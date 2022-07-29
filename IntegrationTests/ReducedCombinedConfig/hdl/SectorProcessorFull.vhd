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
    IR_start  : in std_logic;
    IR_bx_in : in std_logic_vector(2 downto 0);
    FT_bx_out : out std_logic_vector(2 downto 0);
    FT_bx_out_vld : out std_logic;
    FT_done   : out std_logic;
    IR_bx_out : out std_logic_vector(2 downto 0);
    IR_bx_out_vld : out std_logic;
    IR_done   : out std_logic;
    VMR_bx_out : out std_logic_vector(2 downto 0);
    VMR_bx_out_vld : out std_logic;
    VMR_done   : out std_logic;
    TP_bx_out : out std_logic_vector(2 downto 0);
    TP_bx_out_vld : out std_logic;
    TP_done   : out std_logic;
    MP_bx_out : out std_logic_vector(2 downto 0);
    MP_bx_out_vld : out std_logic;
    MP_done   : out std_logic;
    DL_39_link_AV_dout       : in t_arr_DL_39_DATA;
    DL_39_link_empty_neg     : in t_arr_DL_39_1b;
    DL_39_link_read          : out t_arr_DL_39_1b;
    IL_36_mem_A_wea        : out t_arr_IL_36_1b;
    IL_36_mem_AV_writeaddr : out t_arr_IL_36_ADDR;
    IL_36_mem_AV_din       : out t_arr_IL_36_DATA;
    AS_36_mem_A_wea        : out t_arr_AS_36_1b;
    AS_36_mem_AV_writeaddr : out t_arr_AS_36_ADDR;
    AS_36_mem_AV_din       : out t_arr_AS_36_DATA;
    AS_51_mem_A_wea        : out t_arr_AS_51_1b;
    AS_51_mem_AV_writeaddr : out t_arr_AS_51_ADDR;
    AS_51_mem_AV_din       : out t_arr_AS_51_DATA;
    VMSME_16_mem_A_wea        : out t_arr_VMSME_16_1b;
    VMSME_16_mem_AV_writeaddr : out t_arr_VMSME_16_ADDR;
    VMSME_16_mem_AV_din       : out t_arr_VMSME_16_DATA;
    VMSME_17_mem_A_wea        : out t_arr_VMSME_17_1b;
    VMSME_17_mem_AV_writeaddr : out t_arr_VMSME_17_ADDR;
    VMSME_17_mem_AV_din       : out t_arr_VMSME_17_DATA;
    VMSTE_16_mem_A_wea        : out t_arr_VMSTE_16_1b;
    VMSTE_16_mem_AV_writeaddr : out t_arr_VMSTE_16_ADDR;
    VMSTE_16_mem_AV_din       : out t_arr_VMSTE_16_DATA;
    TPROJ_60_mem_A_wea        : out t_arr_TPROJ_60_1b;
    TPROJ_60_mem_AV_writeaddr : out t_arr_TPROJ_60_ADDR;
    TPROJ_60_mem_AV_din       : out t_arr_TPROJ_60_DATA;
    TPROJ_58_mem_A_wea        : out t_arr_TPROJ_58_1b;
    TPROJ_58_mem_AV_writeaddr : out t_arr_TPROJ_58_ADDR;
    TPROJ_58_mem_AV_din       : out t_arr_TPROJ_58_DATA;
    TPAR_70_mem_A_wea        : out t_arr_TPAR_70_1b;
    TPAR_70_mem_AV_writeaddr : out t_arr_TPAR_70_ADDR;
    TPAR_70_mem_AV_din       : out t_arr_TPAR_70_DATA;
    FM_52_mem_A_wea        : out t_arr_FM_52_1b;
    FM_52_mem_AV_writeaddr : out t_arr_FM_52_ADDR;
    FM_52_mem_AV_din       : out t_arr_FM_52_DATA;
    TW_84_stream_AV_din       : out t_arr_TW_84_DATA;
    TW_84_stream_A_full_neg   : in t_arr_TW_84_1b;
    TW_84_stream_A_write      : out t_arr_TW_84_1b;
    BW_46_stream_AV_din       : out t_arr_BW_46_DATA;
    BW_46_stream_A_full_neg   : in t_arr_BW_46_1b;
    BW_46_stream_A_write      : out t_arr_BW_46_1b
  );
end SectorProcessorFull;

architecture rtl of SectorProcessorFull is

  signal IL_36_mem_A_enb          : t_arr_IL_36_1b;
  signal IL_36_mem_AV_readaddr    : t_arr_IL_36_ADDR;
  signal IL_36_mem_AV_dout        : t_arr_IL_36_DATA;
  signal IL_36_mem_AAV_dout_nent  : t_arr_IL_36_NENT; -- (#page)
  signal AS_36_mem_A_enb          : t_arr_AS_36_1b;
  signal AS_36_mem_AV_readaddr    : t_arr_AS_36_ADDR;
  signal AS_36_mem_AV_dout        : t_arr_AS_36_DATA;
  signal AS_51_mem_A_enb          : t_arr_AS_51_1b;
  signal AS_51_mem_AV_readaddr    : t_arr_AS_51_ADDR;
  signal AS_51_mem_AV_dout        : t_arr_AS_51_DATA;
  signal AS_51_mem_AAV_dout_nent  : t_arr_AS_51_NENT; -- (#page)
  signal VMSME_16_mem_AA_enb         : t_arr_VMSME_16_A1b;
  signal VMSME_16_mem_AAV_readaddr   : t_arr_VMSME_16_AADDR;
  signal VMSME_16_mem_AAV_dout       : t_arr_VMSME_16_ADATA;
  signal VMSME_16_mem_AAV_dout_mask : t_arr_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_16_mem_A_enb_nentA : t_arr_VMSME_16_1b;
  signal VMSME_16_mem_A_enb_nentB : t_arr_VMSME_16_1b;
  signal VMSME_16_mem_AV_addr_nentA : t_arr_VMSME_16_NENTADDR;
  signal VMSME_16_mem_AV_addr_nentB : t_arr_VMSME_16_NENTADDR;
  signal VMSME_16_mem_AV_dout_nentA : t_arr_VMSME_16_NENT;
  signal VMSME_16_mem_AV_dout_nentB : t_arr_VMSME_16_NENT;
  signal VMSME_17_mem_AA_enb         : t_arr_VMSME_17_A1b;
  signal VMSME_17_mem_AAV_readaddr   : t_arr_VMSME_17_AADDR;
  signal VMSME_17_mem_AAV_dout       : t_arr_VMSME_17_ADATA;
  signal VMSME_17_mem_AAV_dout_mask : t_arr_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_17_mem_A_enb_nentA : t_arr_VMSME_17_1b;
  signal VMSME_17_mem_A_enb_nentB : t_arr_VMSME_17_1b;
  signal VMSME_17_mem_AV_addr_nentA : t_arr_VMSME_17_NENTADDR;
  signal VMSME_17_mem_AV_addr_nentB : t_arr_VMSME_17_NENTADDR;
  signal VMSME_17_mem_AV_dout_nentA : t_arr_VMSME_17_NENT;
  signal VMSME_17_mem_AV_dout_nentB : t_arr_VMSME_17_NENT;
  signal VMSTE_16_mem_AA_enb         : t_arr_VMSTE_16_A1b;
  signal VMSTE_16_mem_AAV_readaddr   : t_arr_VMSTE_16_AADDR;
  signal VMSTE_16_mem_AAV_dout       : t_arr_VMSTE_16_ADATA;
  signal VMSTE_16_mem_AAV_dout_mask : t_arr_VMSTE_16_MASK; -- (#page)(#bin)
  signal VMSTE_16_mem_AAAV_dout_nent : t_arr_VMSTE_16_NENT; -- (#page)(#bin)
  signal TPROJ_60_mem_A_enb          : t_arr_TPROJ_60_1b;
  signal TPROJ_60_mem_AV_readaddr    : t_arr_TPROJ_60_ADDR;
  signal TPROJ_60_mem_AV_dout        : t_arr_TPROJ_60_DATA;
  signal TPROJ_60_mem_AAV_dout_nent  : t_arr_TPROJ_60_NENT; -- (#page)
  signal TPROJ_58_mem_A_enb          : t_arr_TPROJ_58_1b;
  signal TPROJ_58_mem_AV_readaddr    : t_arr_TPROJ_58_ADDR;
  signal TPROJ_58_mem_AV_dout        : t_arr_TPROJ_58_DATA;
  signal TPROJ_58_mem_AAV_dout_nent  : t_arr_TPROJ_58_NENT; -- (#page)
  signal TPAR_70_mem_A_enb          : t_arr_TPAR_70_1b;
  signal TPAR_70_mem_AV_readaddr    : t_arr_TPAR_70_ADDR;
  signal TPAR_70_mem_AV_dout        : t_arr_TPAR_70_DATA;
  signal FM_52_mem_A_enb          : t_arr_FM_52_1b;
  signal FM_52_mem_AV_readaddr    : t_arr_FM_52_ADDR;
  signal FM_52_mem_AV_dout        : t_arr_FM_52_DATA;
  signal FM_52_mem_AAV_dout_nent  : t_arr_FM_52_NENT; -- (#page)
  signal VMR_start : std_logic := '0';
  signal TP_start : std_logic := '0';
  signal MP_start : std_logic := '0';
  signal TP_L1L2C_lut_addr       : std_logic_vector(10 downto 0);
  signal TP_L1L2C_lut_ce       : std_logic;
  signal TP_L1L2C_lut_dout : std_logic_vector(9 downto 0);
  signal TP_L1L2C_regionlut_addr       : std_logic_vector(10 downto 0);
  signal TP_L1L2C_regionlut_ce       : std_logic;
  signal TP_L1L2C_regionlut_dout : std_logic_vector(7 downto 0);
  signal FT_start : std_logic := '0';

begin

  IL_36_loop : for var in enum_IL_36 generate
  begin

    IL_36 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "IL_36_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => IL_36_mem_A_wea(var),
        addra     => IL_36_mem_AV_writeaddr(var),
        dina      => IL_36_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => IL_36_mem_A_enb(var),
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_36_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => AS_36_mem_A_wea(var),
        addra     => AS_36_mem_AV_writeaddr(var),
        dina      => AS_36_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => AS_36_mem_A_enb(var),
        addrb     => AS_36_mem_AV_readaddr(var),
        doutb     => AS_36_mem_AV_dout(var),
        sync_nent => TP_start,
        nent_o    => open
      );

  end generate AS_36_loop;


  AS_51_loop : for var in enum_AS_51 generate
  begin

    AS_51 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 51,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_51_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => AS_51_mem_A_wea(var),
        addra     => AS_51_mem_AV_writeaddr(var),
        dina      => AS_51_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => AS_51_mem_A_enb(var),
        addrb     => AS_51_mem_AV_readaddr(var),
        doutb     => AS_51_mem_AV_dout(var),
        sync_nent => TP_start,
        nent_o    => AS_51_mem_AAV_dout_nent(var)
      );

  end generate AS_51_loop;


  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin

    VMSME_16 : entity work.tf_mem_bin_cm4_new
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_16_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => VMSME_16_mem_A_wea(var),
        addra     => VMSME_16_mem_AV_writeaddr(var),
        dina      => VMSME_16_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSME_16_mem_AA_enb(var)(0),
        addrb0     => VMSME_16_mem_AAV_readaddr(var)(0),
        doutb0     => VMSME_16_mem_AAV_dout(var)(0),
        enb1       => VMSME_16_mem_AA_enb(var)(1),
        addrb1     => VMSME_16_mem_AAV_readaddr(var)(1),
        doutb1     => VMSME_16_mem_AAV_dout(var)(1),
        enb2       => VMSME_16_mem_AA_enb(var)(2),
        addrb2     => VMSME_16_mem_AAV_readaddr(var)(2),
        doutb2     => VMSME_16_mem_AAV_dout(var)(2),
        enb3       => VMSME_16_mem_AA_enb(var)(3),
        addrb3     => VMSME_16_mem_AAV_readaddr(var)(3),
        doutb3     => VMSME_16_mem_AAV_dout(var)(3),
        sync_nent => MP_start,
        enb_nentA  => VMSME_16_mem_A_enb_nentA(var),
        enb_nentB  => VMSME_16_mem_A_enb_nentB(var),
        addr_nentA  => VMSME_16_mem_AV_addr_nentA(var),
        addr_nentB  => VMSME_16_mem_AV_addr_nentB(var),
        dout_nentA    => VMSME_16_mem_AV_dout_nentA(var),
        dout_nentB    => VMSME_16_mem_AV_dout_nentB(var),
        mask_o    => VMSME_16_mem_AAV_dout_mask(var)
      );

  end generate VMSME_16_loop;


  VMSME_17_loop : for var in enum_VMSME_17 generate
  begin

    VMSME_17 : entity work.tf_mem_bin_cm4_new
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_17_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => VMSME_17_mem_A_wea(var),
        addra     => VMSME_17_mem_AV_writeaddr(var),
        dina      => VMSME_17_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSME_17_mem_AA_enb(var)(0),
        addrb0     => VMSME_17_mem_AAV_readaddr(var)(0),
        doutb0     => VMSME_17_mem_AAV_dout(var)(0),
        enb1       => VMSME_17_mem_AA_enb(var)(1),
        addrb1     => VMSME_17_mem_AAV_readaddr(var)(1),
        doutb1     => VMSME_17_mem_AAV_dout(var)(1),
        enb2       => VMSME_17_mem_AA_enb(var)(2),
        addrb2     => VMSME_17_mem_AAV_readaddr(var)(2),
        doutb2     => VMSME_17_mem_AAV_dout(var)(2),
        enb3       => VMSME_17_mem_AA_enb(var)(3),
        addrb3     => VMSME_17_mem_AAV_readaddr(var)(3),
        doutb3     => VMSME_17_mem_AAV_dout(var)(3),
        sync_nent => MP_start,
        enb_nentA  => VMSME_17_mem_A_enb_nentA(var),
        enb_nentB  => VMSME_17_mem_A_enb_nentB(var),
        addr_nentA  => VMSME_17_mem_AV_addr_nentA(var),
        addr_nentB  => VMSME_17_mem_AV_addr_nentB(var),
        dout_nentA    => VMSME_17_mem_AV_dout_nentA(var),
        dout_nentB    => VMSME_17_mem_AV_dout_nentB(var),
        mask_o    => VMSME_17_mem_AAV_dout_mask(var)
      );

  end generate VMSME_17_loop;


  VMSTE_16_loop : for var in enum_VMSTE_16 generate
  begin

    VMSTE_16 : entity work.tf_mem_bin_cm5
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSTE_16_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => VMSTE_16_mem_A_wea(var),
        addra     => VMSTE_16_mem_AV_writeaddr(var),
        dina      => VMSTE_16_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSTE_16_mem_AA_enb(var)(0),
        addrb0     => VMSTE_16_mem_AAV_readaddr(var)(0),
        doutb0     => VMSTE_16_mem_AAV_dout(var)(0),
        enb1       => VMSTE_16_mem_AA_enb(var)(1),
        addrb1     => VMSTE_16_mem_AAV_readaddr(var)(1),
        doutb1     => VMSTE_16_mem_AAV_dout(var)(1),
        enb2       => VMSTE_16_mem_AA_enb(var)(2),
        addrb2     => VMSTE_16_mem_AAV_readaddr(var)(2),
        doutb2     => VMSTE_16_mem_AAV_dout(var)(2),
        enb3       => VMSTE_16_mem_AA_enb(var)(3),
        addrb3     => VMSTE_16_mem_AAV_readaddr(var)(3),
        doutb3     => VMSTE_16_mem_AAV_dout(var)(3),
        enb4       => VMSTE_16_mem_AA_enb(var)(4),
        addrb4     => VMSTE_16_mem_AAV_readaddr(var)(4),
        doutb4     => VMSTE_16_mem_AAV_dout(var)(4),
        sync_nent => TP_start,
        nent_o    => VMSTE_16_mem_AAAV_dout_nent(var),
        mask_o    => VMSTE_16_mem_AAV_dout_mask(var)
      );

  end generate VMSTE_16_loop;


  TPROJ_60_loop : for var in enum_TPROJ_60 generate
  begin

    TPROJ_60 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "TPROJ_60_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => TPROJ_60_mem_A_wea(var),
        addra     => TPROJ_60_mem_AV_writeaddr(var),
        dina      => TPROJ_60_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => TPROJ_60_mem_A_enb(var),
        addrb     => TPROJ_60_mem_AV_readaddr(var),
        doutb     => TPROJ_60_mem_AV_dout(var),
        sync_nent => MP_start,
        nent_o    => TPROJ_60_mem_AAV_dout_nent(var)
      );

  end generate TPROJ_60_loop;


  TPROJ_58_loop : for var in enum_TPROJ_58 generate
  begin

    TPROJ_58 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "TPROJ_58_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => TPROJ_58_mem_A_wea(var),
        addra     => TPROJ_58_mem_AV_writeaddr(var),
        dina      => TPROJ_58_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => TPROJ_58_mem_A_enb(var),
        addrb     => TPROJ_58_mem_AV_readaddr(var),
        doutb     => TPROJ_58_mem_AV_dout(var),
        sync_nent => MP_start,
        nent_o    => TPROJ_58_mem_AAV_dout_nent(var)
      );

  end generate TPROJ_58_loop;


  TPAR_70_loop : for var in enum_TPAR_70 generate
  begin

    TPAR_70 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 70,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "TPAR_70_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => TPAR_70_mem_A_wea(var),
        addra     => TPAR_70_mem_AV_writeaddr(var),
        dina      => TPAR_70_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => TPAR_70_mem_A_enb(var),
        addrb     => TPAR_70_mem_AV_readaddr(var),
        doutb     => TPAR_70_mem_AV_dout(var),
        sync_nent => FT_start,
        nent_o    => open
      );

  end generate TPAR_70_loop;


  FM_52_loop : for var in enum_FM_52 generate
  begin

    FM_52 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_52_"&memory_enum_to_string(var)
      )
      port map (
        clka      => clk,
        wea       => FM_52_mem_A_wea(var),
        addra     => FM_52_mem_AV_writeaddr(var),
        dina      => FM_52_mem_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb       => FM_52_mem_A_enb(var),
        addrb     => FM_52_mem_AV_readaddr(var),
        doutb     => FM_52_mem_AV_dout(var),
        sync_nent => FT_start,
        nent_o    => FM_52_mem_AAV_dout_nent(var)
      );

  end generate FM_52_loop;


  LATCH_IR: entity work.CreateStartSignal
    port map (
      clk   => clk,
      reset => reset,
      done  => IR_done,
      start => VMR_start
  );

  IR_PS10G_1_A : entity work.IR_PS10G_1_A
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
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS10G_1_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS10G_1_A),
      hInputStubs_V_read     => DL_39_link_read(PS10G_1_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L1PHIB_PS10G_1_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L1PHIB_PS10G_1_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L1PHIB_PS10G_1_A),
      hLinkWord_V => "00100000000000000011",
      hPhBnWord_V => "00000000000000000000000000000010"
  );

  IR_PS10G_2_A : entity work.IR_PS10G_2_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS10G_2_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS10G_2_A),
      hInputStubs_V_read     => DL_39_link_read(PS10G_2_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L1PHIB_PS10G_2_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L1PHIB_PS10G_2_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L1PHIB_PS10G_2_A),
      hLinkWord_V => "00100000000000000011",
      hPhBnWord_V => "00000000000000000000000000000010"
  );

  IR_PS10G_3_A : entity work.IR_PS10G_3_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS10G_3_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS10G_3_A),
      hInputStubs_V_read     => DL_39_link_read(PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L2PHIA_PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L2PHIA_PS10G_3_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L2PHIA_PS10G_3_A),
      hLinkWord_V => "00100000000000000101",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  IR_PS_1_A : entity work.IR_PS_1_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS_1_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS_1_A),
      hInputStubs_V_read     => DL_39_link_read(PS_1_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L3PHIA_PS_1_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L3PHIA_PS_1_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L3PHIA_PS_1_A),
      hLinkWord_V => "00100000000000000111",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  IR_PS_2_A : entity work.IR_PS_2_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(PS_2_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(PS_2_A),
      hInputStubs_V_read     => DL_39_link_read(PS_2_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L3PHIA_PS_2_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L3PHIA_PS_2_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L3PHIA_PS_2_A),
      hLinkWord_V => "00100000000000000111",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  IR_2S_1_A : entity work.IR_2S_1_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(twoS_1_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(twoS_1_A),
      hInputStubs_V_read     => DL_39_link_read(twoS_1_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L4PHIA_2S_1_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L4PHIA_2S_1_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L4PHIA_2S_1_A),
      hOutputStubs_1_dataarray_data_V_ce0       => open,
      hOutputStubs_1_dataarray_data_V_we0       => IL_36_mem_A_wea(L5PHIA_2S_1_A),
      hOutputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L5PHIA_2S_1_A),
      hOutputStubs_1_dataarray_data_V_d0        => IL_36_mem_AV_din(L5PHIA_2S_1_A),
      hLinkWord_V => "01010000000010111001",
      hPhBnWord_V => "00000000000000000000000100000001"
  );

  IR_2S_2_A : entity work.IR_2S_2_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(twoS_2_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(twoS_2_A),
      hInputStubs_V_read     => DL_39_link_read(twoS_2_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L5PHIA_2S_2_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L5PHIA_2S_2_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L5PHIA_2S_2_A),
      hLinkWord_V => "00110000000000001011",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  IR_2S_3_A : entity work.IR_2S_3_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(twoS_3_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(twoS_3_A),
      hInputStubs_V_read     => DL_39_link_read(twoS_3_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L6PHIA_2S_3_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L6PHIA_2S_3_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L6PHIA_2S_3_A),
      hLinkWord_V => "00110000000000001101",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  IR_2S_4_A : entity work.IR_2S_4_A
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => IR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_in,
      hInputStubs_V_dout     => DL_39_link_AV_dout(twoS_4_A),
      hInputStubs_V_empty_n  => DL_39_link_empty_neg(twoS_4_A),
      hInputStubs_V_read     => DL_39_link_read(twoS_4_A),
      hOutputStubs_0_dataarray_data_V_ce0       => open,
      hOutputStubs_0_dataarray_data_V_we0       => IL_36_mem_A_wea(L6PHIA_2S_4_A),
      hOutputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_writeaddr(L6PHIA_2S_4_A),
      hOutputStubs_0_dataarray_data_V_d0        => IL_36_mem_AV_din(L6PHIA_2S_4_A),
      hLinkWord_V => "00110000000000001101",
      hPhBnWord_V => "00000000000000000000000000000001"
  );

  LATCH_VMR: entity work.CreateStartSignal
    port map (
      clk   => clk,
      reset => reset,
      done  => VMR_done,
      start => TP_start
  );

  VMR_L1PHIB : entity work.VMR_L1PHIB
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
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L1PHIB_PS10G_1_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L1PHIB_PS10G_1_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L1PHIB_PS10G_1_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L1PHIB_PS10G_1_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L1PHIB_PS10G_1_A)(1),
      inputStubs_1_dataarray_data_V_ce0       => IL_36_mem_A_enb(L1PHIB_PS10G_2_A),
      inputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L1PHIB_PS10G_2_A),
      inputStubs_1_dataarray_data_V_q0        => IL_36_mem_AV_dout(L1PHIB_PS10G_2_A),
      inputStubs_1_nentries_0_V               => IL_36_mem_AAV_dout_nent(L1PHIB_PS10G_2_A)(0),
      inputStubs_1_nentries_1_V               => IL_36_mem_AAV_dout_nent(L1PHIB_PS10G_2_A)(1),
      memoriesASInner_0_dataarray_data_V_ce0       => open,
      memoriesASInner_0_dataarray_data_V_we0       => AS_51_mem_A_wea(L1PHIB_BC),
      memoriesASInner_0_dataarray_data_V_address0  => AS_51_mem_AV_writeaddr(L1PHIB_BC),
      memoriesASInner_0_dataarray_data_V_d0        => AS_51_mem_AV_din(L1PHIB_BC)
  );

  VMR_L2PHIA : entity work.VMR_L2PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_out,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L2PHIA_PS10G_3_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L2PHIA_PS10G_3_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L2PHIA_PS10G_3_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L2PHIA_PS10G_3_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L2PHIA_PS10G_3_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L2PHIA_B_L1C),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L2PHIA_B_L1C),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L2PHIA_B_L1C),
      memoriesTEO_0_dataarray_0_data_V_ce0       => open,
      memoriesTEO_0_dataarray_0_data_V_we0       => VMSTE_16_mem_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_0_data_V_address0  => VMSTE_16_mem_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_0_data_V_d0        => VMSTE_16_mem_AV_din(L2PHIAn3)
  );

  VMR_L3PHIA : entity work.VMR_L3PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_out,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L3PHIA_PS_1_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L3PHIA_PS_1_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L3PHIA_PS_1_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L3PHIA_PS_1_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L3PHIA_PS_1_A)(1),
      inputStubs_1_dataarray_data_V_ce0       => IL_36_mem_A_enb(L3PHIA_PS_2_A),
      inputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L3PHIA_PS_2_A),
      inputStubs_1_dataarray_data_V_q0        => IL_36_mem_AV_dout(L3PHIA_PS_2_A),
      inputStubs_1_nentries_0_V               => IL_36_mem_AAV_dout_nent(L3PHIA_PS_2_A)(0),
      inputStubs_1_nentries_1_V               => IL_36_mem_AAV_dout_nent(L3PHIA_PS_2_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L3PHIAn1),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L3PHIAn1),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L3PHIAn1),
      memoryME_dataarray_0_data_V_ce0       => open,
      memoryME_dataarray_0_data_V_we0       => VMSME_16_mem_A_wea(L3PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_16_mem_AV_writeaddr(L3PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_16_mem_AV_din(L3PHIAn1)
  );

  VMR_L4PHIA : entity work.VMR_L4PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_out,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L4PHIA_2S_1_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L4PHIA_2S_1_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L4PHIA_2S_1_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L4PHIA_2S_1_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L4PHIA_2S_1_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L4PHIAn1),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L4PHIAn1),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L4PHIAn1),
      memoryME_dataarray_0_data_V_ce0       => open,
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem_A_wea(L4PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem_AV_writeaddr(L4PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem_AV_din(L4PHIAn1)
  );

  VMR_L5PHIA : entity work.VMR_L5PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_out,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L5PHIA_2S_1_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L5PHIA_2S_1_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L5PHIA_2S_1_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L5PHIA_2S_1_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L5PHIA_2S_1_A)(1),
      inputStubs_1_dataarray_data_V_ce0       => IL_36_mem_A_enb(L5PHIA_2S_2_A),
      inputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L5PHIA_2S_2_A),
      inputStubs_1_dataarray_data_V_q0        => IL_36_mem_AV_dout(L5PHIA_2S_2_A),
      inputStubs_1_nentries_0_V               => IL_36_mem_AAV_dout_nent(L5PHIA_2S_2_A)(0),
      inputStubs_1_nentries_1_V               => IL_36_mem_AAV_dout_nent(L5PHIA_2S_2_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L5PHIAn1),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L5PHIAn1),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L5PHIAn1),
      memoryME_dataarray_0_data_V_ce0       => open,
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem_A_wea(L5PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem_AV_writeaddr(L5PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem_AV_din(L5PHIAn1)
  );

  VMR_L6PHIA : entity work.VMR_L6PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => VMR_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => IR_bx_out,
      inputStubs_0_dataarray_data_V_ce0       => IL_36_mem_A_enb(L6PHIA_2S_3_A),
      inputStubs_0_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L6PHIA_2S_3_A),
      inputStubs_0_dataarray_data_V_q0        => IL_36_mem_AV_dout(L6PHIA_2S_3_A),
      inputStubs_0_nentries_0_V               => IL_36_mem_AAV_dout_nent(L6PHIA_2S_3_A)(0),
      inputStubs_0_nentries_1_V               => IL_36_mem_AAV_dout_nent(L6PHIA_2S_3_A)(1),
      inputStubs_1_dataarray_data_V_ce0       => IL_36_mem_A_enb(L6PHIA_2S_4_A),
      inputStubs_1_dataarray_data_V_address0  => IL_36_mem_AV_readaddr(L6PHIA_2S_4_A),
      inputStubs_1_dataarray_data_V_q0        => IL_36_mem_AV_dout(L6PHIA_2S_4_A),
      inputStubs_1_nentries_0_V               => IL_36_mem_AAV_dout_nent(L6PHIA_2S_4_A)(0),
      inputStubs_1_nentries_1_V               => IL_36_mem_AAV_dout_nent(L6PHIA_2S_4_A)(1),
      memoriesAS_0_dataarray_data_V_ce0       => open,
      memoriesAS_0_dataarray_data_V_we0       => AS_36_mem_A_wea(L6PHIAn1),
      memoriesAS_0_dataarray_data_V_address0  => AS_36_mem_AV_writeaddr(L6PHIAn1),
      memoriesAS_0_dataarray_data_V_d0        => AS_36_mem_AV_din(L6PHIAn1),
      memoryME_dataarray_0_data_V_ce0       => open,
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem_A_wea(L6PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem_AV_writeaddr(L6PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem_AV_din(L6PHIAn1)
  );


  TP_L1L2C_lut : entity work.tf_lutdat
    generic map (
      lut_file  => getDirSCRIPT & "LUTs/TP_L1L2.dat",
      lut_width => 10,
      lut_depth => 2048
    )
    port map (
      clk       => clk,
      addr      => TP_L1L2C_lut_addr,
      ce        => TP_L1L2C_lut_ce,
      dout      => TP_L1L2C_lut_dout
  );


  TP_L1L2C_regionlut : entity work.tf_lutdat
    generic map (
      lut_file  => getDirSCRIPT & "LUTs/TP_L1L2C_usereg.dat",
      lut_width => 8,
      lut_depth => 2048
    )
    port map (
      clk       => clk,
      addr      => TP_L1L2C_regionlut_addr,
      ce        => TP_L1L2C_regionlut_ce,
      dout      => TP_L1L2C_regionlut_dout
  );

  LATCH_TP: entity work.CreateStartSignal
    port map (
      clk   => clk,
      reset => reset,
      done  => TP_done,
      start => MP_start
  );

  TP_L1L2C : entity work.TP_L1L2C
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => TP_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => TP_done,
      bx_V          => VMR_bx_out,
      bx_o_V        => TP_bx_out,
      bx_o_V_ap_vld => TP_bx_out_vld,
      lut_V_address0                  => TP_L1L2C_lut_addr,
      lut_V_ce0                       => TP_L1L2C_lut_ce,
      lut_V_q0                        => TP_L1L2C_lut_dout,
      regionlut_V_address0                  => TP_L1L2C_regionlut_addr,
      regionlut_V_ce0                       => TP_L1L2C_regionlut_ce,
      regionlut_V_q0                        => TP_L1L2C_regionlut_dout,
      innerStubs_0_dataarray_data_V_ce0       => AS_51_mem_A_enb(L1PHIB_BC),
      innerStubs_0_dataarray_data_V_address0  => AS_51_mem_AV_readaddr(L1PHIB_BC),
      innerStubs_0_dataarray_data_V_q0        => AS_51_mem_AV_dout(L1PHIB_BC),
      innerStubs_0_nentries_0_V               => AS_51_mem_AAV_dout_nent(L1PHIB_BC)(0),
      innerStubs_0_nentries_1_V               => AS_51_mem_AAV_dout_nent(L1PHIB_BC)(1),
      outerStubs_dataarray_data_V_ce0       => AS_36_mem_A_enb(L2PHIA_B_L1C),
      outerStubs_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L2PHIA_B_L1C),
      outerStubs_dataarray_data_V_q0        => AS_36_mem_AV_dout(L2PHIA_B_L1C),
      outerVMStubs_dataarray_0_data_V_ce0       => VMSTE_16_mem_AA_enb(L2PHIAn3)(0),
      outerVMStubs_dataarray_0_data_V_address0  => VMSTE_16_mem_AAV_readaddr(L2PHIAn3)(0),
      outerVMStubs_dataarray_0_data_V_q0        => VMSTE_16_mem_AAV_dout(L2PHIAn3)(0),
      outerVMStubs_dataarray_1_data_V_ce0       => VMSTE_16_mem_AA_enb(L2PHIAn3)(1),
      outerVMStubs_dataarray_1_data_V_address0  => VMSTE_16_mem_AAV_readaddr(L2PHIAn3)(1),
      outerVMStubs_dataarray_1_data_V_q0        => VMSTE_16_mem_AAV_dout(L2PHIAn3)(1),
      outerVMStubs_dataarray_2_data_V_ce0       => VMSTE_16_mem_AA_enb(L2PHIAn3)(2),
      outerVMStubs_dataarray_2_data_V_address0  => VMSTE_16_mem_AAV_readaddr(L2PHIAn3)(2),
      outerVMStubs_dataarray_2_data_V_q0        => VMSTE_16_mem_AAV_dout(L2PHIAn3)(2),
      outerVMStubs_dataarray_3_data_V_ce0       => VMSTE_16_mem_AA_enb(L2PHIAn3)(3),
      outerVMStubs_dataarray_3_data_V_address0  => VMSTE_16_mem_AAV_readaddr(L2PHIAn3)(3),
      outerVMStubs_dataarray_3_data_V_q0        => VMSTE_16_mem_AAV_dout(L2PHIAn3)(3),
      outerVMStubs_dataarray_4_data_V_ce0       => VMSTE_16_mem_AA_enb(L2PHIAn3)(4),
      outerVMStubs_dataarray_4_data_V_address0  => VMSTE_16_mem_AAV_readaddr(L2PHIAn3)(4),
      outerVMStubs_dataarray_4_data_V_q0        => VMSTE_16_mem_AAV_dout(L2PHIAn3)(4),
      outerVMStubs_binmask8_0_V_0     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(56), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(48), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(40), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(32), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(24), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(16), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(8), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(0)),
      outerVMStubs_binmask8_0_V_1     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(57), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(49), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(41), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(33), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(25), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(17), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(9), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(1)),
      outerVMStubs_binmask8_0_V_2     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(58), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(50), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(42), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(34), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(26), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(18), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(10), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(2)),
      outerVMStubs_binmask8_0_V_3     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(59), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(51), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(43), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(35), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(27), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(19), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(11), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(3)),
      outerVMStubs_binmask8_0_V_4     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(60), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(52), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(44), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(36), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(28), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(20), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(12), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(4)),
      outerVMStubs_binmask8_0_V_5     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(61), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(53), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(45), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(37), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(29), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(21), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(13), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(5)),
      outerVMStubs_binmask8_0_V_6     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(62), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(54), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(46), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(38), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(30), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(22), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(14), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(6)),
      outerVMStubs_binmask8_0_V_7     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(63), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(55), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(47), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(39), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(31), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(23), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(15), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(7)),
      outerVMStubs_nentries8_0_V_0     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(56), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(48), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(40), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(32), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(24), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(16), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(8), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(0)),
      outerVMStubs_nentries8_0_V_1     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(57), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(49), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(41), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(33), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(25), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(17), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(9), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(1)),
      outerVMStubs_nentries8_0_V_2     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(58), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(50), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(42), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(34), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(26), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(18), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(10), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(2)),
      outerVMStubs_nentries8_0_V_3     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(59), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(51), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(43), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(35), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(27), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(19), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(11), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(3)),
      outerVMStubs_nentries8_0_V_4     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(60), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(52), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(44), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(36), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(28), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(20), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(12), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(4)),
      outerVMStubs_nentries8_0_V_5     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(61), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(53), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(45), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(37), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(29), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(21), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(13), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(5)),
      outerVMStubs_nentries8_0_V_6     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(62), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(54), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(46), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(38), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(30), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(22), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(14), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(6)),
      outerVMStubs_nentries8_0_V_7     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(63), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(55), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(47), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(39), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(31), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(23), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(15), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(7)),
      outerVMStubs_binmask8_1_V_0     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(56), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(48), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(40), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(32), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(24), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(16), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(8), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(0)),
      outerVMStubs_binmask8_1_V_1     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(57), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(49), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(41), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(33), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(25), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(17), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(9), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(1)),
      outerVMStubs_binmask8_1_V_2     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(58), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(50), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(42), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(34), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(26), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(18), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(10), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(2)),
      outerVMStubs_binmask8_1_V_3     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(59), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(51), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(43), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(35), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(27), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(19), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(11), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(3)),
      outerVMStubs_binmask8_1_V_4     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(60), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(52), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(44), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(36), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(28), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(20), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(12), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(4)),
      outerVMStubs_binmask8_1_V_5     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(61), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(53), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(45), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(37), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(29), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(21), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(13), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(5)),
      outerVMStubs_binmask8_1_V_6     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(62), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(54), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(46), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(38), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(30), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(22), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(14), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(6)),
      outerVMStubs_binmask8_1_V_7     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(63), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(55), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(47), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(39), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(31), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(23), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(15), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(7)),
      outerVMStubs_nentries8_1_V_0     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(56), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(48), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(40), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(32), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(24), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(16), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(8), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(0)),
      outerVMStubs_nentries8_1_V_1     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(57), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(49), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(41), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(33), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(25), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(17), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(9), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(1)),
      outerVMStubs_nentries8_1_V_2     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(58), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(50), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(42), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(34), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(26), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(18), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(10), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(2)),
      outerVMStubs_nentries8_1_V_3     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(59), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(51), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(43), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(35), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(27), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(19), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(11), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(3)),
      outerVMStubs_nentries8_1_V_4     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(60), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(52), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(44), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(36), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(28), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(20), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(12), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(4)),
      outerVMStubs_nentries8_1_V_5     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(61), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(53), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(45), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(37), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(29), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(21), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(13), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(5)),
      outerVMStubs_nentries8_1_V_6     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(62), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(54), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(46), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(38), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(30), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(22), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(14), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(6)),
      outerVMStubs_nentries8_1_V_7     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(63), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(55), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(47), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(39), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(31), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(23), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(15), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(7)),
      trackletParameters_dataarray_data_V_ce0       => open,
      trackletParameters_dataarray_data_V_we0       => TPAR_70_mem_A_wea(L1L2C),
      trackletParameters_dataarray_data_V_address0  => TPAR_70_mem_AV_writeaddr(L1L2C),
      trackletParameters_dataarray_data_V_d0        => TPAR_70_mem_AV_din(L1L2C),
      projout_barrel_ps_12_dataarray_data_V_ce0       => open,
      projout_barrel_ps_12_dataarray_data_V_we0       => TPROJ_60_mem_A_wea(L1L2C_L3PHIA),
      projout_barrel_ps_12_dataarray_data_V_address0  => TPROJ_60_mem_AV_writeaddr(L1L2C_L3PHIA),
      projout_barrel_ps_12_dataarray_data_V_d0        => TPROJ_60_mem_AV_din(L1L2C_L3PHIA),
      projout_barrel_2s_0_dataarray_data_V_ce0       => open,
      projout_barrel_2s_0_dataarray_data_V_we0       => TPROJ_58_mem_A_wea(L1L2C_L4PHIA),
      projout_barrel_2s_0_dataarray_data_V_address0  => TPROJ_58_mem_AV_writeaddr(L1L2C_L4PHIA),
      projout_barrel_2s_0_dataarray_data_V_d0        => TPROJ_58_mem_AV_din(L1L2C_L4PHIA),
      projout_barrel_2s_4_dataarray_data_V_ce0       => open,
      projout_barrel_2s_4_dataarray_data_V_we0       => TPROJ_58_mem_A_wea(L1L2C_L5PHIA),
      projout_barrel_2s_4_dataarray_data_V_address0  => TPROJ_58_mem_AV_writeaddr(L1L2C_L5PHIA),
      projout_barrel_2s_4_dataarray_data_V_d0        => TPROJ_58_mem_AV_din(L1L2C_L5PHIA),
      projout_barrel_2s_8_dataarray_data_V_ce0       => open,
      projout_barrel_2s_8_dataarray_data_V_we0       => TPROJ_58_mem_A_wea(L1L2C_L6PHIA),
      projout_barrel_2s_8_dataarray_data_V_address0  => TPROJ_58_mem_AV_writeaddr(L1L2C_L6PHIA),
      projout_barrel_2s_8_dataarray_data_V_d0        => TPROJ_58_mem_AV_din(L1L2C_L6PHIA)
  );

  LATCH_MP: entity work.CreateStartSignal
    port map (
      clk   => clk,
      reset => reset,
      done  => MP_done,
      start => FT_start
  );

  MP_L3PHIA : entity work.MP_L3PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MP_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MP_done,
      bx_V          => TP_bx_out,
      bx_o_V        => MP_bx_out,
      bx_o_V_ap_vld => MP_bx_out_vld,
      projin_0_dataarray_data_V_ce0       => TPROJ_60_mem_A_enb(L1L2C_L3PHIA),
      projin_0_dataarray_data_V_address0  => TPROJ_60_mem_AV_readaddr(L1L2C_L3PHIA),
      projin_0_dataarray_data_V_q0        => TPROJ_60_mem_AV_dout(L1L2C_L3PHIA),
      projin_0_nentries_0_V               => TPROJ_60_mem_AAV_dout_nent(L1L2C_L3PHIA)(0),
      projin_0_nentries_1_V               => TPROJ_60_mem_AAV_dout_nent(L1L2C_L3PHIA)(1),
      instubdata_dataarray_0_data_V_ce0       => VMSME_16_mem_AA_enb(L3PHIAn1)(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_16_mem_AAV_readaddr(L3PHIAn1)(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_16_mem_AAV_dout(L3PHIAn1)(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_16_mem_AA_enb(L3PHIAn1)(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_16_mem_AAV_readaddr(L3PHIAn1)(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_16_mem_AAV_dout(L3PHIAn1)(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_16_mem_AA_enb(L3PHIAn1)(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_16_mem_AAV_readaddr(L3PHIAn1)(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_16_mem_AAV_dout(L3PHIAn1)(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_16_mem_AA_enb(L3PHIAn1)(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_16_mem_AAV_readaddr(L3PHIAn1)(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_16_mem_AAV_dout(L3PHIAn1)(3),
      instubdata_nentries8a_v_q0              => VMSME_16_mem_AV_dout_nentA(L3PHIAn1),
      instubdata_nentries8a_v_address0        => VMSME_16_mem_AV_addr_nentA(L3PHIAn1),
      instubdata_nentries8a_v_ce0             => VMSME_16_mem_A_enb_nentA(L3PHIAn1),
      instubdata_nentries8b_v_q0              => VMSME_16_mem_AV_dout_nentB(L3PHIAn1),
      instubdata_nentries8b_v_address0        => VMSME_16_mem_AV_addr_nentB(L3PHIAn1),
      instubdata_nentries8b_v_ce0             => VMSME_16_mem_A_enb_nentB(L3PHIAn1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L3PHIAn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L3PHIAn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L3PHIAn1),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L3PHIA),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L3PHIA),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L3PHIA)
  );

  MP_L4PHIA : entity work.MP_L4PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MP_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => TP_bx_out,
      projin_0_dataarray_data_V_ce0       => TPROJ_58_mem_A_enb(L1L2C_L4PHIA),
      projin_0_dataarray_data_V_address0  => TPROJ_58_mem_AV_readaddr(L1L2C_L4PHIA),
      projin_0_dataarray_data_V_q0        => TPROJ_58_mem_AV_dout(L1L2C_L4PHIA),
      projin_0_nentries_0_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L4PHIA)(0),
      projin_0_nentries_1_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L4PHIA)(1),
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem_AA_enb(L4PHIAn1)(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem_AAV_readaddr(L4PHIAn1)(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem_AAV_dout(L4PHIAn1)(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem_AA_enb(L4PHIAn1)(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem_AAV_readaddr(L4PHIAn1)(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem_AAV_dout(L4PHIAn1)(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem_AA_enb(L4PHIAn1)(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem_AAV_readaddr(L4PHIAn1)(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem_AAV_dout(L4PHIAn1)(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem_AA_enb(L4PHIAn1)(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem_AAV_readaddr(L4PHIAn1)(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem_AAV_dout(L4PHIAn1)(3),
      instubdata_nentries8a_v_q0              => VMSME_17_mem_AV_dout_nentA(L4PHIAn1),
      instubdata_nentries8a_v_address0        => VMSME_17_mem_AV_addr_nentA(L4PHIAn1),
      instubdata_nentries8a_v_ce0             => VMSME_17_mem_A_enb_nentA(L4PHIAn1),
      instubdata_nentries8b_v_q0              => VMSME_17_mem_AV_dout_nentB(L4PHIAn1),
      instubdata_nentries8b_v_address0        => VMSME_17_mem_AV_addr_nentB(L4PHIAn1),
      instubdata_nentries8b_v_ce0             => VMSME_17_mem_A_enb_nentB(L4PHIAn1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L4PHIAn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L4PHIAn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L4PHIAn1),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L4PHIA),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L4PHIA),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L4PHIA)
  );

  MP_L5PHIA : entity work.MP_L5PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MP_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => TP_bx_out,
      projin_0_dataarray_data_V_ce0       => TPROJ_58_mem_A_enb(L1L2C_L5PHIA),
      projin_0_dataarray_data_V_address0  => TPROJ_58_mem_AV_readaddr(L1L2C_L5PHIA),
      projin_0_dataarray_data_V_q0        => TPROJ_58_mem_AV_dout(L1L2C_L5PHIA),
      projin_0_nentries_0_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L5PHIA)(0),
      projin_0_nentries_1_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L5PHIA)(1),
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem_AA_enb(L5PHIAn1)(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem_AAV_readaddr(L5PHIAn1)(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem_AAV_dout(L5PHIAn1)(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem_AA_enb(L5PHIAn1)(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem_AAV_readaddr(L5PHIAn1)(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem_AAV_dout(L5PHIAn1)(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem_AA_enb(L5PHIAn1)(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem_AAV_readaddr(L5PHIAn1)(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem_AAV_dout(L5PHIAn1)(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem_AA_enb(L5PHIAn1)(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem_AAV_readaddr(L5PHIAn1)(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem_AAV_dout(L5PHIAn1)(3),
      instubdata_nentries8a_v_q0              => VMSME_17_mem_AV_dout_nentA(L5PHIAn1),
      instubdata_nentries8a_v_address0        => VMSME_17_mem_AV_addr_nentA(L5PHIAn1),
      instubdata_nentries8a_v_ce0             => VMSME_17_mem_A_enb_nentA(L5PHIAn1),
      instubdata_nentries8b_v_q0              => VMSME_17_mem_AV_dout_nentB(L5PHIAn1),
      instubdata_nentries8b_v_address0        => VMSME_17_mem_AV_addr_nentB(L5PHIAn1),
      instubdata_nentries8b_v_ce0             => VMSME_17_mem_A_enb_nentB(L5PHIAn1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L5PHIAn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L5PHIAn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L5PHIAn1),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L5PHIA),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L5PHIA),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L5PHIA)
  );

  MP_L6PHIA : entity work.MP_L6PHIA
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MP_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => TP_bx_out,
      projin_0_dataarray_data_V_ce0       => TPROJ_58_mem_A_enb(L1L2C_L6PHIA),
      projin_0_dataarray_data_V_address0  => TPROJ_58_mem_AV_readaddr(L1L2C_L6PHIA),
      projin_0_dataarray_data_V_q0        => TPROJ_58_mem_AV_dout(L1L2C_L6PHIA),
      projin_0_nentries_0_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L6PHIA)(0),
      projin_0_nentries_1_V               => TPROJ_58_mem_AAV_dout_nent(L1L2C_L6PHIA)(1),
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem_AA_enb(L6PHIAn1)(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem_AAV_readaddr(L6PHIAn1)(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem_AAV_dout(L6PHIAn1)(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem_AA_enb(L6PHIAn1)(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem_AAV_readaddr(L6PHIAn1)(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem_AAV_dout(L6PHIAn1)(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem_AA_enb(L6PHIAn1)(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem_AAV_readaddr(L6PHIAn1)(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem_AAV_dout(L6PHIAn1)(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem_AA_enb(L6PHIAn1)(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem_AAV_readaddr(L6PHIAn1)(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem_AAV_dout(L6PHIAn1)(3),
      instubdata_nentries8a_v_q0              => VMSME_17_mem_AV_dout_nentA(L6PHIAn1),
      instubdata_nentries8a_v_address0        => VMSME_17_mem_AV_addr_nentA(L6PHIAn1),
      instubdata_nentries8a_v_ce0             => VMSME_17_mem_A_enb_nentA(L6PHIAn1),
      instubdata_nentries8b_v_q0              => VMSME_17_mem_AV_dout_nentB(L6PHIAn1),
      instubdata_nentries8b_v_address0        => VMSME_17_mem_AV_addr_nentB(L6PHIAn1),
      instubdata_nentries8b_v_ce0             => VMSME_17_mem_A_enb_nentB(L6PHIAn1),
      allstub_dataarray_data_V_ce0       => AS_36_mem_A_enb(L6PHIAn1),
      allstub_dataarray_data_V_address0  => AS_36_mem_AV_readaddr(L6PHIAn1),
      allstub_dataarray_data_V_q0        => AS_36_mem_AV_dout(L6PHIAn1),
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_52_mem_A_wea(L1L2_L6PHIA),
      fullmatch_0_dataarray_data_V_address0  => FM_52_mem_AV_writeaddr(L1L2_L6PHIA),
      fullmatch_0_dataarray_data_V_d0        => FM_52_mem_AV_din(L1L2_L6PHIA)
  );

  FT_L1L2 : entity work.FT_L1L2
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => FT_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => FT_done,
      bx_V          => MP_bx_out,
      bx_o_V        => FT_bx_out,
      bx_o_V_ap_vld => FT_bx_out_vld,
      trackletParameters_0_dataarray_data_V_ce0       => TPAR_70_mem_A_enb(L1L2C),
      trackletParameters_0_dataarray_data_V_address0  => TPAR_70_mem_AV_readaddr(L1L2C),
      trackletParameters_0_dataarray_data_V_q0        => TPAR_70_mem_AV_dout(L1L2C),
      barrelFullMatches_0_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L3PHIA),
      barrelFullMatches_0_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L3PHIA),
      barrelFullMatches_0_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L3PHIA),
      barrelFullMatches_0_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L3PHIA)(0),
      barrelFullMatches_0_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L3PHIA)(1),
      barrelFullMatches_1_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L4PHIA),
      barrelFullMatches_1_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L4PHIA),
      barrelFullMatches_1_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L4PHIA),
      barrelFullMatches_1_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L4PHIA)(0),
      barrelFullMatches_1_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L4PHIA)(1),
      barrelFullMatches_2_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L5PHIA),
      barrelFullMatches_2_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L5PHIA),
      barrelFullMatches_2_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L5PHIA),
      barrelFullMatches_2_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L5PHIA)(0),
      barrelFullMatches_2_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L5PHIA)(1),
      barrelFullMatches_3_dataarray_data_V_ce0       => FM_52_mem_A_enb(L1L2_L6PHIA),
      barrelFullMatches_3_dataarray_data_V_address0  => FM_52_mem_AV_readaddr(L1L2_L6PHIA),
      barrelFullMatches_3_dataarray_data_V_q0        => FM_52_mem_AV_dout(L1L2_L6PHIA),
      barrelFullMatches_3_nentries_0_V               => FM_52_mem_AAV_dout_nent(L1L2_L6PHIA)(0),
      barrelFullMatches_3_nentries_1_V               => FM_52_mem_AAV_dout_nent(L1L2_L6PHIA)(1),
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
