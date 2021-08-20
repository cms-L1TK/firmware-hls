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
    IR_start  : in std_logic;
    IR_bx_in : in std_logic_vector(2 downto 0);
    VMR_bx_out : out std_logic_vector(2 downto 0);
    VMR_bx_out_vld : out std_logic;
    VMR_done   : out std_logic;
    DL_39_link_AV_dout       : in t_arr_DL_39_DATA;
    DL_39_link_empty_neg     : in t_arr_DL_39_1b;
    DL_39_link_read          : out t_arr_DL_39_1b;
    AS_36_mem_A_enb          : in t_arr_AS_36_1b;
    AS_36_mem_AV_readaddr    : in t_arr_AS_36_ADDR;
    AS_36_mem_AV_dout        : out t_arr_AS_36_DATA;
    AS_36_mem_AAV_dout_nent  : out t_arr_AS_36_NENT;
    VMSME_16_mem_A_enb          : in t_arr_VMSME_16_1b;
    VMSME_16_mem_AV_readaddr    : in t_arr_VMSME_16_ADDR;
    VMSME_16_mem_AV_dout        : out t_arr_VMSME_16_DATA;
    VMSME_16_mem_AAAV_dout_nent : out t_arr_VMSME_16_NENT;
    VMSTE_16_mem_A_enb          : in t_arr_VMSTE_16_1b;
    VMSTE_16_mem_AV_readaddr    : in t_arr_VMSTE_16_ADDR;
    VMSTE_16_mem_AV_dout        : out t_arr_VMSTE_16_DATA;
    VMSTE_16_mem_AAAV_dout_nent : out t_arr_VMSTE_16_NENT;
    VMSTE_22_mem_A_enb          : in t_arr_VMSTE_22_1b;
    VMSTE_22_mem_AV_readaddr    : in t_arr_VMSTE_22_ADDR;
    VMSTE_22_mem_AV_dout        : out t_arr_VMSTE_22_DATA;
    VMSTE_22_mem_AAV_dout_nent  : out t_arr_VMSTE_22_NENT
  );
end SectorProcessor;

architecture rtl of SectorProcessor is

  signal IL_36_mem_A_wea          : t_arr_IL_36_1b;
  signal IL_36_mem_AV_writeaddr   : t_arr_IL_36_ADDR;
  signal IL_36_mem_AV_din         : t_arr_IL_36_DATA;
  signal IL_36_mem_A_enb          : t_arr_IL_36_1b;
  signal IL_36_mem_AV_readaddr    : t_arr_IL_36_ADDR;
  signal IL_36_mem_AV_dout        : t_arr_IL_36_DATA;
  signal IL_36_mem_AAV_dout_nent  : t_arr_IL_36_NENT; -- (#page)
  signal AS_36_mem_A_wea          : t_arr_AS_36_1b;
  signal AS_36_mem_AV_writeaddr   : t_arr_AS_36_ADDR;
  signal AS_36_mem_AV_din         : t_arr_AS_36_DATA;
  signal VMSME_16_mem_A_wea          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem_AV_writeaddr   : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem_AV_din         : t_arr_VMSME_16_DATA;
  signal VMSTE_16_mem_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_22_mem_A_wea          : t_arr_VMSTE_22_1b;
  signal VMSTE_22_mem_AV_writeaddr   : t_arr_VMSTE_22_ADDR;
  signal VMSTE_22_mem_AV_din         : t_arr_VMSTE_22_DATA;
  signal IR_done : std_logic := '0';
  signal IR_bx_out : std_logic_vector(2 downto 0);
  signal IR_bx_out_vld : std_logic;
  signal VMR_start : std_logic := '0';

begin

  IL_36_loop : for var in enum_IL_36 generate
  begin

    IL_36 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => IL_36_mem_A_wea(var),
        addra     => IL_36_mem_AV_writeaddr(var),
        dina      => IL_36_mem_AV_din(var),
        clkb      => clk,
        enb       => IL_36_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => IL_36_mem_AV_readaddr(var),
        doutb     => IL_36_mem_AV_dout(var),
        sync_nent => VMR_start,
        nent_o    => IL_36_mem_AAV_dout_nent(var)
      );

  end generate IL_36_loop;


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
        sync_nent => VMR_done,
        nent_o    => AS_36_mem_AAV_dout_nent(var)
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
        sync_nent => VMR_done,
        nent_o    => VMSME_16_mem_AAAV_dout_nent(var)
      );

  end generate VMSME_16_loop;


  VMSTE_16_loop : for var in enum_VMSTE_16 generate
  begin

    VMSTE_16 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => VMSTE_16_mem_A_wea(var),
        addra     => VMSTE_16_mem_AV_writeaddr(var),
        dina      => VMSTE_16_mem_AV_din(var),
        clkb      => clk,
        enb       => VMSTE_16_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => VMSTE_16_mem_AV_readaddr(var),
        doutb     => VMSTE_16_mem_AV_dout(var),
        sync_nent => VMR_done,
        nent_o    => VMSTE_16_mem_AAAV_dout_nent(var)
      );

  end generate VMSTE_16_loop;


  VMSTE_22_loop : for var in enum_VMSTE_22 generate
  begin

    VMSTE_22 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 22,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea       => VMSTE_22_mem_A_wea(var),
        addra     => VMSTE_22_mem_AV_writeaddr(var),
        dina      => VMSTE_22_mem_AV_din(var),
        clkb      => clk,
        enb       => VMSTE_22_mem_A_enb(var),
        rstb      => '0',
        regceb    => '1',
        addrb     => VMSTE_22_mem_AV_readaddr(var),
        doutb     => VMSTE_22_mem_AV_dout(var),
        sync_nent => VMR_done,
        nent_o    => VMSTE_22_mem_AAV_dout_nent(var)
      );

  end generate VMSTE_22_loop;


  VMR_start <= '1' when IR_done = '1';

  IR_PS10G_3_A : entity work.IR_PS10G_3_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => IR_done,
      bx_V          => IR_bx_in,
      bx_o_V        => IR_bx_out,
      bx_o_V_ap_vld => IR_bx_out_vld,
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS10G_3_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS10G_3_A),
      hInputStubs_V_read     => DL_39_link_read(PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIA_PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIA_PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIA_PS10G_3_A),
      hOutputStubs_1_dataarray_data_V_ce0       => open,
      hOutputStubs_1_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIB_PS10G_3_A),
      hOutputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIB_PS10G_3_A),
      hOutputStubs_1_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIB_PS10G_3_A),
      hOutputStubs_2_dataarray_data_V_ce0       => open,
      hOutputStubs_2_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIC_PS10G_3_A),
      hOutputStubs_2_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIC_PS10G_3_A),
      hOutputStubs_2_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIC_PS10G_3_A),
      hOutputStubs_3_dataarray_data_V_ce0       => open,
      hOutputStubs_3_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIA_PS10G_3_A),
      hOutputStubs_3_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIA_PS10G_3_A),
      hOutputStubs_3_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIA_PS10G_3_A),
      hOutputStubs_4_dataarray_data_V_ce0       => open,
      hOutputStubs_4_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIB_PS10G_3_A),
      hOutputStubs_4_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIB_PS10G_3_A),
      hOutputStubs_4_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIB_PS10G_3_A),
      hOutputStubs_5_dataarray_data_V_ce0       => open,
      hOutputStubs_5_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIC_PS10G_3_A),
      hOutputStubs_5_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIC_PS10G_3_A),
      hOutputStubs_5_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIC_PS10G_3_A),
      hOutputStubs_6_dataarray_data_V_ce0       => open,
      hOutputStubs_6_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHID_PS10G_3_A),
      hOutputStubs_6_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHID_PS10G_3_A),
      hOutputStubs_6_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHID_PS10G_3_A),
      hLinkWord_V => "01000000000001000101",
      hPhBnWord_V => "000000011010"
  );

  IR_negPS10G_3_A : entity work.IR_negPS10G_3_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(negPS10G_3_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(negPS10G_3_A),
      hInputStubs_V_read     => DL_39_link_read(negPS10G_3_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIA_negPS10G_3_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIA_negPS10G_3_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIA_negPS10G_3_A),
      hOutputStubs_1_dataarray_data_V_ce0       => open,
      hOutputStubs_1_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIB_negPS10G_3_A),
      hOutputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIB_negPS10G_3_A),
      hOutputStubs_1_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIB_negPS10G_3_A),
      hOutputStubs_2_dataarray_data_V_ce0       => open,
      hOutputStubs_2_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIC_negPS10G_3_A),
      hOutputStubs_2_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIC_negPS10G_3_A),
      hOutputStubs_2_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIC_negPS10G_3_A),
      hOutputStubs_3_dataarray_data_V_ce0       => open,
      hOutputStubs_3_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIA_negPS10G_3_A),
      hOutputStubs_3_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIA_negPS10G_3_A),
      hOutputStubs_3_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIA_negPS10G_3_A),
      hOutputStubs_4_dataarray_data_V_ce0       => open,
      hOutputStubs_4_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIB_negPS10G_3_A),
      hOutputStubs_4_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIB_negPS10G_3_A),
      hOutputStubs_4_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIB_negPS10G_3_A),
      hOutputStubs_5_dataarray_data_V_ce0       => open,
      hOutputStubs_5_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHIC_negPS10G_3_A),
      hOutputStubs_5_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHIC_negPS10G_3_A),
      hOutputStubs_5_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHIC_negPS10G_3_A),
      hOutputStubs_6_dataarray_data_V_ce0       => open,
      hOutputStubs_6_dataarray_data_V_we0       => IL_36_mem_A_wea(D2PHID_negPS10G_3_A),
      hOutputStubs_6_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(D2PHID_negPS10G_3_A),
      hOutputStubs_6_dataarray_data_V_d0        => IL_36_mem_AV_din(D2PHID_negPS10G_3_A),
      hLinkWord_V => "01000000000001000101",
      hPhBnWord_V => "000000011010"
  );

  VMR_L2PHIA : entity work.VMR_L2PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => VMR_done,
      bx_V          => IR_bx_out,
      bx_o_V        => VMR_bx_out,
      bx_o_V_ap_vld => VMR_bx_out_vld,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L2PHIA_PS10G_3_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L2PHIA_PS10G_3_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L2PHIA_PS10G_3_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L2PHIA_PS10G_3_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L2PHIA_PS10G_3_A)(1),
      inputStubs_1_dataarray_data_V_ce0       => IL_36_mem_A_enb(L2PHIA_negPS10G_3_A),
      inputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L2PHIA_negPS10G_3_A),
      inputStubs_1_dataarray_data_V_q0        => IL_36_mem_AV_dout(L2PHIA_negPS10G_3_A),
      inputStubs_1_nentries_0_V               => IL_36_mem_AAV_dout_nent(L2PHIA_negPS10G_3_A)(0),
      inputStubs_1_nentries_1_V               => IL_36_mem_AAV_dout_nent(L2PHIA_negPS10G_3_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn1),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn1),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn1),
      memoriesAS_1_dataarray_data_V_ce0       => open,
      memoriesAS_1_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn2),
      memoriesAS_1_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn2),
      memoriesAS_1_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn2),
      memoriesAS_2_dataarray_data_V_ce0       => open,
      memoriesAS_2_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn3),
      memoriesAS_2_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn3),
      memoriesAS_2_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn3),
      memoriesAS_3_dataarray_data_V_ce0       => open,
      memoriesAS_3_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn4),
      memoriesAS_3_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn4),
      memoriesAS_3_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn4),
      memoriesAS_4_dataarray_data_V_ce0       => open,
      memoriesAS_4_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn5),
      memoriesAS_4_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn5),
      memoriesAS_4_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn5),
      memoriesAS_5_dataarray_data_V_ce0       => open,
      memoriesAS_5_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn6),
      memoriesAS_5_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn6),
      memoriesAS_5_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn6),
      memoriesAS_6_dataarray_data_V_ce0       => open,
      memoriesAS_6_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIAn7),
      memoriesAS_6_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIAn7),
      memoriesAS_6_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIAn7),
      memoriesME_0_dataarray_data_V_ce0       => open,
      memoriesME_0_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA1n1),
      memoriesME_0_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA1n1),
      memoriesME_0_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA1n1),
      memoriesME_1_dataarray_data_V_ce0       => open,
      memoriesME_1_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA2n1),
      memoriesME_1_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA2n1),
      memoriesME_1_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA2n1),
      memoriesME_2_dataarray_data_V_ce0       => open,
      memoriesME_2_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA3n1),
      memoriesME_2_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA3n1),
      memoriesME_2_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA3n1),
      memoriesME_3_dataarray_data_V_ce0       => open,
      memoriesME_3_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA4n1),
      memoriesME_3_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA4n1),
      memoriesME_3_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA4n1),
      memoriesME_4_dataarray_data_V_ce0       => open,
      memoriesME_4_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA5n1),
      memoriesME_4_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA5n1),
      memoriesME_4_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA5n1),
      memoriesME_5_dataarray_data_V_ce0       => open,
      memoriesME_5_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA6n1),
      memoriesME_5_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA6n1),
      memoriesME_5_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA6n1),
      memoriesME_6_dataarray_data_V_ce0       => open,
      memoriesME_6_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA7n1),
      memoriesME_6_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA7n1),
      memoriesME_6_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA7n1),
      memoriesME_7_dataarray_data_V_ce0       => open,
      memoriesME_7_dataarray_data_V_we0       => VMSME_16_mem_A_wea(L2PHIA8n1),
      memoriesME_7_dataarray_data_V_address0  => VMSME_16_mem_AV_writeaddr(L2PHIA8n1),
      memoriesME_7_dataarray_data_V_d0        => VMSME_16_mem_AV_din(L2PHIA8n1),
      memoriesTEI_0_0_dataarray_data_V_ce0       => open,
      memoriesTEI_0_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII1n1),
      memoriesTEI_0_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII1n1),
      memoriesTEI_0_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII1n1),
      memoriesTEI_0_1_dataarray_data_V_ce0       => open,
      memoriesTEI_0_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII1n2),
      memoriesTEI_0_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII1n2),
      memoriesTEI_0_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII1n2),
      memoriesTEI_1_0_dataarray_data_V_ce0       => open,
      memoriesTEI_1_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII2n1),
      memoriesTEI_1_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII2n1),
      memoriesTEI_1_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII2n1),
      memoriesTEI_1_1_dataarray_data_V_ce0       => open,
      memoriesTEI_1_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII2n2),
      memoriesTEI_1_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII2n2),
      memoriesTEI_1_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII2n2),
      memoriesTEI_1_2_dataarray_data_V_ce0       => open,
      memoriesTEI_1_2_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII2n3),
      memoriesTEI_1_2_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII2n3),
      memoriesTEI_1_2_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII2n3),
      memoriesTEI_2_0_dataarray_data_V_ce0       => open,
      memoriesTEI_2_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII3n1),
      memoriesTEI_2_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII3n1),
      memoriesTEI_2_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII3n1),
      memoriesTEI_2_1_dataarray_data_V_ce0       => open,
      memoriesTEI_2_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII3n2),
      memoriesTEI_2_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII3n2),
      memoriesTEI_2_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII3n2),
      memoriesTEI_2_2_dataarray_data_V_ce0       => open,
      memoriesTEI_2_2_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII3n3),
      memoriesTEI_2_2_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII3n3),
      memoriesTEI_2_2_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII3n3),
      memoriesTEI_3_0_dataarray_data_V_ce0       => open,
      memoriesTEI_3_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII4n1),
      memoriesTEI_3_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII4n1),
      memoriesTEI_3_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII4n1),
      memoriesTEI_3_1_dataarray_data_V_ce0       => open,
      memoriesTEI_3_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII4n2),
      memoriesTEI_3_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII4n2),
      memoriesTEI_3_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII4n2),
      memoriesTEI_3_2_dataarray_data_V_ce0       => open,
      memoriesTEI_3_2_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHII4n3),
      memoriesTEI_3_2_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHII4n3),
      memoriesTEI_3_2_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHII4n3),
      memoriesOL_0_0_dataarray_data_V_ce0       => open,
      memoriesOL_0_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX1n5),
      memoriesOL_0_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX1n5),
      memoriesOL_0_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX1n5),
      memoriesOL_0_1_dataarray_data_V_ce0       => open,
      memoriesOL_0_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX1n6),
      memoriesOL_0_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX1n6),
      memoriesOL_0_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX1n6),
      memoriesOL_0_2_dataarray_data_V_ce0       => open,
      memoriesOL_0_2_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX1n7),
      memoriesOL_0_2_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX1n7),
      memoriesOL_0_2_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX1n7),
      memoriesOL_1_0_dataarray_data_V_ce0       => open,
      memoriesOL_1_0_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX2n5),
      memoriesOL_1_0_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX2n5),
      memoriesOL_1_0_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX2n5),
      memoriesOL_1_1_dataarray_data_V_ce0       => open,
      memoriesOL_1_1_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX2n6),
      memoriesOL_1_1_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX2n6),
      memoriesOL_1_1_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX2n6),
      memoriesOL_1_2_dataarray_data_V_ce0       => open,
      memoriesOL_1_2_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX2n7),
      memoriesOL_1_2_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX2n7),
      memoriesOL_1_2_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX2n7),
      memoriesOL_1_3_dataarray_data_V_ce0       => open,
      memoriesOL_1_3_dataarray_data_V_we0       => VMSTE_22_mem_A_wea(L2PHIX2n8),
      memoriesOL_1_3_dataarray_data_V_address0  => VMSTE_22_mem_AV_writeaddr(L2PHIX2n8),
      memoriesOL_1_3_dataarray_data_V_d0        => VMSTE_22_mem_AV_din(L2PHIX2n8),
      memoriesTEO_0_0_dataarray_data_V_ce0       => open,
      memoriesTEO_0_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA1n1),
      memoriesTEO_0_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA1n1),
      memoriesTEO_0_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA1n1),
      memoriesTEO_0_1_dataarray_data_V_ce0       => open,
      memoriesTEO_0_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA1n2),
      memoriesTEO_0_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA1n2),
      memoriesTEO_0_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA1n2),
      memoriesTEO_0_2_dataarray_data_V_ce0       => open,
      memoriesTEO_0_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA1n3),
      memoriesTEO_0_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA1n3),
      memoriesTEO_0_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA1n3),
      memoriesTEO_1_0_dataarray_data_V_ce0       => open,
      memoriesTEO_1_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA2n1),
      memoriesTEO_1_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA2n1),
      memoriesTEO_1_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA2n1),
      memoriesTEO_1_1_dataarray_data_V_ce0       => open,
      memoriesTEO_1_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA2n2),
      memoriesTEO_1_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA2n2),
      memoriesTEO_1_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA2n2),
      memoriesTEO_1_2_dataarray_data_V_ce0       => open,
      memoriesTEO_1_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA2n3),
      memoriesTEO_1_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA2n3),
      memoriesTEO_1_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA2n3),
      memoriesTEO_1_3_dataarray_data_V_ce0       => open,
      memoriesTEO_1_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA2n4),
      memoriesTEO_1_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA2n4),
      memoriesTEO_1_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA2n4),
      memoriesTEO_2_0_dataarray_data_V_ce0       => open,
      memoriesTEO_2_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA3n1),
      memoriesTEO_2_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA3n1),
      memoriesTEO_2_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA3n1),
      memoriesTEO_2_1_dataarray_data_V_ce0       => open,
      memoriesTEO_2_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA3n2),
      memoriesTEO_2_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA3n2),
      memoriesTEO_2_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA3n2),
      memoriesTEO_2_2_dataarray_data_V_ce0       => open,
      memoriesTEO_2_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA3n3),
      memoriesTEO_2_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA3n3),
      memoriesTEO_2_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA3n3),
      memoriesTEO_2_3_dataarray_data_V_ce0       => open,
      memoriesTEO_2_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA3n4),
      memoriesTEO_2_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA3n4),
      memoriesTEO_2_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA3n4),
      memoriesTEO_2_4_dataarray_data_V_ce0       => open,
      memoriesTEO_2_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA3n5),
      memoriesTEO_2_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA3n5),
      memoriesTEO_2_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA3n5),
      memoriesTEO_3_0_dataarray_data_V_ce0       => open,
      memoriesTEO_3_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA4n1),
      memoriesTEO_3_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA4n1),
      memoriesTEO_3_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA4n1),
      memoriesTEO_3_1_dataarray_data_V_ce0       => open,
      memoriesTEO_3_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA4n2),
      memoriesTEO_3_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA4n2),
      memoriesTEO_3_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA4n2),
      memoriesTEO_3_2_dataarray_data_V_ce0       => open,
      memoriesTEO_3_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA4n3),
      memoriesTEO_3_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA4n3),
      memoriesTEO_3_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA4n3),
      memoriesTEO_3_3_dataarray_data_V_ce0       => open,
      memoriesTEO_3_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA4n4),
      memoriesTEO_3_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA4n4),
      memoriesTEO_3_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA4n4),
      memoriesTEO_3_4_dataarray_data_V_ce0       => open,
      memoriesTEO_3_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA4n5),
      memoriesTEO_3_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA4n5),
      memoriesTEO_3_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA4n5),
      memoriesTEO_4_0_dataarray_data_V_ce0       => open,
      memoriesTEO_4_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA5n1),
      memoriesTEO_4_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA5n1),
      memoriesTEO_4_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA5n1),
      memoriesTEO_4_1_dataarray_data_V_ce0       => open,
      memoriesTEO_4_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA5n2),
      memoriesTEO_4_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA5n2),
      memoriesTEO_4_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA5n2),
      memoriesTEO_4_2_dataarray_data_V_ce0       => open,
      memoriesTEO_4_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA5n3),
      memoriesTEO_4_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA5n3),
      memoriesTEO_4_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA5n3),
      memoriesTEO_4_3_dataarray_data_V_ce0       => open,
      memoriesTEO_4_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA5n4),
      memoriesTEO_4_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA5n4),
      memoriesTEO_4_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA5n4),
      memoriesTEO_4_4_dataarray_data_V_ce0       => open,
      memoriesTEO_4_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA5n5),
      memoriesTEO_4_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA5n5),
      memoriesTEO_4_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA5n5),
      memoriesTEO_5_0_dataarray_data_V_ce0       => open,
      memoriesTEO_5_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA6n1),
      memoriesTEO_5_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA6n1),
      memoriesTEO_5_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA6n1),
      memoriesTEO_5_1_dataarray_data_V_ce0       => open,
      memoriesTEO_5_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA6n2),
      memoriesTEO_5_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA6n2),
      memoriesTEO_5_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA6n2),
      memoriesTEO_5_2_dataarray_data_V_ce0       => open,
      memoriesTEO_5_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA6n3),
      memoriesTEO_5_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA6n3),
      memoriesTEO_5_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA6n3),
      memoriesTEO_5_3_dataarray_data_V_ce0       => open,
      memoriesTEO_5_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA6n4),
      memoriesTEO_5_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA6n4),
      memoriesTEO_5_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA6n4),
      memoriesTEO_5_4_dataarray_data_V_ce0       => open,
      memoriesTEO_5_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA6n5),
      memoriesTEO_5_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA6n5),
      memoriesTEO_5_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA6n5),
      memoriesTEO_6_0_dataarray_data_V_ce0       => open,
      memoriesTEO_6_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA7n1),
      memoriesTEO_6_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA7n1),
      memoriesTEO_6_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA7n1),
      memoriesTEO_6_1_dataarray_data_V_ce0       => open,
      memoriesTEO_6_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA7n2),
      memoriesTEO_6_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA7n2),
      memoriesTEO_6_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA7n2),
      memoriesTEO_6_2_dataarray_data_V_ce0       => open,
      memoriesTEO_6_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA7n3),
      memoriesTEO_6_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA7n3),
      memoriesTEO_6_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA7n3),
      memoriesTEO_6_3_dataarray_data_V_ce0       => open,
      memoriesTEO_6_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA7n4),
      memoriesTEO_6_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA7n4),
      memoriesTEO_6_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA7n4),
      memoriesTEO_6_4_dataarray_data_V_ce0       => open,
      memoriesTEO_6_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA7n5),
      memoriesTEO_6_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA7n5),
      memoriesTEO_6_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA7n5),
      memoriesTEO_7_0_dataarray_data_V_ce0       => open,
      memoriesTEO_7_0_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA8n1),
      memoriesTEO_7_0_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA8n1),
      memoriesTEO_7_0_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA8n1),
      memoriesTEO_7_1_dataarray_data_V_ce0       => open,
      memoriesTEO_7_1_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA8n2),
      memoriesTEO_7_1_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA8n2),
      memoriesTEO_7_1_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA8n2),
      memoriesTEO_7_2_dataarray_data_V_ce0       => open,
      memoriesTEO_7_2_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA8n3),
      memoriesTEO_7_2_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA8n3),
      memoriesTEO_7_2_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA8n3),
      memoriesTEO_7_3_dataarray_data_V_ce0       => open,
      memoriesTEO_7_3_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA8n4),
      memoriesTEO_7_3_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA8n4),
      memoriesTEO_7_3_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA8n4),
      memoriesTEO_7_4_dataarray_data_V_ce0       => open,
      memoriesTEO_7_4_dataarray_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIA8n5),
      memoriesTEO_7_4_dataarray_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIA8n5),
      memoriesTEO_7_4_dataarray_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIA8n5)
  );



end rtl;
