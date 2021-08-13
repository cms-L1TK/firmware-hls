--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;

entity SectorProcessor is
  port(
    clk        : in std_logic;
    reset      : in std_logic;
    PR_start  : in std_logic;
    PR_bx_in : in std_logic_vector(2 downto 0);
    MC_bx_out : out std_logic_vector(2 downto 0);
    MC_bx_out_vld : out std_logic;
    MC_done   : out std_logic;
    AS_36_mem_A_wea        : in t_arr_AS_36_1b;
    AS_36_mem_AV_writeaddr : in t_arr_AS_36_ADDR;
    AS_36_mem_AV_din       : in t_arr_AS_36_DATA;
    VMSME_16_mem_A_wea        : in t_arr_VMSME_16_1b;
    VMSME_16_mem_AV_writeaddr : in t_arr_VMSME_16_ADDR;
    VMSME_16_mem_AV_din       : in t_arr_VMSME_16_DATA;
    TPROJ_60_mem_A_wea        : in t_arr_TPROJ_60_1b;
    TPROJ_60_mem_AV_writeaddr : in t_arr_TPROJ_60_ADDR;
    TPROJ_60_mem_AV_din       : in t_arr_TPROJ_60_DATA;
    FM_52_mem_A_enb          : in t_arr_FM_52_1b;
    FM_52_mem_AV_readaddr    : in t_arr_FM_52_ADDR;
    FM_52_mem_AV_dout        : out t_arr_FM_52_DATA;
    FM_52_mem_AAV_dout_nent  : out t_arr_FM_52_NENT
  );
end SectorProcessor;

architecture rtl of SectorProcessor is

  signal AS_36_mem_A_enb          : t_arr_AS_36_1b;
  signal AS_36_mem_AV_readaddr    : t_arr_AS_36_ADDR;
  signal AS_36_mem_AV_dout        : t_arr_AS_36_DATA;
  signal VMSME_16_mem_A_enb          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem_AV_readaddr    : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem_AV_dout        : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem_AAAV_dout_nent : t_arr_VMSME_16_NENT; -- (#page)(#bin)
  signal TPROJ_60_mem_A_enb          : t_arr_TPROJ_60_1b;
  signal TPROJ_60_mem_AV_readaddr    : t_arr_TPROJ_60_ADDR;
  signal TPROJ_60_mem_AV_dout        : t_arr_TPROJ_60_DATA;
  signal TPROJ_60_mem_AAV_dout_nent  : t_arr_TPROJ_60_NENT; -- (#page)
  signal VMPROJ_24_mem_A_wea          : t_arr_VMPROJ_24_1b;
  signal VMPROJ_24_mem_AV_writeaddr   : t_arr_VMPROJ_24_ADDR;
  signal VMPROJ_24_mem_AV_din         : t_arr_VMPROJ_24_DATA;
  signal VMPROJ_24_mem_A_enb          : t_arr_VMPROJ_24_1b;
  signal VMPROJ_24_mem_AV_readaddr    : t_arr_VMPROJ_24_ADDR;
  signal VMPROJ_24_mem_AV_dout        : t_arr_VMPROJ_24_DATA;
  signal VMPROJ_24_mem_AAV_dout_nent  : t_arr_VMPROJ_24_NENT; -- (#page)
  signal AP_60_mem_A_wea          : t_arr_AP_60_1b;
  signal AP_60_mem_AV_writeaddr   : t_arr_AP_60_ADDR;
  signal AP_60_mem_AV_din         : t_arr_AP_60_DATA;
  signal AP_60_mem_A_enb          : t_arr_AP_60_1b;
  signal AP_60_mem_AV_readaddr    : t_arr_AP_60_ADDR;
  signal AP_60_mem_AV_dout        : t_arr_AP_60_DATA;
  signal CM_14_mem_A_wea          : t_arr_CM_14_1b;
  signal CM_14_mem_AV_writeaddr   : t_arr_CM_14_ADDR;
  signal CM_14_mem_AV_din         : t_arr_CM_14_DATA;
  signal CM_14_mem_A_enb          : t_arr_CM_14_1b;
  signal CM_14_mem_AV_readaddr    : t_arr_CM_14_ADDR;
  signal CM_14_mem_AV_dout        : t_arr_CM_14_DATA;
  signal CM_14_mem_AAV_dout_nent  : t_arr_CM_14_NENT; -- (#page)
  signal FM_52_mem_A_wea          : t_arr_FM_52_1b;
  signal FM_52_mem_AV_writeaddr   : t_arr_FM_52_ADDR;
  signal FM_52_mem_AV_din         : t_arr_FM_52_DATA;
  signal PR_done : std_logic := '0';
  signal PR_bx_out : std_logic_vector(2 downto 0);
  signal PR_bx_out_vld : std_logic;
  signal ME_start : std_logic := '0';
  signal ME_done : std_logic := '0';
  signal ME_bx_out : std_logic_vector(2 downto 0);
  signal ME_bx_out_vld : std_logic;
  signal MC_start : std_logic := '0';

begin

  AS_36_loop : for var in enum_AS_36 generate
  begin

    AS_36 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => AS_36_mem_A_wea(var),
        addra     => AS_36_mem_AV_writeaddr(var),
        dina      => AS_36_mem_AV_din(var),
        clkb      => clk,
        enb       => AS_36_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => AS_36_mem_AV_readaddr(var),
        doutb     => AS_36_mem_AV_dout(var),
        sync_nent => MC_start,
        nent_o    => open
      );

  end generate AS_36_loop;


  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin

    VMSME_16 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => VMSME_16_mem_A_wea(var),
        addra     => VMSME_16_mem_AV_writeaddr(var),
        dina      => VMSME_16_mem_AV_din(var),
        clkb      => clk,
        enb       => VMSME_16_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => VMSME_16_mem_AV_readaddr(var),
        doutb     => VMSME_16_mem_AV_dout(var),
        sync_nent => ME_start,
        nent_o    => VMSME_16_mem_AAAV_dout_nent(var)
      );

  end generate VMSME_16_loop;


  TPROJ_60_loop : for var in enum_TPROJ_60 generate
  begin

    TPROJ_60 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => TPROJ_60_mem_A_wea(var),
        addra     => TPROJ_60_mem_AV_writeaddr(var),
        dina      => TPROJ_60_mem_AV_din(var),
        clkb      => clk,
        enb       => TPROJ_60_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => TPROJ_60_mem_AV_readaddr(var),
        doutb     => TPROJ_60_mem_AV_dout(var),
        sync_nent => PR_start,
        nent_o    => TPROJ_60_mem_AAV_dout_nent(var)
      );

  end generate TPROJ_60_loop;


  VMPROJ_24_loop : for var in enum_VMPROJ_24 generate
  begin

    VMPROJ_24 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 24,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => VMPROJ_24_mem_A_wea(var),
        addra     => VMPROJ_24_mem_AV_writeaddr(var),
        dina      => VMPROJ_24_mem_AV_din(var),
        clkb      => clk,
        enb       => VMPROJ_24_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => VMPROJ_24_mem_AV_readaddr(var),
        doutb     => VMPROJ_24_mem_AV_dout(var),
        sync_nent => ME_start,
        nent_o    => VMPROJ_24_mem_AAV_dout_nent(var)
      );

  end generate VMPROJ_24_loop;


  AP_60_loop : for var in enum_AP_60 generate
  begin

    AP_60 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => AP_60_mem_A_wea(var),
        addra     => AP_60_mem_AV_writeaddr(var),
        dina      => AP_60_mem_AV_din(var),
        clkb      => clk,
        enb       => AP_60_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => AP_60_mem_AV_readaddr(var),
        doutb     => AP_60_mem_AV_dout(var),
        sync_nent => MC_start,
        nent_o    => open
      );

  end generate AP_60_loop;


  CM_14_loop : for var in enum_CM_14 generate
  begin

    CM_14 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 14,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => CM_14_mem_A_wea(var),
        addra     => CM_14_mem_AV_writeaddr(var),
        dina      => CM_14_mem_AV_din(var),
        clkb      => clk,
        enb       => CM_14_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => CM_14_mem_AV_readaddr(var),
        doutb     => CM_14_mem_AV_dout(var),
        sync_nent => MC_start,
        nent_o    => CM_14_mem_AAV_dout_nent(var)
      );

  end generate CM_14_loop;


  FM_52_loop : for var in enum_FM_52 generate
  begin

    FM_52 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => FM_52_mem_A_wea(var),
        addra     => FM_52_mem_AV_writeaddr(var),
        dina      => FM_52_mem_AV_din(var),
        clkb      => clk,
        enb       => FM_52_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => FM_52_mem_AV_readaddr(var),
        doutb     => FM_52_mem_AV_dout(var),
        sync_nent => MC_done,
        nent_o    => FM_52_mem_AAV_dout_nent(var)
      );

  end generate FM_52_loop;


  ME_start <= '1' when PR_done = '1';

  PR_L3PHIC : entity work.PR_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => PR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => PR_done,
      bx_V          => PR_bx_in,
      bx_o_V        => PR_bx_out,
      bx_o_V_ap_vld => PR_bx_out_vld,
      projin_0_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2F_L3PHIC),
      projin_0_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2F_L3PHIC),
      projin_0_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2F_L3PHIC),
      projin_0_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2F_L3PHIC)(0),
      projin_0_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2F_L3PHIC)(1),
      projin_1_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2G_L3PHIC),
      projin_1_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2G_L3PHIC),
      projin_1_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2G_L3PHIC),
      projin_1_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2G_L3PHIC)(0),
      projin_1_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2G_L3PHIC)(1),
      projin_2_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2H_L3PHIC),
      projin_2_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2H_L3PHIC),
      projin_2_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2H_L3PHIC),
      projin_2_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2H_L3PHIC)(0),
      projin_2_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2H_L3PHIC)(1),
      projin_3_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2I_L3PHIC),
      projin_3_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2I_L3PHIC),
      projin_3_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2I_L3PHIC),
      projin_3_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2I_L3PHIC)(0),
      projin_3_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2I_L3PHIC)(1),
      projin_4_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2J_L3PHIC),
      projin_4_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2J_L3PHIC),
      projin_4_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2J_L3PHIC),
      projin_4_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2J_L3PHIC)(0),
      projin_4_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2J_L3PHIC)(1),
      projin_5_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L5L6B_L3PHIC),
      projin_5_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L5L6B_L3PHIC),
      projin_5_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L5L6B_L3PHIC),
      projin_5_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L5L6B_L3PHIC)(0),
      projin_5_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L5L6B_L3PHIC)(1),
      projin_6_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L5L6C_L3PHIC),
      projin_6_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L5L6C_L3PHIC),
      projin_6_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L5L6C_L3PHIC),
      projin_6_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L5L6C_L3PHIC)(0),
      projin_6_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L5L6C_L3PHIC)(1),
      projin_7_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L5L6D_L3PHIC),
      projin_7_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L5L6D_L3PHIC),
      projin_7_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L5L6D_L3PHIC),
      projin_7_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L5L6D_L3PHIC)(0),
      projin_7_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L5L6D_L3PHIC)(1),
      allprojout_dataarray_data_V_ce0       => open,
      allprojout_dataarray_data_V_we0       => AP_60_mem_A_wea(L3PHIC),
      allprojout_dataarray_data_V_address0  => AP_60_mem_AV_writeaddr(L3PHIC),
      allprojout_dataarray_data_V_d0        => AP_60_mem_AV_din(L3PHIC),
      vmprojout_0_dataarray_data_V_ce0       => open,
      vmprojout_0_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC17),
      vmprojout_0_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC17),
      vmprojout_0_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC17),
      vmprojout_1_dataarray_data_V_ce0       => open,
      vmprojout_1_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC18),
      vmprojout_1_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC18),
      vmprojout_1_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC18),
      vmprojout_2_dataarray_data_V_ce0       => open,
      vmprojout_2_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC19),
      vmprojout_2_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC19),
      vmprojout_2_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC19),
      vmprojout_3_dataarray_data_V_ce0       => open,
      vmprojout_3_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC20),
      vmprojout_3_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC20),
      vmprojout_3_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC20),
      vmprojout_4_dataarray_data_V_ce0       => open,
      vmprojout_4_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC21),
      vmprojout_4_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC21),
      vmprojout_4_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC21),
      vmprojout_5_dataarray_data_V_ce0       => open,
      vmprojout_5_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC22),
      vmprojout_5_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC22),
      vmprojout_5_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC22),
      vmprojout_6_dataarray_data_V_ce0       => open,
      vmprojout_6_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC23),
      vmprojout_6_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC23),
      vmprojout_6_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC23),
      vmprojout_7_dataarray_data_V_ce0       => open,
      vmprojout_7_dataarray_data_V_we0       => VMPROJ_24_mem_A_wea(L3PHIC24),
      vmprojout_7_dataarray_data_V_address0  => VMPROJ_24_mem_AV_writeaddr(L3PHIC24),
      vmprojout_7_dataarray_data_V_d0        => VMPROJ_24_mem_AV_din(L3PHIC24)
  );

  MC_start <= '1' when ME_done = '1';

  ME_L3PHIC17 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => ME_done,
      bx_V          => PR_bx_out,
      bx_o_V        => ME_bx_out,
      bx_o_V_ap_vld => ME_bx_out_vld,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC17n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC17n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC17n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC17n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC17),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC17),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC17),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC17)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC17)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC17),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC17),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC17)
  );

  ME_L3PHIC18 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC18n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC18n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC18n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC18n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC18),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC18),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC18),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC18)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC18)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC18),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC18),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC18)
  );

  ME_L3PHIC19 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC19n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC19n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC19n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC19n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC19),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC19),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC19),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC19)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC19)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC19),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC19),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC19)
  );

  ME_L3PHIC20 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC20n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC20n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC20n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC20n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC20),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC20),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC20),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC20)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC20)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC20),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC20),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC20)
  );

  ME_L3PHIC21 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC21n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC21n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC21n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC21n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC21),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC21),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC21),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC21)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC21)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC21),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC21),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC21)
  );

  ME_L3PHIC22 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC22n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC22n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC22n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC22n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC22),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC22),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC22),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC22)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC22)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC22),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC22),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC22)
  );

  ME_L3PHIC23 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC23n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC23n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC23n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC23n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC23),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC23),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC23),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC23)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC23)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC23),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC23),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC23)
  );

  ME_L3PHIC24 : entity work.ME_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => ME_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => PR_bx_out,
      inputStubData_dataarray_data_V_ce0       => VMSME_16_mem_A_enb(L3PHIC24n1),
      inputStubData_dataarray_data_V_address0  => VMSME_16_mem_AV_readaddr(L3PHIC24n1),
      inputStubData_dataarray_data_V_q0        => VMSME_16_mem_AV_dout(L3PHIC24n1),
      inputStubData_nentries_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(0),
      inputStubData_nentries_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(1),
      inputStubData_nentries_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(2),
      inputStubData_nentries_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(3),
      inputStubData_nentries_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(4),
      inputStubData_nentries_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(5),
      inputStubData_nentries_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(6),
      inputStubData_nentries_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(0)(7),
      inputStubData_nentries_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(0),
      inputStubData_nentries_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(1),
      inputStubData_nentries_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(2),
      inputStubData_nentries_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(3),
      inputStubData_nentries_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(4),
      inputStubData_nentries_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(5),
      inputStubData_nentries_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(6),
      inputStubData_nentries_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(1)(7),
      inputStubData_nentries_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(0),
      inputStubData_nentries_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(1),
      inputStubData_nentries_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(2),
      inputStubData_nentries_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(3),
      inputStubData_nentries_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(4),
      inputStubData_nentries_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(5),
      inputStubData_nentries_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(6),
      inputStubData_nentries_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(2)(7),
      inputStubData_nentries_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(0),
      inputStubData_nentries_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(1),
      inputStubData_nentries_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(2),
      inputStubData_nentries_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(3),
      inputStubData_nentries_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(4),
      inputStubData_nentries_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(5),
      inputStubData_nentries_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(6),
      inputStubData_nentries_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(3)(7),
      inputStubData_nentries_4_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(0),
      inputStubData_nentries_4_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(1),
      inputStubData_nentries_4_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(2),
      inputStubData_nentries_4_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(3),
      inputStubData_nentries_4_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(4),
      inputStubData_nentries_4_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(5),
      inputStubData_nentries_4_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(6),
      inputStubData_nentries_4_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(4)(7),
      inputStubData_nentries_5_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(0),
      inputStubData_nentries_5_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(1),
      inputStubData_nentries_5_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(2),
      inputStubData_nentries_5_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(3),
      inputStubData_nentries_5_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(4),
      inputStubData_nentries_5_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(5),
      inputStubData_nentries_5_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(6),
      inputStubData_nentries_5_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(5)(7),
      inputStubData_nentries_6_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(0),
      inputStubData_nentries_6_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(1),
      inputStubData_nentries_6_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(2),
      inputStubData_nentries_6_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(3),
      inputStubData_nentries_6_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(4),
      inputStubData_nentries_6_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(5),
      inputStubData_nentries_6_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(6),
      inputStubData_nentries_6_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(6)(7),
      inputStubData_nentries_7_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(0),
      inputStubData_nentries_7_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(1),
      inputStubData_nentries_7_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(2),
      inputStubData_nentries_7_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(3),
      inputStubData_nentries_7_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(4),
      inputStubData_nentries_7_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(5),
      inputStubData_nentries_7_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(6),
      inputStubData_nentries_7_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIC24n1)(7)(7),
      inputProjectionData_dataarray_data_V_ce0       => VMPROJ_24_mem_A_enb(L3PHIC24),
      inputProjectionData_dataarray_data_V_address0  => VMPROJ_24_mem_AV_readaddr(L3PHIC24),
      inputProjectionData_dataarray_data_V_q0        => VMPROJ_24_mem_AV_dout(L3PHIC24),
      inputProjectionData_nentries_0_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC24)(0),
      inputProjectionData_nentries_1_V               => VMPROJ_24_mem_AAV_dout_nent(L3PHIC24)(1),
      outputCandidateMatch_dataarray_data_V_ce0       => open,
      outputCandidateMatch_dataarray_data_V_we0       => CM_14_mem_A_wea(L3PHIC24),
      outputCandidateMatch_dataarray_data_V_address0  => CM_14_mem_AV_writeaddr(L3PHIC24),
      outputCandidateMatch_dataarray_data_V_d0        => CM_14_mem_AV_din(L3PHIC24)
  );

  MC_L3PHIC : entity work.MC_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MC_done,
      bx_V          => ME_bx_out,
      bx_o_V        => MC_bx_out,
      bx_o_V_ap_vld => MC_bx_out_vld,
      match_0_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC17),
      match_0_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC17),
      match_0_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC17),
      match_0_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC17)(0),
      match_0_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC17)(1),
      match_1_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC18),
      match_1_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC18),
      match_1_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC18),
      match_1_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC18)(0),
      match_1_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC18)(1),
      match_2_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC19),
      match_2_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC19),
      match_2_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC19),
      match_2_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC19)(0),
      match_2_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC19)(1),
      match_3_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC20),
      match_3_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC20),
      match_3_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC20),
      match_3_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC20)(0),
      match_3_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC20)(1),
      match_4_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC21),
      match_4_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC21),
      match_4_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC21),
      match_4_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC21)(0),
      match_4_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC21)(1),
      match_5_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC22),
      match_5_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC22),
      match_5_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC22),
      match_5_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC22)(0),
      match_5_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC22)(1),
      match_6_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC23),
      match_6_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC23),
      match_6_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC23),
      match_6_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC23)(0),
      match_6_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC23)(1),
      match_7_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIC24),
      match_7_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIC24),
      match_7_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIC24),
      match_7_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIC24)(0),
      match_7_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIC24)(1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L3PHICn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L3PHICn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L3PHICn1),
      allproj_dataarray_data_V_ce0       => AP_60_mem_A_enb(L3PHIC),
      allproj_dataarray_data_V_address0  => AP_60_mem_AV_readaddr(L3PHIC),
      allproj_dataarray_data_V_q0        => AP_60_mem_AV_dout(L3PHIC),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L3PHIC),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L3PHIC),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L3PHIC),
      fullmatch_3_dataarray_data_V_ce0       => open,
      fullmatch_3_dataarray_data_V_we0       => FM_52_mem_A_wea(L5L6_L3PHIC),
      fullmatch_3_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L5L6_L3PHIC),
      fullmatch_3_dataarray_data_V_d0        => FM_52_mem_AV_din(L5L6_L3PHIC)
  );



end rtl;
