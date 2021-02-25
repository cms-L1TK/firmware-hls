--===========================================================================
--! @file
--! @brief Top file for track finding configuration.
--! @author robert.glein@colorado.edu
--! @date 2020-06-01
--! @version v.1.0
--===========================================================================

--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;
--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.tf_pkg.all;


entity tf_top is
  port(
    clk       : in std_logic;
    reset     : in std_logic;
    PR_start  : in std_logic;
    PR_idle   : out std_logic;
    PR_ready  : out std_logic;
    PR_bx_in  : in std_logic_vector(2 downto 0);
    -- TrackletProjections input
    TPROJ_L3PHIC_dataarray_data_V_wea       : in t_arr8_1b;
    TPROJ_L3PHIC_dataarray_data_V_writeaddr : in t_arr8_8b;
    TPROJ_L3PHIC_dataarray_data_V_din       : in t_arr8_60b;
    -- VMStubsME input
    VMSME_L3PHIC17to24n1_dataarray_data_V_wea       : in t_arr8_1b;
    VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr : in t_arr8_10b;
    VMSME_L3PHIC17to24n1_dataarray_data_V_din       : in t_arr8_13b;
    -- AllStubs input
    AS_L3PHICn4_dataarray_data_V_wea       : in std_logic;
    AS_L3PHICn4_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    AS_L3PHICn4_dataarray_data_V_din       : in std_logic_vector(35 downto 0);
    -- FullMatches output
    FM_L1L2_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L1L2_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L1L2_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L1L2_L3PHIC_nentries_V_dout : out t_arr2_7b;
    FM_L5L6_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L5L6_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L5L6_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L5L6_L3PHIC_nentries_V_dout : out t_arr2_7b;
    -- MatchCalculator output
    MC_bx_out     : out std_logic_vector(2 downto 0);
    MC_bx_out_vld : out std_logic;
    MC_done       : out std_logic
    );

end tf_top;

architecture rtl of tf_top is


  -- connecting TrackletProjections memories to ProjectionRouter input
  -- (0-7) -> (L1L2F-L1L2J, L5L6B-L5L6D)
  signal TPROJ_L3PHIC_dataarray_data_V_enb      : t_arr8_1b;
  signal TPROJ_L3PHIC_dataarray_data_V_readaddr : t_arr8_8b;
  signal TPROJ_L3PHIC_dataarray_data_V_dout     : t_arr8_60b;
  signal TPROJ_L3PHIC_nentries_V_dout : t_arr8_2_7b;

  -- ProjectionRouter signals
  signal PR_done       : std_logic := '0';
  signal PR_bx_out     : std_logic_vector(2 downto 0);
  signal PR_bx_out_vld : std_logic;

  -- connecting ProjectionRouter output to AllProjection memories
  signal AP_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal AP_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_din       : std_logic_vector(59 downto 0);

  -- connecting ProjectionRouter output to VMProjection memories
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_wea       : t_arr8_1b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr : t_arr8_8b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_din       : t_arr8_21b;

  -- connecting VMProjections memories to MatchEngine input
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_enb      : t_arr8_1b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr : t_arr8_8b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_dout     : t_arr8_21b;
  signal VMPROJ_L3PHIC17to24_nentries_V_dout : t_arr8_2_7b;

  -- connecting VMStubME memories to MatchEngine input
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_enb      : t_arr8_1b;
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr : t_arr8_10b;
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_dout     : t_arr8_13b;
  signal VMSME_L3PHIC17to24n1_nentries_V_dout           : t_arr8_8_8_5b := (others => (others => (others => (others => '0')))); -- (#mem, #page, #bin); set MSbit to zero

  -- Note: entity work.tf_mem_bin class allocates 4-bits for nentries in each bin, while
  -- MatchEngine ports are expecting 5-bits. Leaving the 5th bit unconnected seems
  -- to cause Vivado to trim away logic and messes up some LUT logic in the ME
  -- module. Assign 'dont_touch' attribute to the nentries signal to prevent this.
  attribute dont_touch : string;
  attribute dont_touch of VMSME_L3PHIC17to24n1_nentries_V_dout : signal is "true";

  -- MatchEngine signals
  signal ME_start : std_logic := '0';
  signal ME_done  : t_arr8_1b := (others => '0');
  signal ME_idle  : std_logic := '0';
  signal ME_ready : std_logic := '0';
  signal ME_bx_out     : t_arr8_3b;
  signal ME_bx_out_vld : t_arr8_1b;
  signal ME_all_done   : std_logic := '0';

  -- connecting MatchEngine output to CandidateMatches memories 
  signal CM_L3PHIC17to24_dataarray_data_V_wea       : t_arr8_1b;
  signal CM_L3PHIC17to24_dataarray_data_V_writeaddr : t_arr8_8b;
  signal CM_L3PHIC17to24_dataarray_data_V_din       : t_arr8_14b;

  -- connecting AllStubs memory to MatchCalculator input
  signal AS_L3PHICn4_dataarray_data_V_enb      : std_logic;
  signal AS_L3PHICn4_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AS_L3PHICn4_dataarray_data_V_dout     : std_logic_vector(35 downto 0);
  signal AS_L3PHICn4_nentries_V_dout : t_arr8_7b;

  -- connecting AllProjections memory to MatchCalculator input
  signal AP_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal AP_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal AP_L3PHIC_nentries_V_dout : t_arr8_7b;

  -- connecting CandidateMatches memories to MatchCalculator input
  signal CM_L3PHIC17to24_dataarray_data_V_enb      : t_arr8_1b;
  signal CM_L3PHIC17to24_dataarray_data_V_readaddr : t_arr8_8b;
  signal CM_L3PHIC17to24_dataarray_data_V_dout     : t_arr8_14b;
  signal CM_L3PHIC17to24_nentries_V_dout : t_arr8_2_7b;

  -- MatchCalculator signals
  signal MC_start : std_logic := '0';
  signal MC_idle  : std_logic := '0';
  signal MC_ready : std_logic := '0';

  -- connecting MatchCalculator output to FullMatches memories
  signal FM_L1L2_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L1L2_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L1L2_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);
  signal FM_L5L6_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L5L6_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L5L6_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);

begin

  ----------------------------------------------------------------
  ---- Signaling section
  ----------------------------------------------------------------
  --p_ME_start : process(clk)
  --begin
  --  if rising_edge(clk) then
  --    if PR_done = '1' then
  --      if (ME_ready='1' or ME_idle='1') then
  --        ME_start <= '1';
  --      else
  --        ME_start <= '0';
  --      end if;
  --    else
  --      ME_start <= '0';
  --    end if;
  --  end if;
  --end process;

  --ME_all_done <= ME_done(0) and ME_done(1) and ME_done(2) and ME_done(3) and ME_done(4) and ME_done(5) and ME_done(6) and ME_done(7);

  --p_MC_start : process(clk)
  --begin
  --  if rising_edge(clk) then
  --    if ME_all_done = '1' then
  --      if (MC_ready='1' or MC_idle='1') then
  --        MC_start <= '1';
  --      else
  --        MC_start <= '0';
  --      end if;
  --    else
  --      MC_start <= '0';
  --    end if;
  --  end if;
  --end process;

  ----------------------------------------------------------------
  ---- TrackletProjection memories
  ----------------------------------------------------------------
  --gen_TPROJ_L3PHIC : for tpidx in 7 downto 0 generate
  --begin
  --  TPROJ_L3PHIC : entity work.tf_mem
  --    generic map (
  --      RAM_WIDTH       => 60,
  --      RAM_DEPTH       => 256,
  --      INIT_FILE       => "",
  --      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --      HEX             => 1
  --      )
  --    port map (
  --      clka     => clk,
  --      wea      => TPROJ_L3PHIC_dataarray_data_V_wea(tpidx),
  --      addra    => TPROJ_L3PHIC_dataarray_data_V_writeaddr(tpidx),
  --      dina     => TPROJ_L3PHIC_dataarray_data_V_din(tpidx),
  --      clkb     => clk,
  --      rstb     => '0',
  --      regceb   => '1',
  --      enb      => TPROJ_L3PHIC_dataarray_data_V_enb(tpidx),
  --      addrb    => TPROJ_L3PHIC_dataarray_data_V_readaddr(tpidx),
  --      doutb    => TPROJ_L3PHIC_dataarray_data_V_dout(tpidx),
  --      nent_o0  => TPROJ_L3PHIC_nentries_V_dout(0)(tpidx),
  --      nent_o1  => TPROJ_L3PHIC_nentries_V_dout(1)(tpidx),
  --      nent_o2  => open,
  --      nent_o3  => open,
  --      nent_o4  => open,
  --      nent_o5  => open,
  --      nent_o6  => open,
  --      nent_o7  => open
  --      );

  --end generate gen_TPROJ_L3PHIC;


  ----------------------------------------------------------------
  ---- ProjectionRouter
  ----------------------------------------------------------------
  --PR_L3PHIC : entity work.PR_L3PHIC
  --  port map (
  --    ap_clk   => clk,
  --    ap_rst   => reset,
  --    ap_start => PR_start,
  --    ap_done  => PR_done,
  --    ap_idle  => PR_idle,
  --    ap_ready => PR_ready,
  --    bx_V     => PR_bx_in,
  --    projin_0_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(0),
  --    projin_0_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(0),
  --    projin_0_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(0),
  --    projin_0_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(0)(6 downto 0),
  --    projin_0_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(0)(6 downto 0),
  --    projin_1_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(1),
  --    projin_1_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(1),
  --    projin_1_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(1),
  --    projin_1_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(1)(6 downto 0),
  --    projin_1_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(1)(6 downto 0),
  --    projin_2_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(2),
  --    projin_2_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(2),
  --    projin_2_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(2),
  --    projin_2_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(2)(6 downto 0),
  --    projin_2_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(2)(6 downto 0),
  --    projin_3_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(3),
  --    projin_3_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(3),
  --    projin_3_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(3),
  --    projin_3_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(3)(6 downto 0),
  --    projin_3_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(3)(6 downto 0),
  --    projin_4_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(4),
  --    projin_4_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(4),
  --    projin_4_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(4),
  --    projin_4_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(4)(6 downto 0),
  --    projin_4_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(4)(6 downto 0),
  --    projin_5_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(5),
  --    projin_5_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(5),
  --    projin_5_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(5),
  --    projin_5_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(5)(6 downto 0),
  --    projin_5_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(5)(6 downto 0),
  --    projin_6_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(6),
  --    projin_6_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(6),
  --    projin_6_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(6),
  --    projin_6_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(6)(6 downto 0),
  --    projin_6_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(6)(6 downto 0),
  --    projin_7_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(7),
  --    projin_7_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(7),
  --    projin_7_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(7),
  --    projin_7_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(7)(6 downto 0),
  --    projin_7_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(7)(6 downto 0),
  --    bx_o_V        => PR_bx_out,
  --    bx_o_V_ap_vld => PR_bx_out_vld,
  --    allprojout_dataarray_data_V_address0 => AP_L3PHIC_dataarray_data_V_writeaddr,
  --    allprojout_dataarray_data_V_ce0      => open,
  --    allprojout_dataarray_data_V_we0      => AP_L3PHIC_dataarray_data_V_wea,
  --    allprojout_dataarray_data_V_d0       => AP_L3PHIC_dataarray_data_V_din,
  --    vmprojout_0_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(0),
  --    vmprojout_0_dataarray_data_V_ce0      => open,
  --    vmprojout_0_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(0),
  --    vmprojout_0_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(0),
  --    vmprojout_1_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(1),
  --    vmprojout_1_dataarray_data_V_ce0      => open,
  --    vmprojout_1_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(1),
  --    vmprojout_1_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(1),
  --    vmprojout_2_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(2),
  --    vmprojout_2_dataarray_data_V_ce0      => open,
  --    vmprojout_2_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(2),
  --    vmprojout_2_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(2),
  --    vmprojout_3_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(3),
  --    vmprojout_3_dataarray_data_V_ce0      => open,
  --    vmprojout_3_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(3),
  --    vmprojout_3_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(3),
  --    vmprojout_4_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(4),
  --    vmprojout_4_dataarray_data_V_ce0      => open,
  --    vmprojout_4_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(4),
  --    vmprojout_4_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(4),
  --    vmprojout_5_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(5),
  --    vmprojout_5_dataarray_data_V_ce0      => open,
  --    vmprojout_5_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(5),
  --    vmprojout_5_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(5),
  --    vmprojout_6_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(6),
  --    vmprojout_6_dataarray_data_V_ce0      => open,
  --    vmprojout_6_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(6),
  --    vmprojout_6_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(6),
  --    vmprojout_7_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(7),
  --    vmprojout_7_dataarray_data_V_ce0      => open,
  --    vmprojout_7_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(7),
  --    vmprojout_7_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(7)
  --    );


  ----------------------------------------------------------------
  ---- AllProjection memory
  ----------------------------------------------------------------
  --AP_L3PHIC : entity work.tf_mem
  --  generic map (
  --    RAM_WIDTH       => 60,
  --    RAM_DEPTH       => 1024,
  --    INIT_FILE       => "",
  --    RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --    HEX             => 1
  --    )
  --  port map (
  --    clka     => clk,
  --    wea      => AP_L3PHIC_dataarray_data_V_wea,
  --    addra    => AP_L3PHIC_dataarray_data_V_writeaddr,
  --    dina     => AP_L3PHIC_dataarray_data_V_din,
  --    clkb     => clk,
  --    rstb     => '0',
  --    regceb   => '1',
  --    enb      => AP_L3PHIC_dataarray_data_V_enb,
  --    addrb    => AP_L3PHIC_dataarray_data_V_readaddr,
  --    doutb    => AP_L3PHIC_dataarray_data_V_dout,
  --    nent_o0  => AP_L3PHIC_nentries_V_dout(0),
  --    nent_o1  => AP_L3PHIC_nentries_V_dout(1),
  --    nent_o2  => AP_L3PHIC_nentries_V_dout(2),
  --    nent_o3  => AP_L3PHIC_nentries_V_dout(3),
  --    nent_o4  => AP_L3PHIC_nentries_V_dout(4),
  --    nent_o5  => AP_L3PHIC_nentries_V_dout(5),
  --    nent_o6  => AP_L3PHIC_nentries_V_dout(6),
  --    nent_o7  => AP_L3PHIC_nentries_V_dout(7)
  --    );


  ----------------------------------------------------------------
  ---- VMProjection memories
  ----------------------------------------------------------------
  --gen_VMPROJ_L3PHIC17to24 : for vmpidx in 7 downto 0 generate
  --begin
  --  VMPROJ_L3PHIC17to24 : entity work.tf_mem
  --    generic map (
  --      RAM_WIDTH       => 21,
  --      RAM_DEPTH       => 256,
  --      INIT_FILE       => "",
  --      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --      HEX             => 0
  --      )
  --    port map (
  --      clka     => clk,
  --      wea      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(vmpidx),
  --      addra    => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(vmpidx),
  --      dina     => VMPROJ_L3PHIC17to24_dataarray_data_V_din(vmpidx),
  --      nent_we0 => '0',
  --      nent_i0  => (others => '0'),
  --      nent_we1 => '0',
  --      nent_i1  => (others => '0'),
  --      nent_we2 => '0',
  --      nent_i2  => (others => '0'),
  --      nent_we3 => '0',
  --      nent_i3  => (others => '0'),
  --      nent_we4 => '0',
  --      nent_i4  => (others => '0'),
  --      nent_we5 => '0',
  --      nent_i5  => (others => '0'),
  --      nent_we6 => '0',
  --      nent_i6  => (others => '0'),
  --      nent_we7 => '0',
  --      nent_i7  => (others => '0'),
  --      clkb     => clk,
  --      rstb     => '0',
  --      regceb   => '1',
  --      enb      => VMPROJ_L3PHIC17to24_dataarray_data_V_enb(vmpidx),
  --      addrb    => VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr(vmpidx),
  --      doutb    => VMPROJ_L3PHIC17to24_dataarray_data_V_dout(vmpidx),
  --      nent_o0  => VMPROJ_L3PHIC17to24_nentries_V_dout(0)(vmpidx),
  --      nent_o1  => VMPROJ_L3PHIC17to24_nentries_V_dout(1)(vmpidx),
  --      nent_o2  => open,
  --      nent_o3  => open,
  --      nent_o4  => open,
  --      nent_o5  => open,
  --      nent_o6  => open,
  --      nent_o7  => open
  --      );
  
  --end generate gen_VMPROJ_L3PHIC17to24;


  ----------------------------------------------------------------
  ---- VMStubME memories
  ----------------------------------------------------------------
  --gen_VMSME_L3PHIC17to24n1 : for vmsidx in 7 downto 0 generate
  --begin
  --  VMSME_L3PHIC17to24n1 : entity work.tf_mem_bin
  --    generic map (
  --      RAM_WIDTH       => 14,
  --      RAM_DEPTH       => 1024,
  --      INIT_FILE       => "",
  --      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --      HEX             => 0
  --      )
  --    port map (
  --      clka       => clk,
  --      wea        => VMSME_L3PHIC17to24n1_dataarray_data_V_wea(vmsidx),
  --      addra      => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(vmsidx),
  --      dina       => VMSME_L3PHIC17to24n1_dataarray_data_V_din(vmsidx),
  --      clkb       => clk,
  --      rstb       => '0',
  --      regceb     => '1',
  --      enb        => VMSME_L3PHIC17to24n1_dataarray_data_V_enb(vmsidx),
  --      addrb      => VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr(vmsidx),
  --      doutb      => VMSME_L3PHIC17to24n1_dataarray_data_V_dout(vmsidx),
  --      nent_0_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(0)(vmsidx)(3 downto 0),
  --      nent_0_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(1)(vmsidx)(3 downto 0),
  --      nent_0_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(2)(vmsidx)(3 downto 0),
  --      nent_0_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(3)(vmsidx)(3 downto 0),
  --      nent_0_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(4)(vmsidx)(3 downto 0),
  --      nent_0_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(5)(vmsidx)(3 downto 0),
  --      nent_0_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(6)(vmsidx)(3 downto 0),
  --      nent_0_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(7)(vmsidx)(3 downto 0),
  --      nent_1_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(0)(vmsidx)(3 downto 0),
  --      nent_1_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(1)(vmsidx)(3 downto 0),
  --      nent_1_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(2)(vmsidx)(3 downto 0),
  --      nent_1_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(3)(vmsidx)(3 downto 0),
  --      nent_1_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(4)(vmsidx)(3 downto 0),
  --      nent_1_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(5)(vmsidx)(3 downto 0),
  --      nent_1_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(6)(vmsidx)(3 downto 0),
  --      nent_1_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(7)(vmsidx)(3 downto 0),
  --      nent_2_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(0)(vmsidx)(3 downto 0),
  --      nent_2_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(1)(vmsidx)(3 downto 0),
  --      nent_2_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(2)(vmsidx)(3 downto 0),
  --      nent_2_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(3)(vmsidx)(3 downto 0),
  --      nent_2_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(4)(vmsidx)(3 downto 0),
  --      nent_2_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(5)(vmsidx)(3 downto 0),
  --      nent_2_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(6)(vmsidx)(3 downto 0),
  --      nent_2_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(7)(vmsidx)(3 downto 0),
  --      nent_3_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(0)(vmsidx)(3 downto 0),
  --      nent_3_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(1)(vmsidx)(3 downto 0),
  --      nent_3_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(2)(vmsidx)(3 downto 0),
  --      nent_3_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(3)(vmsidx)(3 downto 0),
  --      nent_3_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(4)(vmsidx)(3 downto 0),
  --      nent_3_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(5)(vmsidx)(3 downto 0),
  --      nent_3_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(6)(vmsidx)(3 downto 0),
  --      nent_3_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(7)(vmsidx)(3 downto 0),
  --      nent_4_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(0)(vmsidx)(3 downto 0),
  --      nent_4_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(1)(vmsidx)(3 downto 0),
  --      nent_4_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(2)(vmsidx)(3 downto 0),
  --      nent_4_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(3)(vmsidx)(3 downto 0),
  --      nent_4_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(4)(vmsidx)(3 downto 0),
  --      nent_4_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(5)(vmsidx)(3 downto 0),
  --      nent_4_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(6)(vmsidx)(3 downto 0),
  --      nent_4_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(7)(vmsidx)(3 downto 0),
  --      nent_5_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(0)(vmsidx)(3 downto 0),
  --      nent_5_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(1)(vmsidx)(3 downto 0),
  --      nent_5_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(2)(vmsidx)(3 downto 0),
  --      nent_5_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(3)(vmsidx)(3 downto 0),
  --      nent_5_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(4)(vmsidx)(3 downto 0),
  --      nent_5_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(5)(vmsidx)(3 downto 0),
  --      nent_5_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(6)(vmsidx)(3 downto 0),
  --      nent_5_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(7)(vmsidx)(3 downto 0),
  --      nent_6_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(0)(vmsidx)(3 downto 0),
  --      nent_6_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(1)(vmsidx)(3 downto 0),
  --      nent_6_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(2)(vmsidx)(3 downto 0),
  --      nent_6_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(3)(vmsidx)(3 downto 0),
  --      nent_6_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(4)(vmsidx)(3 downto 0),
  --      nent_6_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(5)(vmsidx)(3 downto 0),
  --      nent_6_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(6)(vmsidx)(3 downto 0),
  --      nent_6_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(7)(vmsidx)(3 downto 0),
  --      nent_7_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(0)(vmsidx)(3 downto 0),
  --      nent_7_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(1)(vmsidx)(3 downto 0),
  --      nent_7_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(2)(vmsidx)(3 downto 0),
  --      nent_7_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(3)(vmsidx)(3 downto 0),
  --      nent_7_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(4)(vmsidx)(3 downto 0),
  --      nent_7_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(5)(vmsidx)(3 downto 0),
  --      nent_7_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(6)(vmsidx)(3 downto 0),
  --      nent_7_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(7)(vmsidx)(3 downto 0)
  --      );

  --end generate gen_VMSME_L3PHIC17to24n1;


  ----------------------------------------------------------------
  ---- MatchEngine
  ----------------------------------------------------------------
  --gen_ME : for meidx in 7 downto 0 generate
  --begin
  --  i_ME : entity work.MatchEngineTopL3_0
  --    port map (
  --      ap_clk   => clk,
  --      ap_rst   => reset,
  --      ap_start => ME_start,
  --      ap_done  => ME_done(meidx),
  --      ap_idle  => ME_idle,
  --      ap_ready => ME_ready,
  --      bx_V          => PR_bx_out,
  --      bx_o_V        => ME_bx_out(meidx),
  --      bx_o_V_ap_vld => ME_bx_out_vld(meidx),
  --      inputStubData_dataarray_data_V_address0 => VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr(meidx),
  --      inputStubData_dataarray_data_V_ce0      => VMSME_L3PHIC17to24n1_dataarray_data_V_enb(meidx),
  --      inputStubData_dataarray_data_V_q0       => VMSME_L3PHIC17to24n1_dataarray_data_V_dout(meidx)(12 downto 0),
  --      inputStubData_nentries_0_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(0)(meidx),
  --      inputStubData_nentries_0_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(1)(meidx),
  --      inputStubData_nentries_0_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(2)(meidx),
  --      inputStubData_nentries_0_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(3)(meidx),
  --      inputStubData_nentries_0_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(4)(meidx),
  --      inputStubData_nentries_0_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(5)(meidx),
  --      inputStubData_nentries_0_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(6)(meidx),
  --      inputStubData_nentries_0_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(7)(meidx),
  --      inputStubData_nentries_1_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(0)(meidx),
  --      inputStubData_nentries_1_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(1)(meidx),
  --      inputStubData_nentries_1_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(2)(meidx),
  --      inputStubData_nentries_1_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(3)(meidx),
  --      inputStubData_nentries_1_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(4)(meidx),
  --      inputStubData_nentries_1_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(5)(meidx),
  --      inputStubData_nentries_1_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(6)(meidx),
  --      inputStubData_nentries_1_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(7)(meidx),
  --      inputStubData_nentries_2_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(0)(meidx),
  --      inputStubData_nentries_2_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(1)(meidx),
  --      inputStubData_nentries_2_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(2)(meidx),
  --      inputStubData_nentries_2_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(3)(meidx),
  --      inputStubData_nentries_2_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(4)(meidx),
  --      inputStubData_nentries_2_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(5)(meidx),
  --      inputStubData_nentries_2_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(6)(meidx),
  --      inputStubData_nentries_2_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(7)(meidx),
  --      inputStubData_nentries_3_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(0)(meidx),
  --      inputStubData_nentries_3_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(1)(meidx),
  --      inputStubData_nentries_3_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(2)(meidx),
  --      inputStubData_nentries_3_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(3)(meidx),
  --      inputStubData_nentries_3_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(4)(meidx),
  --      inputStubData_nentries_3_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(5)(meidx),
  --      inputStubData_nentries_3_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(6)(meidx),
  --      inputStubData_nentries_3_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(7)(meidx),
  --      inputStubData_nentries_4_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(0)(meidx),
  --      inputStubData_nentries_4_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(1)(meidx),
  --      inputStubData_nentries_4_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(2)(meidx),
  --      inputStubData_nentries_4_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(3)(meidx),
  --      inputStubData_nentries_4_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(4)(meidx),
  --      inputStubData_nentries_4_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(5)(meidx),
  --      inputStubData_nentries_4_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(6)(meidx),
  --      inputStubData_nentries_4_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(7)(meidx),
  --      inputStubData_nentries_5_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(0)(meidx),
  --      inputStubData_nentries_5_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(1)(meidx),
  --      inputStubData_nentries_5_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(2)(meidx),
  --      inputStubData_nentries_5_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(3)(meidx),
  --      inputStubData_nentries_5_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(4)(meidx),
  --      inputStubData_nentries_5_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(5)(meidx),
  --      inputStubData_nentries_5_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(6)(meidx),
  --      inputStubData_nentries_5_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(7)(meidx),
  --      inputStubData_nentries_6_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(0)(meidx),
  --      inputStubData_nentries_6_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(1)(meidx),
  --      inputStubData_nentries_6_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(2)(meidx),
  --      inputStubData_nentries_6_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(3)(meidx),
  --      inputStubData_nentries_6_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(4)(meidx),
  --      inputStubData_nentries_6_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(5)(meidx),
  --      inputStubData_nentries_6_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(6)(meidx),
  --      inputStubData_nentries_6_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(7)(meidx),
  --      inputStubData_nentries_7_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(0)(meidx),
  --      inputStubData_nentries_7_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(1)(meidx),
  --      inputStubData_nentries_7_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(2)(meidx),
  --      inputStubData_nentries_7_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(3)(meidx),
  --      inputStubData_nentries_7_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(4)(meidx),
  --      inputStubData_nentries_7_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(5)(meidx),
  --      inputStubData_nentries_7_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(6)(meidx),
  --      inputStubData_nentries_7_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(7)(meidx),
  --      inputProjectionData_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr(meidx),
  --      inputProjectionData_dataarray_data_V_ce0      => VMPROJ_L3PHIC17to24_dataarray_data_V_enb(meidx),
  --      inputProjectionData_dataarray_data_V_q0       => VMPROJ_L3PHIC17to24_dataarray_data_V_dout(meidx),
  --      inputProjectionData_nentries_0_V => VMPROJ_L3PHIC17to24_nentries_V_dout(0)(meidx)(6 downto 0),
  --      inputProjectionData_nentries_1_V => VMPROJ_L3PHIC17to24_nentries_V_dout(1)(meidx)(6 downto 0),
  --      outputCandidateMatch_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_writeaddr(meidx),
  --      outputCandidateMatch_dataarray_data_V_ce0      => open,
  --      outputCandidateMatch_dataarray_data_V_we0      => CM_L3PHIC17to24_dataarray_data_V_wea(meidx),
  --      outputCandidateMatch_dataarray_data_V_d0       => CM_L3PHIC17to24_dataarray_data_V_din(meidx)
  --      );

  --end generate gen_ME;

  ----------------------------------------------------------------
  ---- AllStubs memory
  ----------------------------------------------------------------
  --AS_L3PHICn4 : entity work.tf_mem
  --  generic map (
  --    RAM_WIDTH       => 36,
  --    RAM_DEPTH       => 1024,
  --    INIT_FILE       => "",
  --    RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --    HEX             => 0
  --    )
  --  port map (
  --    clka     => clk,
  --    wea      => AS_L3PHICn4_dataarray_data_V_wea,
  --    addra    => AS_L3PHICn4_dataarray_data_V_writeaddr,
  --    dina     => AS_L3PHICn4_dataarray_data_V_din,
  --    clkb     => clk,
  --    rstb     => '0',
  --    regceb   => '1',
  --    enb      => AS_L3PHICn4_dataarray_data_V_enb,
  --    addrb    => AS_L3PHICn4_dataarray_data_V_readaddr,
  --    doutb    => AS_L3PHICn4_dataarray_data_V_dout,
  --    nent_o0  => AS_L3PHICn4_nentries_V_dout(0),
  --    nent_o1  => AS_L3PHICn4_nentries_V_dout(1),
  --    nent_o2  => AS_L3PHICn4_nentries_V_dout(2),
  --    nent_o3  => AS_L3PHICn4_nentries_V_dout(3),
  --    nent_o4  => AS_L3PHICn4_nentries_V_dout(4),
  --    nent_o5  => AS_L3PHICn4_nentries_V_dout(5),
  --    nent_o6  => AS_L3PHICn4_nentries_V_dout(6),
  --    nent_o7  => AS_L3PHICn4_nentries_V_dout(7)
  --    );


  ----------------------------------------------------------------
  ---- CandidateMatches memories
  ----------------------------------------------------------------
  --gen_CM_L3PHIC17to24 : for cmidx in 7 downto 0 generate
  --begin
  --  CM_L3PHIC17to24 : entity work.tf_mem
  --    generic map (
  --      RAM_WIDTH       => 14,
  --      RAM_DEPTH       => 256,
  --      INIT_FILE       => "",
  --      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --      HEX             => 1
  --      )
  --    port map (
  --      clka     => clk,
  --      wea      => CM_L3PHIC17to24_dataarray_data_V_wea(cmidx),
  --      addra    => CM_L3PHIC17to24_dataarray_data_V_writeaddr(cmidx),
  --      dina     => CM_L3PHIC17to24_dataarray_data_V_din(cmidx),
  --      nent_we0 => '0',
  --      nent_i0  => (others => '0'),
  --      nent_we1 => '0',
  --      nent_i1  => (others => '0'),
  --      nent_we2 => '0',
  --      nent_i2  => (others => '0'),
  --      nent_we3 => '0',
  --      nent_i3  => (others => '0'),
  --      nent_we4 => '0',
  --      nent_i4  => (others => '0'),
  --      nent_we5 => '0',
  --      nent_i5  => (others => '0'),
  --      nent_we6 => '0',
  --      nent_i6  => (others => '0'),
  --      nent_we7 => '0',
  --      nent_i7  => (others => '0'),
  --      clkb     => clk,
  --      rstb     => '0',
  --      regceb   => '1',
  --      enb      => CM_L3PHIC17to24_dataarray_data_V_enb(cmidx),
  --      addrb    => CM_L3PHIC17to24_dataarray_data_V_readaddr(cmidx),
  --      doutb    => CM_L3PHIC17to24_dataarray_data_V_dout(cmidx),
  --      nent_o0  => CM_L3PHIC17to24_nentries_V_dout(0)(cmidx),
  --      nent_o1  => CM_L3PHIC17to24_nentries_V_dout(1)(cmidx),
  --      nent_o2  => open,
  --      nent_o3  => open,
  --      nent_o4  => open,
  --      nent_o5  => open,
  --      nent_o6  => open,
  --      nent_o7  => open
  --      );

  --end generate gen_CM_L3PHIC17to24;


  ----------------------------------------------------------------
  ---- MatchCalculator
  ----------------------------------------------------------------
  --MC_L3PHIC : entity work.MC_L3PHIC
  --  port map (
  --    ap_clk   => clk,
  --    ap_rst   => reset,
  --    ap_start => MC_start,
  --    ap_done  => MC_done,
  --    ap_idle  => MC_idle,
  --    ap_ready => MC_ready,
  --    bx_V     => ME_bx_out(0), -- All MEs should have the same counter value
  --    match_0_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(0),
  --    match_0_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(0),
  --    match_0_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(0),
  --    match_0_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(0)(6 downto 0),
  --    match_0_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(0)(6 downto 0),
  --    match_1_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(1),
  --    match_1_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(1),
  --    match_1_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(1),
  --    match_1_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(1)(6 downto 0),
  --    match_1_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(1)(6 downto 0),
  --    match_2_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(2),
  --    match_2_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(2),
  --    match_2_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(2),
  --    match_2_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(2)(6 downto 0),
  --    match_2_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(2)(6 downto 0),
  --    match_3_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(3),
  --    match_3_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(3),
  --    match_3_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(3),
  --    match_3_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(3)(6 downto 0),
  --    match_3_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(3)(6 downto 0),
  --    match_4_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(4),
  --    match_4_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(4),
  --    match_4_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(4),
  --    match_4_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(4)(6 downto 0),
  --    match_4_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(4)(6 downto 0),
  --    match_5_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(5),
  --    match_5_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(5),
  --    match_5_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(5),
  --    match_5_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(5)(6 downto 0),
  --    match_5_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(5)(6 downto 0),
  --    match_6_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(6),
  --    match_6_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(6),
  --    match_6_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(6),
  --    match_6_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(6)(6 downto 0),
  --    match_6_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(6)(6 downto 0),
  --    match_7_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(7),
  --    match_7_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(7),
  --    match_7_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(7),
  --    match_7_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(7)(6 downto 0),
  --    match_7_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(7)(6 downto 0),
  --    allstub_dataarray_data_V_address0 => AS_L3PHICn4_dataarray_data_V_readaddr,
  --    allstub_dataarray_data_V_ce0      => AS_L3PHICn4_dataarray_data_V_enb,
  --    allstub_dataarray_data_V_q0       => AS_L3PHICn4_dataarray_data_V_dout,
  --    allproj_dataarray_data_V_address0 => AP_L3PHIC_dataarray_data_V_readaddr,
  --    allproj_dataarray_data_V_ce0      => AP_L3PHIC_dataarray_data_V_enb,
  --    allproj_dataarray_data_V_q0       => AP_L3PHIC_dataarray_data_V_dout,
  --    bx_o_V        => MC_bx_out,
  --    bx_o_V_ap_vld => MC_bx_out_vld,
  --    fullmatch_0_dataarray_data_V_address0 => FM_L1L2_L3PHIC_dataarray_data_V_writeaddr,
  --    fullmatch_0_dataarray_data_V_ce0      => open,
  --    fullmatch_0_dataarray_data_V_we0      => FM_L1L2_L3PHIC_dataarray_data_V_wea,
  --    fullmatch_0_dataarray_data_V_d0       => FM_L1L2_L3PHIC_dataarray_data_V_din,
  --    fullmatch_3_dataarray_data_V_address0 => FM_L5L6_L3PHIC_dataarray_data_V_writeaddr,
  --    fullmatch_3_dataarray_data_V_ce0      => open,
  --    fullmatch_3_dataarray_data_V_we0      => FM_L5L6_L3PHIC_dataarray_data_V_wea,
  --    fullmatch_3_dataarray_data_V_d0       => FM_L5L6_L3PHIC_dataarray_data_V_din
  --    );


  ----------------------------------------------------------------
  ---- FullMatches memories
  ----------------------------------------------------------------
  --FM_L1L2_L3PHIC : entity work.tf_mem
  --  generic map (
  --    RAM_WIDTH       => 45,
  --    RAM_DEPTH       => 256,
  --    INIT_FILE       => "",
  --    RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --    HEX             => 0
  --    )
  --  port map (
  --    clka     => clk,
  --    wea      => FM_L1L2_L3PHIC_dataarray_data_V_wea,
  --    addra    => FM_L1L2_L3PHIC_dataarray_data_V_writeaddr,
  --    dina     => FM_L1L2_L3PHIC_dataarray_data_V_din,
  --    nent_we0 => '0',
  --    nent_i0  => (others => '0'),
  --    nent_we1 => '0',
  --    nent_i1  => (others => '0'),
  --    nent_we2 => '0',
  --    nent_i2  => (others => '0'),
  --    nent_we3 => '0',
  --    nent_i3  => (others => '0'),
  --    nent_we4 => '0',
  --    nent_i4  => (others => '0'),
  --    nent_we5 => '0',
  --    nent_i5  => (others => '0'),
  --    nent_we6 => '0',
  --    nent_i6  => (others => '0'),
  --    nent_we7 => '0',
  --    nent_i7  => (others => '0'),
  --    clkb     => clk,
  --    rstb     => '0',
  --    regceb   => '1',
  --    enb      => FM_L1L2_L3PHIC_dataarray_data_V_enb,
  --    addrb    => FM_L1L2_L3PHIC_dataarray_data_V_readaddr,
  --    doutb    => FM_L1L2_L3PHIC_dataarray_data_V_dout,
  --    nent_o0  => FM_L1L2_L3PHIC_nentries_V_dout(0),
  --    nent_o1  => FM_L1L2_L3PHIC_nentries_V_dout(1),
  --    nent_o2  => open,
  --    nent_o3  => open,
  --    nent_o4  => open,
  --    nent_o5  => open,
  --    nent_o6  => open,
  --    nent_o7  => open
  --    );

  --FM_L5L6_L3PHIC : entity work.tf_mem
  --  generic map (
  --    RAM_WIDTH       => 45,
  --    RAM_DEPTH       => 256,
  --    INIT_FILE       => "",
  --    RAM_PERFORMANCE => "HIGH_PERFORMANCE",
  --    HEX             => 0
  --    )
  --  port map (
  --    clka     => clk,
  --    wea      => FM_L5L6_L3PHIC_dataarray_data_V_wea,
  --    addra    => FM_L5L6_L3PHIC_dataarray_data_V_writeaddr,
  --    dina     => FM_L5L6_L3PHIC_dataarray_data_V_din,
  --    nent_we0 => '0',
  --    nent_i0  => (others => '0'),
  --    nent_we1 => '0',
  --    nent_i1  => (others => '0'),
  --    nent_we2 => '0',
  --    nent_i2  => (others => '0'),
  --    nent_we3 => '0',
  --    nent_i3  => (others => '0'),
  --    nent_we4 => '0',
  --    nent_i4  => (others => '0'),
  --    nent_we5 => '0',
  --    nent_i5  => (others => '0'),
  --    nent_we6 => '0',
  --    nent_i6  => (others => '0'),
  --    nent_we7 => '0',
  --    nent_i7  => (others => '0'),
  --    clkb     => clk,
  --    rstb     => '0',
  --    regceb   => '1',
  --    enb      => FM_L5L6_L3PHIC_dataarray_data_V_enb,
  --    addrb    => FM_L5L6_L3PHIC_dataarray_data_V_readaddr,
  --    doutb    => FM_L5L6_L3PHIC_dataarray_data_V_dout,
  --    nent_o0  => FM_L5L6_L3PHIC_nentries_V_dout(0),
  --    nent_o1  => FM_L5L6_L3PHIC_nentries_V_dout(1),
  --    nent_o2  => open,
  --    nent_o3  => open,
  --    nent_o4  => open,
  --    nent_o5  => open,
  --    nent_o6  => open,
  --    nent_o7  => open
  --    );

end rtl;
