--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

entity SectorProcessor is
  port(
    clk        : in std_logic;
    reset      : in std_logic;
    ProjectionRouter_start  : in std_logic;
    bx_in_ProjectionRouter : in std_logic_vector(2 downto 0);
    bx_out_MatchCalculator : out std_logic_vector(2 downto 0);
    bx_out_MatchCalculator_vld : out std_logic;
    MatchCalculator_done   : out std_logic;
    AS_L3PHICn6_dataarray_data_V_wea       : in std_logic;
    AS_L3PHICn6_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    AS_L3PHICn6_dataarray_data_V_din       : in std_logic_vector(35 downto 0);
    VMSME_L3PHIC17n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC17n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC17n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC18n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC18n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC18n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC19n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC19n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC19n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC20n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC20n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC20n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC21n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC21n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC21n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC22n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC22n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC22n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC23n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC23n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC23n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    VMSME_L3PHIC24n1_dataarray_data_V_wea       : in std_logic;
    VMSME_L3PHIC24n1_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    VMSME_L3PHIC24n1_dataarray_data_V_din       : in std_logic_vector(12 downto 0);
    TPROJ_L1L2F_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L1L2F_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L1L2F_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L1L2G_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L1L2G_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L1L2G_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L1L2H_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L1L2H_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L1L2H_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L1L2I_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L1L2I_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L1L2I_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L1L2J_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L1L2J_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L1L2J_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L5L6B_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L5L6B_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L5L6B_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L5L6C_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L5L6C_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L5L6C_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    TPROJ_L5L6D_L3PHIC_dataarray_data_V_wea       : in std_logic;
    TPROJ_L5L6D_L3PHIC_dataarray_data_V_writeaddr : in std_logic_vector(7 downto 0);
    TPROJ_L5L6D_L3PHIC_dataarray_data_V_din       : in std_logic_vector(59 downto 0);
    FM_L1L2_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L1L2_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L1L2_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L1L2_L3PHIC_nentries_0_V_dout : out std_logic_vector(6 downto 0);
    FM_L1L2_L3PHIC_nentries_1_V_dout : out std_logic_vector(6 downto 0);
    FM_L5L6_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L5L6_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L5L6_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L5L6_L3PHIC_nentries_0_V_dout : out std_logic_vector(6 downto 0);
    FM_L5L6_L3PHIC_nentries_1_V_dout : out std_logic_vector(6 downto 0)
);



end SectorProcessor;

architecture rtl of SectorProcessor is

  signal TPROJ_L1L2F_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L1L2F_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L1L2F_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L1L2F_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2F_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2G_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L1L2G_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L1L2G_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L1L2G_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2G_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2H_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L1L2H_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L1L2H_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L1L2H_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2H_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2I_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L1L2I_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L1L2I_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L1L2I_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2I_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2J_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L1L2J_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L1L2J_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L1L2J_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L1L2J_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6B_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L5L6B_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L5L6B_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L5L6B_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6B_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6C_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L5L6C_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L5L6C_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L5L6C_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6C_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6D_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal TPROJ_L5L6D_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal TPROJ_L5L6D_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal TPROJ_L5L6D_L3PHIC_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal TPROJ_L5L6D_L3PHIC_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMSME_L3PHIC17n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC17n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC17n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC17n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC17n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC18n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC18n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC18n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC18n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC19n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC19n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC19n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC19n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC20n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC20n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC20n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC20n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC21n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC21n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC21n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC21n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC22n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC22n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC22n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC22n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC23n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC23n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC23n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC23n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_dataarray_data_V_enb      : std_logic;
  signal VMSME_L3PHIC24n1_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal VMSME_L3PHIC24n1_dataarray_data_V_dout     : std_logic_vector(12 downto 0);
  signal VMSME_L3PHIC24n1_nentries_0_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_1_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_2_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_3_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_4_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_5_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_6_VV_dout : t_arr8_5b; -- (#bin)
  signal VMSME_L3PHIC24n1_nentries_7_VV_dout : t_arr8_5b; -- (#bin)
  signal AS_L3PHICn6_dataarray_data_V_enb      : std_logic;
  signal AS_L3PHICn6_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AS_L3PHICn6_dataarray_data_V_dout     : std_logic_vector(35 downto 0);
  signal VMPROJ_L3PHIC17_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC17_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC17_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC17_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC17_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC17_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC17_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC17_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC18_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC18_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC18_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC18_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC18_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC18_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC18_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC18_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC19_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC19_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC19_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC19_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC19_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC19_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC19_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC19_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC20_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC20_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC20_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC20_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC20_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC20_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC20_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC20_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC21_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC21_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC21_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC21_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC21_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC21_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC21_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC21_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC22_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC22_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC22_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC22_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC22_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC22_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC22_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC22_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC23_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC23_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC23_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC23_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC23_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC23_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC23_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC23_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC24_dataarray_data_V_wea       : std_logic;
  signal VMPROJ_L3PHIC24_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC24_dataarray_data_V_din       : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC24_dataarray_data_V_enb      : std_logic;
  signal VMPROJ_L3PHIC24_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal VMPROJ_L3PHIC24_dataarray_data_V_dout     : std_logic_vector(20 downto 0);
  signal VMPROJ_L3PHIC24_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal VMPROJ_L3PHIC24_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC17_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC17_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC17_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC17_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC17_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC17_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC17_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC17_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC18_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC18_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC18_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC18_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC18_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC18_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC18_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC18_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC19_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC19_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC19_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC19_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC19_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC19_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC19_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC19_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC20_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC20_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC20_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC20_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC20_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC20_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC20_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC20_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC21_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC21_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC21_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC21_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC21_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC21_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC21_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC21_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC22_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC22_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC22_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC22_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC22_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC22_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC22_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC22_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC23_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC23_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC23_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC23_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC23_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC23_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC23_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC23_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC24_dataarray_data_V_wea       : std_logic;
  signal CM_L3PHIC24_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC24_dataarray_data_V_din       : std_logic_vector(13 downto 0);
  signal CM_L3PHIC24_dataarray_data_V_enb      : std_logic;
  signal CM_L3PHIC24_dataarray_data_V_readaddr : std_logic_vector(7 downto 0);
  signal CM_L3PHIC24_dataarray_data_V_dout     : std_logic_vector(13 downto 0);
  signal CM_L3PHIC24_nentries_0_V_dout : std_logic_vector(6 downto 0);
  signal CM_L3PHIC24_nentries_1_V_dout : std_logic_vector(6 downto 0);
  signal AP_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal AP_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_din       : std_logic_vector(59 downto 0);
  signal AP_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal AP_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal FM_L1L2_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L1L2_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L1L2_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);
  signal FM_L5L6_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L5L6_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L5L6_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);
  signal ProjectionRouter_done : std_logic := '0';
  signal MatchEngine_start : std_logic := '0';
  signal bx_out_ProjectionRouter : std_logic_vector(2 downto 0);
  signal bx_out_ProjectionRouter_vld : std_logic;

  signal MatchEngine_done : std_logic := '0';
  signal MatchCalculator_start : std_logic := '0';
  signal bx_out_MatchEngine : std_logic_vector(2 downto 0);
  signal bx_out_MatchEngine_vld : std_logic;










 begin 

  TPROJ_L1L2F_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L1L2F_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L1L2F_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L1L2F_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L1L2F_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L1L2F_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L1L2F_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L1L2F_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L1L2F_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L1L2G_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L1L2G_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L1L2G_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L1L2G_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L1L2G_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L1L2G_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L1L2G_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L1L2G_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L1L2G_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L1L2H_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L1L2H_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L1L2H_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L1L2H_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L1L2H_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L1L2H_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L1L2H_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L1L2H_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L1L2H_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L1L2I_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L1L2I_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L1L2I_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L1L2I_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L1L2I_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L1L2I_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L1L2I_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L1L2I_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L1L2I_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L1L2J_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L1L2J_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L1L2J_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L1L2J_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L1L2J_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L1L2J_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L1L2J_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L1L2J_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L1L2J_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L5L6B_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L5L6B_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L5L6B_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L5L6B_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L5L6B_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L5L6B_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L5L6B_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L5L6B_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L5L6B_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L5L6C_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L5L6C_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L5L6C_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L5L6C_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L5L6C_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L5L6C_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L5L6C_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L5L6C_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L5L6C_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  TPROJ_L5L6D_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => TPROJ_L5L6D_L3PHIC_dataarray_data_V_wea,
      addra     => TPROJ_L5L6D_L3PHIC_dataarray_data_V_writeaddr,
      dina      => TPROJ_L5L6D_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => TPROJ_L5L6D_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => TPROJ_L5L6D_L3PHIC_dataarray_data_V_readaddr,
      doutb     => TPROJ_L5L6D_L3PHIC_dataarray_data_V_dout,
      sync_nent => ProjectionRouter_start,
      nent_o0  => TPROJ_L5L6D_L3PHIC_nentries_0_V_dout,
      nent_o1  => TPROJ_L5L6D_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMSME_L3PHIC17n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC17n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC17n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC17n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC17n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC17n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC17n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC17n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC17n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC17n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC17n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC17n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC17n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC17n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC17n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC18n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC18n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC18n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC18n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC18n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC18n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC18n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC18n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC18n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC18n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC18n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC18n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC18n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC18n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC18n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC19n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC19n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC19n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC19n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC19n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC19n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC19n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC19n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC19n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC19n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC19n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC19n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC19n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC19n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC19n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC20n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC20n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC20n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC20n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC20n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC20n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC20n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC20n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC20n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC20n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC20n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC20n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC20n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC20n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC20n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC21n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC21n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC21n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC21n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC21n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC21n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC21n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC21n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC21n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC21n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC21n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC21n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC21n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC21n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC21n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC22n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC22n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC22n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC22n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC22n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC22n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC22n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC22n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC22n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC22n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC22n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC22n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC22n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC22n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC22n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC23n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC23n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC23n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC23n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC23n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC23n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC23n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC23n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC23n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC23n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC23n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC23n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC23n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC23n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC23n1_nentries_7_VV_dout
  );


  VMSME_L3PHIC24n1 : entity work.tf_mem_bin
    generic map (
      RAM_WIDTH       => 13,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMSME_L3PHIC24n1_dataarray_data_V_wea,
      addra     => VMSME_L3PHIC24n1_dataarray_data_V_writeaddr,
      dina      => VMSME_L3PHIC24n1_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMSME_L3PHIC24n1_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMSME_L3PHIC24n1_dataarray_data_V_readaddr,
      doutb     => VMSME_L3PHIC24n1_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMSME_L3PHIC24n1_nentries_0_VV_dout,
      nent_o1  => VMSME_L3PHIC24n1_nentries_1_VV_dout,
      nent_o2  => VMSME_L3PHIC24n1_nentries_2_VV_dout,
      nent_o3  => VMSME_L3PHIC24n1_nentries_3_VV_dout,
      nent_o4  => VMSME_L3PHIC24n1_nentries_4_VV_dout,
      nent_o5  => VMSME_L3PHIC24n1_nentries_5_VV_dout,
      nent_o6  => VMSME_L3PHIC24n1_nentries_6_VV_dout,
      nent_o7  => VMSME_L3PHIC24n1_nentries_7_VV_dout
  );


  AS_L3PHICn6 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 36,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => AS_L3PHICn6_dataarray_data_V_wea,
      addra     => AS_L3PHICn6_dataarray_data_V_writeaddr,
      dina      => AS_L3PHICn6_dataarray_data_V_din,
      clkb      => clk,
      enb       => AS_L3PHICn6_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => AS_L3PHICn6_dataarray_data_V_readaddr,
      doutb     => AS_L3PHICn6_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => open,
      nent_o1  => open,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC17 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC17_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC17_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC17_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC17_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC17_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC17_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC17_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC17_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC18 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC18_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC18_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC18_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC18_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC18_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC18_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC18_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC18_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC19 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC19_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC19_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC19_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC19_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC19_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC19_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC19_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC19_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC20 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC20_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC20_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC20_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC20_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC20_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC20_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC20_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC20_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC21 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC21_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC21_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC21_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC21_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC21_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC21_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC21_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC21_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC22 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC22_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC22_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC22_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC22_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC22_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC22_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC22_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC22_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC23 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC23_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC23_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC23_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC23_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC23_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC23_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC23_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC23_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  VMPROJ_L3PHIC24 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 21,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => VMPROJ_L3PHIC24_dataarray_data_V_wea,
      addra     => VMPROJ_L3PHIC24_dataarray_data_V_writeaddr,
      dina      => VMPROJ_L3PHIC24_dataarray_data_V_din,
      clkb      => clk,
      enb       => VMPROJ_L3PHIC24_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => VMPROJ_L3PHIC24_dataarray_data_V_readaddr,
      doutb     => VMPROJ_L3PHIC24_dataarray_data_V_dout,
      sync_nent => MatchEngine_start,
      nent_o0  => VMPROJ_L3PHIC24_nentries_0_V_dout,
      nent_o1  => VMPROJ_L3PHIC24_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC17 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC17_dataarray_data_V_wea,
      addra     => CM_L3PHIC17_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC17_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC17_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC17_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC17_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC17_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC17_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC18 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC18_dataarray_data_V_wea,
      addra     => CM_L3PHIC18_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC18_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC18_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC18_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC18_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC18_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC18_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC19 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC19_dataarray_data_V_wea,
      addra     => CM_L3PHIC19_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC19_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC19_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC19_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC19_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC19_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC19_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC20 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC20_dataarray_data_V_wea,
      addra     => CM_L3PHIC20_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC20_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC20_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC20_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC20_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC20_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC20_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC21 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC21_dataarray_data_V_wea,
      addra     => CM_L3PHIC21_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC21_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC21_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC21_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC21_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC21_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC21_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC22 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC22_dataarray_data_V_wea,
      addra     => CM_L3PHIC22_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC22_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC22_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC22_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC22_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC22_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC22_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC23 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC23_dataarray_data_V_wea,
      addra     => CM_L3PHIC23_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC23_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC23_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC23_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC23_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC23_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC23_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  CM_L3PHIC24 : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 14,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => CM_L3PHIC24_dataarray_data_V_wea,
      addra     => CM_L3PHIC24_dataarray_data_V_writeaddr,
      dina      => CM_L3PHIC24_dataarray_data_V_din,
      clkb      => clk,
      enb       => CM_L3PHIC24_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => CM_L3PHIC24_dataarray_data_V_readaddr,
      doutb     => CM_L3PHIC24_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => CM_L3PHIC24_nentries_0_V_dout,
      nent_o1  => CM_L3PHIC24_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  AP_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => AP_L3PHIC_dataarray_data_V_wea,
      addra     => AP_L3PHIC_dataarray_data_V_writeaddr,
      dina      => AP_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => AP_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => AP_L3PHIC_dataarray_data_V_readaddr,
      doutb     => AP_L3PHIC_dataarray_data_V_dout,
      sync_nent => MatchCalculator_start,
      nent_o0  => open,
      nent_o1  => open,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  FM_L1L2_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 45,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => FM_L1L2_L3PHIC_dataarray_data_V_wea,
      addra     => FM_L1L2_L3PHIC_dataarray_data_V_writeaddr,
      dina      => FM_L1L2_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => FM_L1L2_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => FM_L1L2_L3PHIC_dataarray_data_V_readaddr,
      doutb     => FM_L1L2_L3PHIC_dataarray_data_V_dout,
      sync_nent => MatchCalculator_done,
      nent_o0  => FM_L1L2_L3PHIC_nentries_0_V_dout,
      nent_o1  => FM_L1L2_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );


  FM_L5L6_L3PHIC : entity work.tf_mem
    generic map (
      RAM_WIDTH       => 45,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      INIT_HEX        => true,
      RAM_PERFORMANCE => "HIGH_PERFORMANCE"
    )
    port map (
      clka      => clk,
      wea       => FM_L5L6_L3PHIC_dataarray_data_V_wea,
      addra     => FM_L5L6_L3PHIC_dataarray_data_V_writeaddr,
      dina      => FM_L5L6_L3PHIC_dataarray_data_V_din,
      clkb      => clk,
      enb       => FM_L5L6_L3PHIC_dataarray_data_V_enb,
      rstb      => '0',
      regceb    => '1',
      addrb     => FM_L5L6_L3PHIC_dataarray_data_V_readaddr,
      doutb     => FM_L5L6_L3PHIC_dataarray_data_V_dout,
      sync_nent => MatchCalculator_done,
      nent_o0  => FM_L5L6_L3PHIC_nentries_0_V_dout,
      nent_o1  => FM_L5L6_L3PHIC_nentries_1_V_dout,
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
  );

  process(ProjectionRouter_done)
  begin
    if ProjectionRouter_done = '1' then MatchEngine_start <= '1'; end if;
  end process;

  PR_L3PHIC : entity work.PR_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ProjectionRouter_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => ProjectionRouter_done,
      bx_V          => bx_in_ProjectionRouter,
      bx_o_V        => bx_out_ProjectionRouter,
      bx_o_V_ap_vld => bx_out_ProjectionRouter_vld,
      projin_0_dataarray_data_V_ce0         => TPROJ_L1L2F_L3PHIC_dataarray_data_V_enb,
      projin_0_dataarray_data_V_address0    => TPROJ_L1L2F_L3PHIC_dataarray_data_V_readaddr,
      projin_0_dataarray_data_V_q0            => TPROJ_L1L2F_L3PHIC_dataarray_data_V_dout,
      projin_0_nentries_0_V        => TPROJ_L1L2F_L3PHIC_nentries_0_V_dout,
      projin_0_nentries_1_V        => TPROJ_L1L2F_L3PHIC_nentries_1_V_dout,
      projin_1_dataarray_data_V_ce0         => TPROJ_L1L2G_L3PHIC_dataarray_data_V_enb,
      projin_1_dataarray_data_V_address0    => TPROJ_L1L2G_L3PHIC_dataarray_data_V_readaddr,
      projin_1_dataarray_data_V_q0            => TPROJ_L1L2G_L3PHIC_dataarray_data_V_dout,
      projin_1_nentries_0_V        => TPROJ_L1L2G_L3PHIC_nentries_0_V_dout,
      projin_1_nentries_1_V        => TPROJ_L1L2G_L3PHIC_nentries_1_V_dout,
      projin_2_dataarray_data_V_ce0         => TPROJ_L1L2H_L3PHIC_dataarray_data_V_enb,
      projin_2_dataarray_data_V_address0    => TPROJ_L1L2H_L3PHIC_dataarray_data_V_readaddr,
      projin_2_dataarray_data_V_q0            => TPROJ_L1L2H_L3PHIC_dataarray_data_V_dout,
      projin_2_nentries_0_V        => TPROJ_L1L2H_L3PHIC_nentries_0_V_dout,
      projin_2_nentries_1_V        => TPROJ_L1L2H_L3PHIC_nentries_1_V_dout,
      projin_3_dataarray_data_V_ce0         => TPROJ_L1L2I_L3PHIC_dataarray_data_V_enb,
      projin_3_dataarray_data_V_address0    => TPROJ_L1L2I_L3PHIC_dataarray_data_V_readaddr,
      projin_3_dataarray_data_V_q0            => TPROJ_L1L2I_L3PHIC_dataarray_data_V_dout,
      projin_3_nentries_0_V        => TPROJ_L1L2I_L3PHIC_nentries_0_V_dout,
      projin_3_nentries_1_V        => TPROJ_L1L2I_L3PHIC_nentries_1_V_dout,
      projin_4_dataarray_data_V_ce0         => TPROJ_L1L2J_L3PHIC_dataarray_data_V_enb,
      projin_4_dataarray_data_V_address0    => TPROJ_L1L2J_L3PHIC_dataarray_data_V_readaddr,
      projin_4_dataarray_data_V_q0            => TPROJ_L1L2J_L3PHIC_dataarray_data_V_dout,
      projin_4_nentries_0_V        => TPROJ_L1L2J_L3PHIC_nentries_0_V_dout,
      projin_4_nentries_1_V        => TPROJ_L1L2J_L3PHIC_nentries_1_V_dout,
      projin_5_dataarray_data_V_ce0         => TPROJ_L5L6B_L3PHIC_dataarray_data_V_enb,
      projin_5_dataarray_data_V_address0    => TPROJ_L5L6B_L3PHIC_dataarray_data_V_readaddr,
      projin_5_dataarray_data_V_q0            => TPROJ_L5L6B_L3PHIC_dataarray_data_V_dout,
      projin_5_nentries_0_V        => TPROJ_L5L6B_L3PHIC_nentries_0_V_dout,
      projin_5_nentries_1_V        => TPROJ_L5L6B_L3PHIC_nentries_1_V_dout,
      projin_6_dataarray_data_V_ce0         => TPROJ_L5L6C_L3PHIC_dataarray_data_V_enb,
      projin_6_dataarray_data_V_address0    => TPROJ_L5L6C_L3PHIC_dataarray_data_V_readaddr,
      projin_6_dataarray_data_V_q0            => TPROJ_L5L6C_L3PHIC_dataarray_data_V_dout,
      projin_6_nentries_0_V        => TPROJ_L5L6C_L3PHIC_nentries_0_V_dout,
      projin_6_nentries_1_V        => TPROJ_L5L6C_L3PHIC_nentries_1_V_dout,
      projin_7_dataarray_data_V_ce0         => TPROJ_L5L6D_L3PHIC_dataarray_data_V_enb,
      projin_7_dataarray_data_V_address0    => TPROJ_L5L6D_L3PHIC_dataarray_data_V_readaddr,
      projin_7_dataarray_data_V_q0            => TPROJ_L5L6D_L3PHIC_dataarray_data_V_dout,
      projin_7_nentries_0_V        => TPROJ_L5L6D_L3PHIC_nentries_0_V_dout,
      projin_7_nentries_1_V        => TPROJ_L5L6D_L3PHIC_nentries_1_V_dout,
      allprojout_dataarray_data_V_ce0         => open,
      allprojout_dataarray_data_V_we0         => AP_L3PHIC_dataarray_data_V_wea,
      allprojout_dataarray_data_V_address0    => AP_L3PHIC_dataarray_data_V_writeaddr,
      allprojout_dataarray_data_V_d0          => AP_L3PHIC_dataarray_data_V_din,
      vmprojout_0_dataarray_data_V_ce0         => open,
      vmprojout_0_dataarray_data_V_we0         => VMPROJ_L3PHIC17_dataarray_data_V_wea,
      vmprojout_0_dataarray_data_V_address0    => VMPROJ_L3PHIC17_dataarray_data_V_writeaddr,
      vmprojout_0_dataarray_data_V_d0          => VMPROJ_L3PHIC17_dataarray_data_V_din,
      vmprojout_1_dataarray_data_V_ce0         => open,
      vmprojout_1_dataarray_data_V_we0         => VMPROJ_L3PHIC18_dataarray_data_V_wea,
      vmprojout_1_dataarray_data_V_address0    => VMPROJ_L3PHIC18_dataarray_data_V_writeaddr,
      vmprojout_1_dataarray_data_V_d0          => VMPROJ_L3PHIC18_dataarray_data_V_din,
      vmprojout_2_dataarray_data_V_ce0         => open,
      vmprojout_2_dataarray_data_V_we0         => VMPROJ_L3PHIC19_dataarray_data_V_wea,
      vmprojout_2_dataarray_data_V_address0    => VMPROJ_L3PHIC19_dataarray_data_V_writeaddr,
      vmprojout_2_dataarray_data_V_d0          => VMPROJ_L3PHIC19_dataarray_data_V_din,
      vmprojout_3_dataarray_data_V_ce0         => open,
      vmprojout_3_dataarray_data_V_we0         => VMPROJ_L3PHIC20_dataarray_data_V_wea,
      vmprojout_3_dataarray_data_V_address0    => VMPROJ_L3PHIC20_dataarray_data_V_writeaddr,
      vmprojout_3_dataarray_data_V_d0          => VMPROJ_L3PHIC20_dataarray_data_V_din,
      vmprojout_4_dataarray_data_V_ce0         => open,
      vmprojout_4_dataarray_data_V_we0         => VMPROJ_L3PHIC21_dataarray_data_V_wea,
      vmprojout_4_dataarray_data_V_address0    => VMPROJ_L3PHIC21_dataarray_data_V_writeaddr,
      vmprojout_4_dataarray_data_V_d0          => VMPROJ_L3PHIC21_dataarray_data_V_din,
      vmprojout_5_dataarray_data_V_ce0         => open,
      vmprojout_5_dataarray_data_V_we0         => VMPROJ_L3PHIC22_dataarray_data_V_wea,
      vmprojout_5_dataarray_data_V_address0    => VMPROJ_L3PHIC22_dataarray_data_V_writeaddr,
      vmprojout_5_dataarray_data_V_d0          => VMPROJ_L3PHIC22_dataarray_data_V_din,
      vmprojout_6_dataarray_data_V_ce0         => open,
      vmprojout_6_dataarray_data_V_we0         => VMPROJ_L3PHIC23_dataarray_data_V_wea,
      vmprojout_6_dataarray_data_V_address0    => VMPROJ_L3PHIC23_dataarray_data_V_writeaddr,
      vmprojout_6_dataarray_data_V_d0          => VMPROJ_L3PHIC23_dataarray_data_V_din,
      vmprojout_7_dataarray_data_V_ce0         => open,
      vmprojout_7_dataarray_data_V_we0         => VMPROJ_L3PHIC24_dataarray_data_V_wea,
      vmprojout_7_dataarray_data_V_address0    => VMPROJ_L3PHIC24_dataarray_data_V_writeaddr,
      vmprojout_7_dataarray_data_V_d0          => VMPROJ_L3PHIC24_dataarray_data_V_din
  );


  process(MatchEngine_done)
  begin
    if MatchEngine_done = '1' then MatchCalculator_start <= '1'; end if;
  end process;

  ME_L3PHIC17 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MatchEngine_done,
      bx_V          => bx_out_ProjectionRouter,
      bx_o_V        => bx_out_MatchEngine,
      bx_o_V_ap_vld => bx_out_MatchEngine_vld,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC17n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC17n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC17n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC17n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC17n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC17n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC17n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC17n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC17n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC17n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC17n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC17n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC17n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC17n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC17n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC17n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC17n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC17n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC17n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC17n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC17n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC17n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC17n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC17n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC17n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC17n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC17n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC17n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC17n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC17n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC17n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC17n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC17n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC17n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC17n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC17n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC17n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC17n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC17n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC17n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC17n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC17n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC17n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC17n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC17n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC17n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC17n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC17n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC17n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC17n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC17n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC17n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC17n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC17n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC17n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC17n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC17n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC17n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC17n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC17n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC17n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC17n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC17n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC17n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC17n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC17n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC17n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC17_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC17_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC17_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC17_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC17_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC17_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC17_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC17_dataarray_data_V_din
  );


  ME_L3PHIC18 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC18n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC18n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC18n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC18n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC18n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC18n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC18n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC18n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC18n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC18n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC18n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC18n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC18n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC18n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC18n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC18n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC18n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC18n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC18n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC18n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC18n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC18n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC18n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC18n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC18n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC18n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC18n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC18n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC18n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC18n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC18n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC18n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC18n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC18n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC18n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC18n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC18n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC18n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC18n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC18n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC18n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC18n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC18n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC18n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC18n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC18n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC18n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC18n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC18n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC18n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC18n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC18n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC18n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC18n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC18n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC18n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC18n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC18n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC18n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC18n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC18n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC18n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC18n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC18n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC18n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC18n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC18n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC18_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC18_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC18_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC18_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC18_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC18_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC18_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC18_dataarray_data_V_din
  );


  ME_L3PHIC19 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC19n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC19n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC19n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC19n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC19n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC19n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC19n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC19n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC19n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC19n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC19n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC19n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC19n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC19n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC19n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC19n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC19n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC19n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC19n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC19n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC19n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC19n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC19n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC19n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC19n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC19n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC19n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC19n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC19n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC19n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC19n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC19n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC19n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC19n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC19n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC19n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC19n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC19n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC19n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC19n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC19n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC19n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC19n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC19n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC19n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC19n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC19n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC19n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC19n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC19n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC19n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC19n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC19n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC19n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC19n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC19n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC19n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC19n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC19n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC19n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC19n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC19n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC19n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC19n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC19n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC19n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC19n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC19_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC19_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC19_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC19_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC19_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC19_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC19_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC19_dataarray_data_V_din
  );


  ME_L3PHIC20 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC20n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC20n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC20n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC20n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC20n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC20n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC20n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC20n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC20n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC20n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC20n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC20n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC20n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC20n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC20n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC20n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC20n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC20n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC20n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC20n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC20n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC20n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC20n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC20n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC20n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC20n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC20n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC20n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC20n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC20n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC20n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC20n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC20n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC20n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC20n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC20n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC20n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC20n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC20n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC20n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC20n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC20n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC20n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC20n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC20n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC20n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC20n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC20n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC20n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC20n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC20n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC20n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC20n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC20n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC20n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC20n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC20n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC20n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC20n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC20n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC20n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC20n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC20n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC20n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC20n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC20n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC20n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC20_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC20_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC20_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC20_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC20_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC20_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC20_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC20_dataarray_data_V_din
  );


  ME_L3PHIC21 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC21n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC21n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC21n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC21n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC21n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC21n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC21n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC21n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC21n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC21n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC21n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC21n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC21n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC21n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC21n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC21n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC21n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC21n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC21n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC21n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC21n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC21n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC21n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC21n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC21n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC21n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC21n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC21n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC21n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC21n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC21n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC21n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC21n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC21n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC21n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC21n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC21n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC21n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC21n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC21n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC21n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC21n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC21n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC21n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC21n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC21n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC21n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC21n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC21n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC21n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC21n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC21n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC21n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC21n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC21n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC21n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC21n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC21n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC21n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC21n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC21n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC21n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC21n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC21n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC21n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC21n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC21n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC21_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC21_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC21_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC21_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC21_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC21_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC21_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC21_dataarray_data_V_din
  );


  ME_L3PHIC22 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC22n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC22n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC22n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC22n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC22n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC22n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC22n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC22n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC22n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC22n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC22n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC22n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC22n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC22n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC22n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC22n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC22n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC22n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC22n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC22n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC22n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC22n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC22n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC22n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC22n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC22n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC22n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC22n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC22n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC22n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC22n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC22n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC22n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC22n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC22n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC22n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC22n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC22n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC22n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC22n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC22n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC22n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC22n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC22n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC22n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC22n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC22n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC22n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC22n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC22n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC22n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC22n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC22n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC22n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC22n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC22n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC22n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC22n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC22n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC22n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC22n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC22n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC22n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC22n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC22n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC22n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC22n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC22_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC22_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC22_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC22_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC22_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC22_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC22_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC22_dataarray_data_V_din
  );


  ME_L3PHIC23 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC23n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC23n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC23n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC23n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC23n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC23n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC23n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC23n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC23n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC23n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC23n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC23n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC23n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC23n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC23n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC23n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC23n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC23n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC23n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC23n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC23n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC23n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC23n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC23n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC23n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC23n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC23n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC23n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC23n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC23n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC23n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC23n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC23n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC23n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC23n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC23n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC23n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC23n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC23n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC23n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC23n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC23n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC23n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC23n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC23n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC23n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC23n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC23n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC23n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC23n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC23n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC23n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC23n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC23n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC23n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC23n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC23n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC23n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC23n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC23n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC23n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC23n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC23n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC23n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC23n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC23n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC23n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC23_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC23_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC23_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC23_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC23_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC23_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC23_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC23_dataarray_data_V_din
  );


  ME_L3PHIC24 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchEngine_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => bx_out_ProjectionRouter,
      inputStubData_dataarray_data_V_ce0         => VMSME_L3PHIC24n1_dataarray_data_V_enb,
      inputStubData_dataarray_data_V_address0    => VMSME_L3PHIC24n1_dataarray_data_V_readaddr,
      inputStubData_dataarray_data_V_q0            => VMSME_L3PHIC24n1_dataarray_data_V_dout,
      inputStubData_nentries_0_V_0        => VMSME_L3PHIC24n1_nentries_0_VV_dout(0),
      inputStubData_nentries_0_V_1        => VMSME_L3PHIC24n1_nentries_0_VV_dout(1),
      inputStubData_nentries_0_V_2        => VMSME_L3PHIC24n1_nentries_0_VV_dout(2),
      inputStubData_nentries_0_V_3        => VMSME_L3PHIC24n1_nentries_0_VV_dout(3),
      inputStubData_nentries_0_V_4        => VMSME_L3PHIC24n1_nentries_0_VV_dout(4),
      inputStubData_nentries_0_V_5        => VMSME_L3PHIC24n1_nentries_0_VV_dout(5),
      inputStubData_nentries_0_V_6        => VMSME_L3PHIC24n1_nentries_0_VV_dout(6),
      inputStubData_nentries_0_V_7        => VMSME_L3PHIC24n1_nentries_0_VV_dout(7),
      inputStubData_nentries_1_V_0        => VMSME_L3PHIC24n1_nentries_1_VV_dout(0),
      inputStubData_nentries_1_V_1        => VMSME_L3PHIC24n1_nentries_1_VV_dout(1),
      inputStubData_nentries_1_V_2        => VMSME_L3PHIC24n1_nentries_1_VV_dout(2),
      inputStubData_nentries_1_V_3        => VMSME_L3PHIC24n1_nentries_1_VV_dout(3),
      inputStubData_nentries_1_V_4        => VMSME_L3PHIC24n1_nentries_1_VV_dout(4),
      inputStubData_nentries_1_V_5        => VMSME_L3PHIC24n1_nentries_1_VV_dout(5),
      inputStubData_nentries_1_V_6        => VMSME_L3PHIC24n1_nentries_1_VV_dout(6),
      inputStubData_nentries_1_V_7        => VMSME_L3PHIC24n1_nentries_1_VV_dout(7),
      inputStubData_nentries_2_V_0        => VMSME_L3PHIC24n1_nentries_2_VV_dout(0),
      inputStubData_nentries_2_V_1        => VMSME_L3PHIC24n1_nentries_2_VV_dout(1),
      inputStubData_nentries_2_V_2        => VMSME_L3PHIC24n1_nentries_2_VV_dout(2),
      inputStubData_nentries_2_V_3        => VMSME_L3PHIC24n1_nentries_2_VV_dout(3),
      inputStubData_nentries_2_V_4        => VMSME_L3PHIC24n1_nentries_2_VV_dout(4),
      inputStubData_nentries_2_V_5        => VMSME_L3PHIC24n1_nentries_2_VV_dout(5),
      inputStubData_nentries_2_V_6        => VMSME_L3PHIC24n1_nentries_2_VV_dout(6),
      inputStubData_nentries_2_V_7        => VMSME_L3PHIC24n1_nentries_2_VV_dout(7),
      inputStubData_nentries_3_V_0        => VMSME_L3PHIC24n1_nentries_3_VV_dout(0),
      inputStubData_nentries_3_V_1        => VMSME_L3PHIC24n1_nentries_3_VV_dout(1),
      inputStubData_nentries_3_V_2        => VMSME_L3PHIC24n1_nentries_3_VV_dout(2),
      inputStubData_nentries_3_V_3        => VMSME_L3PHIC24n1_nentries_3_VV_dout(3),
      inputStubData_nentries_3_V_4        => VMSME_L3PHIC24n1_nentries_3_VV_dout(4),
      inputStubData_nentries_3_V_5        => VMSME_L3PHIC24n1_nentries_3_VV_dout(5),
      inputStubData_nentries_3_V_6        => VMSME_L3PHIC24n1_nentries_3_VV_dout(6),
      inputStubData_nentries_3_V_7        => VMSME_L3PHIC24n1_nentries_3_VV_dout(7),
      inputStubData_nentries_4_V_0        => VMSME_L3PHIC24n1_nentries_4_VV_dout(0),
      inputStubData_nentries_4_V_1        => VMSME_L3PHIC24n1_nentries_4_VV_dout(1),
      inputStubData_nentries_4_V_2        => VMSME_L3PHIC24n1_nentries_4_VV_dout(2),
      inputStubData_nentries_4_V_3        => VMSME_L3PHIC24n1_nentries_4_VV_dout(3),
      inputStubData_nentries_4_V_4        => VMSME_L3PHIC24n1_nentries_4_VV_dout(4),
      inputStubData_nentries_4_V_5        => VMSME_L3PHIC24n1_nentries_4_VV_dout(5),
      inputStubData_nentries_4_V_6        => VMSME_L3PHIC24n1_nentries_4_VV_dout(6),
      inputStubData_nentries_4_V_7        => VMSME_L3PHIC24n1_nentries_4_VV_dout(7),
      inputStubData_nentries_5_V_0        => VMSME_L3PHIC24n1_nentries_5_VV_dout(0),
      inputStubData_nentries_5_V_1        => VMSME_L3PHIC24n1_nentries_5_VV_dout(1),
      inputStubData_nentries_5_V_2        => VMSME_L3PHIC24n1_nentries_5_VV_dout(2),
      inputStubData_nentries_5_V_3        => VMSME_L3PHIC24n1_nentries_5_VV_dout(3),
      inputStubData_nentries_5_V_4        => VMSME_L3PHIC24n1_nentries_5_VV_dout(4),
      inputStubData_nentries_5_V_5        => VMSME_L3PHIC24n1_nentries_5_VV_dout(5),
      inputStubData_nentries_5_V_6        => VMSME_L3PHIC24n1_nentries_5_VV_dout(6),
      inputStubData_nentries_5_V_7        => VMSME_L3PHIC24n1_nentries_5_VV_dout(7),
      inputStubData_nentries_6_V_0        => VMSME_L3PHIC24n1_nentries_6_VV_dout(0),
      inputStubData_nentries_6_V_1        => VMSME_L3PHIC24n1_nentries_6_VV_dout(1),
      inputStubData_nentries_6_V_2        => VMSME_L3PHIC24n1_nentries_6_VV_dout(2),
      inputStubData_nentries_6_V_3        => VMSME_L3PHIC24n1_nentries_6_VV_dout(3),
      inputStubData_nentries_6_V_4        => VMSME_L3PHIC24n1_nentries_6_VV_dout(4),
      inputStubData_nentries_6_V_5        => VMSME_L3PHIC24n1_nentries_6_VV_dout(5),
      inputStubData_nentries_6_V_6        => VMSME_L3PHIC24n1_nentries_6_VV_dout(6),
      inputStubData_nentries_6_V_7        => VMSME_L3PHIC24n1_nentries_6_VV_dout(7),
      inputStubData_nentries_7_V_0        => VMSME_L3PHIC24n1_nentries_7_VV_dout(0),
      inputStubData_nentries_7_V_1        => VMSME_L3PHIC24n1_nentries_7_VV_dout(1),
      inputStubData_nentries_7_V_2        => VMSME_L3PHIC24n1_nentries_7_VV_dout(2),
      inputStubData_nentries_7_V_3        => VMSME_L3PHIC24n1_nentries_7_VV_dout(3),
      inputStubData_nentries_7_V_4        => VMSME_L3PHIC24n1_nentries_7_VV_dout(4),
      inputStubData_nentries_7_V_5        => VMSME_L3PHIC24n1_nentries_7_VV_dout(5),
      inputStubData_nentries_7_V_6        => VMSME_L3PHIC24n1_nentries_7_VV_dout(6),
      inputStubData_nentries_7_V_7        => VMSME_L3PHIC24n1_nentries_7_VV_dout(7),
      inputProjectionData_dataarray_data_V_ce0         => VMPROJ_L3PHIC24_dataarray_data_V_enb,
      inputProjectionData_dataarray_data_V_address0    => VMPROJ_L3PHIC24_dataarray_data_V_readaddr,
      inputProjectionData_dataarray_data_V_q0            => VMPROJ_L3PHIC24_dataarray_data_V_dout,
      inputProjectionData_nentries_0_V        => VMPROJ_L3PHIC24_nentries_0_V_dout,
      inputProjectionData_nentries_1_V        => VMPROJ_L3PHIC24_nentries_1_V_dout,
      outputCandidateMatch_dataarray_data_V_ce0         => open,
      outputCandidateMatch_dataarray_data_V_we0         => CM_L3PHIC24_dataarray_data_V_wea,
      outputCandidateMatch_dataarray_data_V_address0    => CM_L3PHIC24_dataarray_data_V_writeaddr,
      outputCandidateMatch_dataarray_data_V_d0          => CM_L3PHIC24_dataarray_data_V_din
  );


  MC_L3PHIC : entity work.MC_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MatchCalculator_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MatchCalculator_done,
      bx_V          => bx_out_MatchEngine,
      bx_o_V        => bx_out_MatchCalculator,
      bx_o_V_ap_vld => bx_out_MatchCalculator_vld,
      match_0_dataarray_data_V_ce0         => CM_L3PHIC17_dataarray_data_V_enb,
      match_0_dataarray_data_V_address0    => CM_L3PHIC17_dataarray_data_V_readaddr,
      match_0_dataarray_data_V_q0            => CM_L3PHIC17_dataarray_data_V_dout,
      match_0_nentries_0_V        => CM_L3PHIC17_nentries_0_V_dout,
      match_0_nentries_1_V        => CM_L3PHIC17_nentries_1_V_dout,
      match_1_dataarray_data_V_ce0         => CM_L3PHIC18_dataarray_data_V_enb,
      match_1_dataarray_data_V_address0    => CM_L3PHIC18_dataarray_data_V_readaddr,
      match_1_dataarray_data_V_q0            => CM_L3PHIC18_dataarray_data_V_dout,
      match_1_nentries_0_V        => CM_L3PHIC18_nentries_0_V_dout,
      match_1_nentries_1_V        => CM_L3PHIC18_nentries_1_V_dout,
      match_2_dataarray_data_V_ce0         => CM_L3PHIC19_dataarray_data_V_enb,
      match_2_dataarray_data_V_address0    => CM_L3PHIC19_dataarray_data_V_readaddr,
      match_2_dataarray_data_V_q0            => CM_L3PHIC19_dataarray_data_V_dout,
      match_2_nentries_0_V        => CM_L3PHIC19_nentries_0_V_dout,
      match_2_nentries_1_V        => CM_L3PHIC19_nentries_1_V_dout,
      match_3_dataarray_data_V_ce0         => CM_L3PHIC20_dataarray_data_V_enb,
      match_3_dataarray_data_V_address0    => CM_L3PHIC20_dataarray_data_V_readaddr,
      match_3_dataarray_data_V_q0            => CM_L3PHIC20_dataarray_data_V_dout,
      match_3_nentries_0_V        => CM_L3PHIC20_nentries_0_V_dout,
      match_3_nentries_1_V        => CM_L3PHIC20_nentries_1_V_dout,
      match_4_dataarray_data_V_ce0         => CM_L3PHIC21_dataarray_data_V_enb,
      match_4_dataarray_data_V_address0    => CM_L3PHIC21_dataarray_data_V_readaddr,
      match_4_dataarray_data_V_q0            => CM_L3PHIC21_dataarray_data_V_dout,
      match_4_nentries_0_V        => CM_L3PHIC21_nentries_0_V_dout,
      match_4_nentries_1_V        => CM_L3PHIC21_nentries_1_V_dout,
      match_5_dataarray_data_V_ce0         => CM_L3PHIC22_dataarray_data_V_enb,
      match_5_dataarray_data_V_address0    => CM_L3PHIC22_dataarray_data_V_readaddr,
      match_5_dataarray_data_V_q0            => CM_L3PHIC22_dataarray_data_V_dout,
      match_5_nentries_0_V        => CM_L3PHIC22_nentries_0_V_dout,
      match_5_nentries_1_V        => CM_L3PHIC22_nentries_1_V_dout,
      match_6_dataarray_data_V_ce0         => CM_L3PHIC23_dataarray_data_V_enb,
      match_6_dataarray_data_V_address0    => CM_L3PHIC23_dataarray_data_V_readaddr,
      match_6_dataarray_data_V_q0            => CM_L3PHIC23_dataarray_data_V_dout,
      match_6_nentries_0_V        => CM_L3PHIC23_nentries_0_V_dout,
      match_6_nentries_1_V        => CM_L3PHIC23_nentries_1_V_dout,
      match_7_dataarray_data_V_ce0         => CM_L3PHIC24_dataarray_data_V_enb,
      match_7_dataarray_data_V_address0    => CM_L3PHIC24_dataarray_data_V_readaddr,
      match_7_dataarray_data_V_q0            => CM_L3PHIC24_dataarray_data_V_dout,
      match_7_nentries_0_V        => CM_L3PHIC24_nentries_0_V_dout,
      match_7_nentries_1_V        => CM_L3PHIC24_nentries_1_V_dout,
      allstub_dataarray_data_V_ce0         => AS_L3PHICn6_dataarray_data_V_enb,
      allstub_dataarray_data_V_address0    => AS_L3PHICn6_dataarray_data_V_readaddr,
      allstub_dataarray_data_V_q0            => AS_L3PHICn6_dataarray_data_V_dout,
      allproj_dataarray_data_V_ce0         => AP_L3PHIC_dataarray_data_V_enb,
      allproj_dataarray_data_V_address0    => AP_L3PHIC_dataarray_data_V_readaddr,
      allproj_dataarray_data_V_q0            => AP_L3PHIC_dataarray_data_V_dout,
      fullmatch_0_dataarray_data_V_ce0         => open,
      fullmatch_0_dataarray_data_V_we0         => FM_L1L2_L3PHIC_dataarray_data_V_wea,
      fullmatch_0_dataarray_data_V_address0    => FM_L1L2_L3PHIC_dataarray_data_V_writeaddr,
      fullmatch_0_dataarray_data_V_d0          => FM_L1L2_L3PHIC_dataarray_data_V_din,
      fullmatch_3_dataarray_data_V_ce0         => open,
      fullmatch_3_dataarray_data_V_we0         => FM_L5L6_L3PHIC_dataarray_data_V_wea,
      fullmatch_3_dataarray_data_V_address0    => FM_L5L6_L3PHIC_dataarray_data_V_writeaddr,
      fullmatch_3_dataarray_data_V_d0          => FM_L5L6_L3PHIC_dataarray_data_V_din
  );




end rtl;