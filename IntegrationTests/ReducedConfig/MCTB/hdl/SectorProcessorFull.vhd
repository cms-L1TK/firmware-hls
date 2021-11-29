--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;

entity SectorProcessorFull is
  port(
    clk        : in std_logic;
    reset      : in std_logic;
    MC_start  : in std_logic;
    MC_bx_in : in std_logic_vector(2 downto 0);
    FT_bx_out : out std_logic_vector(2 downto 0);
    FT_bx_out_vld : out std_logic;
    FT_done   : out std_logic;
    MC_bx_out : out std_logic_vector(2 downto 0);
    MC_bx_out_vld : out std_logic;
    MC_done   : out std_logic;
    AS_36_mem_A_wea        : in t_arr_AS_36_1b;
    AS_36_mem_AV_writeaddr : in t_arr_AS_36_ADDR;
    AS_36_mem_AV_din       : in t_arr_AS_36_DATA;
    TPAR_70_mem_A_wea        : in t_arr_TPAR_70_1b;
    TPAR_70_mem_AV_writeaddr : in t_arr_TPAR_70_ADDR;
    TPAR_70_mem_AV_din       : in t_arr_TPAR_70_DATA;
    AP_60_mem_A_wea        : in t_arr_AP_60_1b;
    AP_60_mem_AV_writeaddr : in t_arr_AP_60_ADDR;
    AP_60_mem_AV_din       : in t_arr_AP_60_DATA;
    AP_58_mem_A_wea        : in t_arr_AP_58_1b;
    AP_58_mem_AV_writeaddr : in t_arr_AP_58_ADDR;
    AP_58_mem_AV_din       : in t_arr_AP_58_DATA;
    CM_14_mem_A_wea        : in t_arr_CM_14_1b;
    CM_14_mem_AV_writeaddr : in t_arr_CM_14_ADDR;
    CM_14_mem_AV_din       : in t_arr_CM_14_DATA;
    FM_52_mem_A_wea        : out t_arr_FM_52_1b;
    FM_52_mem_AV_writeaddr : out t_arr_FM_52_ADDR;
    FM_52_mem_AV_din       : out t_arr_FM_52_DATA;
    BW_46_stream_AV_din       : out t_arr_BW_46_DATA;
    BW_46_stream_A_full_neg   : in t_arr_BW_46_1b;
    BW_46_stream_A_write      : out t_arr_BW_46_1b;
    TW_84_stream_AV_din       : out t_arr_TW_84_DATA;
    TW_84_stream_A_full_neg   : in t_arr_TW_84_1b;
    TW_84_stream_A_write      : out t_arr_TW_84_1b
  );
end SectorProcessorFull;

architecture rtl of SectorProcessorFull is

  signal AS_36_mem_A_enb          : t_arr_AS_36_1b;
  signal AS_36_mem_AV_readaddr    : t_arr_AS_36_ADDR;
  signal AS_36_mem_AV_dout        : t_arr_AS_36_DATA;
  signal TPAR_70_mem_A_enb          : t_arr_TPAR_70_1b;
  signal TPAR_70_mem_AV_readaddr    : t_arr_TPAR_70_ADDR;
  signal TPAR_70_mem_AV_dout        : t_arr_TPAR_70_DATA;
  signal AP_60_mem_A_enb          : t_arr_AP_60_1b;
  signal AP_60_mem_AV_readaddr    : t_arr_AP_60_ADDR;
  signal AP_60_mem_AV_dout        : t_arr_AP_60_DATA;
  signal AP_58_mem_A_enb          : t_arr_AP_58_1b;
  signal AP_58_mem_AV_readaddr    : t_arr_AP_58_ADDR;
  signal AP_58_mem_AV_dout        : t_arr_AP_58_DATA;
  signal CM_14_mem_A_enb          : t_arr_CM_14_1b;
  signal CM_14_mem_AV_readaddr    : t_arr_CM_14_ADDR;
  signal CM_14_mem_AV_dout        : t_arr_CM_14_DATA;
  signal CM_14_mem_AAV_dout_nent  : t_arr_CM_14_NENT; -- (#page)
  signal FM_52_mem_A_enb          : t_arr_FM_52_1b;
  signal FM_52_mem_AV_readaddr    : t_arr_FM_52_ADDR;
  signal FM_52_mem_AV_dout        : t_arr_FM_52_DATA;
  signal FM_52_mem_AAV_dout_nent  : t_arr_FM_52_NENT; -- (#page)
  signal FT_start : std_logic := '0';

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


  TPAR_70_loop : for var in enum_TPAR_70 generate
  begin

    TPAR_70 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 70,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => TPAR_70_mem_A_wea(var),
        addra     => TPAR_70_mem_AV_writeaddr(var),
        dina      => TPAR_70_mem_AV_din(var),
        clkb      => clk,
        enb       => TPAR_70_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => TPAR_70_mem_AV_readaddr(var),
        doutb     => TPAR_70_mem_AV_dout(var),
        sync_nent => FT_start,
        nent_o    => open
      );

  end generate TPAR_70_loop;


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


  AP_58_loop : for var in enum_AP_58 generate
  begin

    AP_58 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => AP_58_mem_A_wea(var),
        addra     => AP_58_mem_AV_writeaddr(var),
        dina      => AP_58_mem_AV_din(var),
        clkb      => clk,
        enb       => AP_58_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => AP_58_mem_AV_readaddr(var),
        doutb     => AP_58_mem_AV_dout(var),
        sync_nent => MC_start,
        nent_o    => open
      );

  end generate AP_58_loop;


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
        sync_nent => FT_start,
        nent_o    => FM_52_mem_AAV_dout_nent(var)
      );

  end generate FM_52_loop;


  FT_start <= '1' when MC_done = '1';

  MC_L3PHIB : entity work.MC_L3PHIB
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MC_done,
      bx_V          => MC_bx_in,
      bx_o_V        => MC_bx_out,
      bx_o_V_ap_vld => MC_bx_out_vld,
      match_0_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB9),
      match_0_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB9),
      match_0_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB9),
      match_0_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB9)(0),
      match_0_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB9)(1),
      match_1_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB10),
      match_1_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB10),
      match_1_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB10),
      match_1_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB10)(0),
      match_1_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB10)(1),
      match_2_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB11),
      match_2_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB11),
      match_2_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB11),
      match_2_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB11)(0),
      match_2_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB11)(1),
      match_3_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB12),
      match_3_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB12),
      match_3_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB12),
      match_3_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB12)(0),
      match_3_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB12)(1),
      match_4_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB13),
      match_4_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB13),
      match_4_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB13),
      match_4_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB13)(0),
      match_4_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB13)(1),
      match_5_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB14),
      match_5_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB14),
      match_5_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB14),
      match_5_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB14)(0),
      match_5_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB14)(1),
      match_6_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB15),
      match_6_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB15),
      match_6_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB15),
      match_6_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB15)(0),
      match_6_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB15)(1),
      match_7_dataarray_data_V_ce0       => CM_14_mem_A_enb(L3PHIB16),
      match_7_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L3PHIB16),
      match_7_dataarray_data_V_q0        => CM_14_mem_AV_dout(L3PHIB16),
      match_7_nentries_0_V               => CM_14_mem_AAV_dout_nent(L3PHIB16)(0),
      match_7_nentries_1_V               => CM_14_mem_AAV_dout_nent(L3PHIB16)(1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L3PHIBn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L3PHIBn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L3PHIBn1),
      allproj_dataarray_data_V_ce0       => AP_60_mem_A_enb(L3PHIB),
      allproj_dataarray_data_V_address0  => AP_60_mem_AV_readaddr(L3PHIB),
      allproj_dataarray_data_V_q0        => AP_60_mem_AV_dout(L3PHIB),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L3PHIB),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L3PHIB),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L3PHIB)
  );

  MC_L4PHIB : entity work.MC_L4PHIB
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MC_bx_in,
      match_0_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB9),
      match_0_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB9),
      match_0_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB9),
      match_0_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB9)(0),
      match_0_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB9)(1),
      match_1_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB10),
      match_1_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB10),
      match_1_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB10),
      match_1_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB10)(0),
      match_1_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB10)(1),
      match_2_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB11),
      match_2_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB11),
      match_2_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB11),
      match_2_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB11)(0),
      match_2_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB11)(1),
      match_3_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB12),
      match_3_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB12),
      match_3_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB12),
      match_3_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB12)(0),
      match_3_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB12)(1),
      match_4_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB13),
      match_4_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB13),
      match_4_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB13),
      match_4_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB13)(0),
      match_4_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB13)(1),
      match_5_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB14),
      match_5_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB14),
      match_5_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB14),
      match_5_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB14)(0),
      match_5_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB14)(1),
      match_6_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB15),
      match_6_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB15),
      match_6_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB15),
      match_6_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB15)(0),
      match_6_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB15)(1),
      match_7_dataarray_data_V_ce0       => CM_14_mem_A_enb(L4PHIB16),
      match_7_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L4PHIB16),
      match_7_dataarray_data_V_q0        => CM_14_mem_AV_dout(L4PHIB16),
      match_7_nentries_0_V               => CM_14_mem_AAV_dout_nent(L4PHIB16)(0),
      match_7_nentries_1_V               => CM_14_mem_AAV_dout_nent(L4PHIB16)(1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L4PHIBn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L4PHIBn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L4PHIBn1),
      allproj_dataarray_data_V_ce0       => AP_58_mem_A_enb(L4PHIB),
      allproj_dataarray_data_V_address0  => AP_58_mem_AV_readaddr(L4PHIB),
      allproj_dataarray_data_V_q0        => AP_58_mem_AV_dout(L4PHIB),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L4PHIB),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L4PHIB),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L4PHIB)
  );

  MC_L5PHIB : entity work.MC_L5PHIB
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MC_bx_in,
      match_0_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB9),
      match_0_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB9),
      match_0_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB9),
      match_0_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB9)(0),
      match_0_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB9)(1),
      match_1_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB10),
      match_1_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB10),
      match_1_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB10),
      match_1_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB10)(0),
      match_1_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB10)(1),
      match_2_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB11),
      match_2_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB11),
      match_2_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB11),
      match_2_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB11)(0),
      match_2_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB11)(1),
      match_3_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB12),
      match_3_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB12),
      match_3_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB12),
      match_3_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB12)(0),
      match_3_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB12)(1),
      match_4_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB13),
      match_4_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB13),
      match_4_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB13),
      match_4_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB13)(0),
      match_4_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB13)(1),
      match_5_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB14),
      match_5_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB14),
      match_5_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB14),
      match_5_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB14)(0),
      match_5_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB14)(1),
      match_6_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB15),
      match_6_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB15),
      match_6_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB15),
      match_6_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB15)(0),
      match_6_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB15)(1),
      match_7_dataarray_data_V_ce0       => CM_14_mem_A_enb(L5PHIB16),
      match_7_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L5PHIB16),
      match_7_dataarray_data_V_q0        => CM_14_mem_AV_dout(L5PHIB16),
      match_7_nentries_0_V               => CM_14_mem_AAV_dout_nent(L5PHIB16)(0),
      match_7_nentries_1_V               => CM_14_mem_AAV_dout_nent(L5PHIB16)(1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L5PHIBn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L5PHIBn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L5PHIBn1),
      allproj_dataarray_data_V_ce0       => AP_58_mem_A_enb(L5PHIB),
      allproj_dataarray_data_V_address0  => AP_58_mem_AV_readaddr(L5PHIB),
      allproj_dataarray_data_V_q0        => AP_58_mem_AV_dout(L5PHIB),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L5PHIB),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L5PHIB),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L5PHIB)
  );

  MC_L6PHIB : entity work.MC_L6PHIB
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MC_bx_in,
      match_0_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB9),
      match_0_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB9),
      match_0_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB9),
      match_0_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB9)(0),
      match_0_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB9)(1),
      match_1_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB10),
      match_1_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB10),
      match_1_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB10),
      match_1_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB10)(0),
      match_1_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB10)(1),
      match_2_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB11),
      match_2_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB11),
      match_2_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB11),
      match_2_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB11)(0),
      match_2_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB11)(1),
      match_3_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB12),
      match_3_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB12),
      match_3_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB12),
      match_3_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB12)(0),
      match_3_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB12)(1),
      match_4_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB13),
      match_4_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB13),
      match_4_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB13),
      match_4_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB13)(0),
      match_4_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB13)(1),
      match_5_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB14),
      match_5_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB14),
      match_5_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB14),
      match_5_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB14)(0),
      match_5_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB14)(1),
      match_6_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB15),
      match_6_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB15),
      match_6_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB15),
      match_6_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB15)(0),
      match_6_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB15)(1),
      match_7_dataarray_data_V_ce0       => CM_14_mem_A_enb(L6PHIB16),
      match_7_dataarray_data_V_address0  => CM_14_mem_AV_readaddr(L6PHIB16),
      match_7_dataarray_data_V_q0        => CM_14_mem_AV_dout(L6PHIB16),
      match_7_nentries_0_V               => CM_14_mem_AAV_dout_nent(L6PHIB16)(0),
      match_7_nentries_1_V               => CM_14_mem_AAV_dout_nent(L6PHIB16)(1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L6PHIBn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L6PHIBn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L6PHIBn1),
      allproj_dataarray_data_V_ce0       => AP_58_mem_A_enb(L6PHIB),
      allproj_dataarray_data_V_address0  => AP_58_mem_AV_readaddr(L6PHIB),
      allproj_dataarray_data_V_q0        => AP_58_mem_AV_dout(L6PHIB),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L6PHIB),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L6PHIB),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L6PHIB)
  );

  FT_L1L2 : entity work.FT_L1L2
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => FT_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => FT_done,
      bx_V          => MC_bx_out,
      bx_o_V        => FT_bx_out,
      bx_o_V_ap_vld => FT_bx_out_vld,
      trackletParameters_0_dataarray_data_V_ce0       => TPAR_70_mem_A_enb(L1L2F),
      trackletParameters_0_dataarray_data_V_address0  => TPAR_70_mem_AV_readaddr(L1L2F),
      trackletParameters_0_dataarray_data_V_q0        => TPAR_70_mem_AV_dout(L1L2F),
      barrelFullMatches_0_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L3PHIB),
      barrelFullMatches_0_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L3PHIB),
      barrelFullMatches_0_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L3PHIB),
      barrelFullMatches_0_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L3PHIB)(0),
      barrelFullMatches_0_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L3PHIB)(1),
      barrelFullMatches_1_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L4PHIB),
      barrelFullMatches_1_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L4PHIB),
      barrelFullMatches_1_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L4PHIB),
      barrelFullMatches_1_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L4PHIB)(0),
      barrelFullMatches_1_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L4PHIB)(1),
      barrelFullMatches_2_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L5PHIB),
      barrelFullMatches_2_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L5PHIB),
      barrelFullMatches_2_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L5PHIB),
      barrelFullMatches_2_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L5PHIB)(0),
      barrelFullMatches_2_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L5PHIB)(1),
      barrelFullMatches_3_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L6PHIB),
      barrelFullMatches_3_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L6PHIB),
      barrelFullMatches_3_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L6PHIB),
      barrelFullMatches_3_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L6PHIB)(0),
      barrelFullMatches_3_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L6PHIB)(1),
      trackWord_V_din       => TW_84_stream_AV_din(L1L2),
      trackWord_V_full_n    => TW_84_stream_A_full_neg(L1L2),
      trackWord_V_write     => TW_84_stream_A_write(L1L2),
      barrelStubWords_0_V_din       => BW_46_stream_AV_din(L1L2_L3),
      barrelStubWords_0_V_full_n    => BW_46_stream_A_full_neg(L1L2_L3),
      barrelStubWords_0_V_write     => BW_46_stream_A_write(L1L2_L3),
      barrelStubWords_1_V_din       => BW_46_stream_AV_din(L1L2_L4),
      barrelStubWords_1_V_full_n    => BW_46_stream_A_full_neg(L1L2_L4),
      barrelStubWords_1_V_write     => BW_46_stream_A_write(L1L2_L4),
      barrelStubWords_2_V_din       => BW_46_stream_AV_din(L1L2_L5),
      barrelStubWords_2_V_full_n    => BW_46_stream_A_full_neg(L1L2_L5),
      barrelStubWords_2_V_write     => BW_46_stream_A_write(L1L2_L5),
      barrelStubWords_3_V_din       => BW_46_stream_AV_din(L1L2_L6),
      barrelStubWords_3_V_full_n    => BW_46_stream_A_full_neg(L1L2_L6),
      barrelStubWords_3_V_write     => BW_46_stream_A_write(L1L2_L6)
  );



end rtl;
