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
    FT_bx_out : out std_logic_vector(2 downto 0);
    FT_bx_out_vld : out std_logic;
    FT_done   : out std_logic;
    DL_39_link_AV_dout       : in t_arr_DL_39_DATA;
    DL_39_link_empty_neg     : in t_arr_DL_39_1b;
    DL_39_link_read          : out t_arr_DL_39_1b;
    TW_84_stream_AV_din       : out t_arr_TW_84_DATA;
    TW_84_stream_A_full_neg   : in t_arr_TW_84_1b;
    TW_84_stream_A_write      : out t_arr_TW_84_1b;
    BW_46_stream_AV_din       : out t_arr_BW_46_DATA;
    BW_46_stream_A_full_neg   : in t_arr_BW_46_1b;
    BW_46_stream_A_write      : out t_arr_BW_46_1b
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
  signal AS_36_mem_A_enb          : t_arr_AS_36_1b;
  signal AS_36_mem_AV_readaddr    : t_arr_AS_36_ADDR;
  signal AS_36_mem_AV_dout        : t_arr_AS_36_DATA;
  signal AS_51_mem_A_wea          : t_arr_AS_51_1b;
  signal AS_51_mem_AV_writeaddr   : t_arr_AS_51_ADDR;
  signal AS_51_mem_AV_din         : t_arr_AS_51_DATA;
  signal AS_51_mem_A_enb          : t_arr_AS_51_1b;
  signal AS_51_mem_AV_readaddr    : t_arr_AS_51_ADDR;
  signal AS_51_mem_AV_dout        : t_arr_AS_51_DATA;
  signal AS_51_mem_AAV_dout_nent  : t_arr_AS_51_NENT; -- (#page)
  signal VMSME_16_mem0_A_wea          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem0_AV_writeaddr   : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem0_AV_din         : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem1_A_wea          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem1_AV_writeaddr   : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem1_AV_din         : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem2_A_wea          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem2_AV_writeaddr   : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem2_AV_din         : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem3_A_wea          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem3_AV_writeaddr   : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem3_AV_din         : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem0_A_enb          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem0_AV_readaddr    : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem0_AV_dout        : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem1_A_enb          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem1_AV_readaddr    : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem1_AV_dout        : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem2_A_enb          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem2_AV_readaddr    : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem2_AV_dout        : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem3_A_enb          : t_arr_VMSME_16_1b;
  signal VMSME_16_mem3_AV_readaddr    : t_arr_VMSME_16_ADDR;
  signal VMSME_16_mem3_AV_dout        : t_arr_VMSME_16_DATA;
  signal VMSME_16_mem_AAV_dout_mask : t_arr_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_16_mem_AAAV_dout_nent : t_arr_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_17_mem0_A_wea          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem0_AV_writeaddr   : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem0_AV_din         : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem1_A_wea          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem1_AV_writeaddr   : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem1_AV_din         : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem2_A_wea          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem2_AV_writeaddr   : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem2_AV_din         : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem3_A_wea          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem3_AV_writeaddr   : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem3_AV_din         : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem0_A_enb          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem0_AV_readaddr    : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem0_AV_dout        : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem1_A_enb          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem1_AV_readaddr    : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem1_AV_dout        : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem2_A_enb          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem2_AV_readaddr    : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem2_AV_dout        : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem3_A_enb          : t_arr_VMSME_17_1b;
  signal VMSME_17_mem3_AV_readaddr    : t_arr_VMSME_17_ADDR;
  signal VMSME_17_mem3_AV_dout        : t_arr_VMSME_17_DATA;
  signal VMSME_17_mem_AAV_dout_mask : t_arr_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_17_mem_AAAV_dout_nent : t_arr_VMSME_17_NENT; -- (#page)(#bin)
  signal VMSTE_16_mem0_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem0_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem0_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem1_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem1_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem1_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem2_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem2_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem2_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem3_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem3_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem3_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem4_A_wea          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem4_AV_writeaddr   : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem4_AV_din         : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem0_A_enb          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem0_AV_readaddr    : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem0_AV_dout        : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem1_A_enb          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem1_AV_readaddr    : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem1_AV_dout        : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem2_A_enb          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem2_AV_readaddr    : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem2_AV_dout        : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem3_A_enb          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem3_AV_readaddr    : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem3_AV_dout        : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem4_A_enb          : t_arr_VMSTE_16_1b;
  signal VMSTE_16_mem4_AV_readaddr    : t_arr_VMSTE_16_ADDR;
  signal VMSTE_16_mem4_AV_dout        : t_arr_VMSTE_16_DATA;
  signal VMSTE_16_mem_AAV_dout_mask : t_arr_VMSTE_16_MASK; -- (#page)(#bin)
  signal VMSTE_16_mem_AAAV_dout_nent : t_arr_VMSTE_16_NENT; -- (#page)(#bin)
  signal TPROJ_60_mem_A_wea          : t_arr_TPROJ_60_1b;
  signal TPROJ_60_mem_AV_writeaddr   : t_arr_TPROJ_60_ADDR;
  signal TPROJ_60_mem_AV_din         : t_arr_TPROJ_60_DATA;
  signal TPROJ_60_mem_A_enb          : t_arr_TPROJ_60_1b;
  signal TPROJ_60_mem_AV_readaddr    : t_arr_TPROJ_60_ADDR;
  signal TPROJ_60_mem_AV_dout        : t_arr_TPROJ_60_DATA;
  signal TPROJ_60_mem_AAV_dout_nent  : t_arr_TPROJ_60_NENT; -- (#page)
  signal TPROJ_58_mem_A_wea          : t_arr_TPROJ_58_1b;
  signal TPROJ_58_mem_AV_writeaddr   : t_arr_TPROJ_58_ADDR;
  signal TPROJ_58_mem_AV_din         : t_arr_TPROJ_58_DATA;
  signal TPROJ_58_mem_A_enb          : t_arr_TPROJ_58_1b;
  signal TPROJ_58_mem_AV_readaddr    : t_arr_TPROJ_58_ADDR;
  signal TPROJ_58_mem_AV_dout        : t_arr_TPROJ_58_DATA;
  signal TPROJ_58_mem_AAV_dout_nent  : t_arr_TPROJ_58_NENT; -- (#page)
  signal TPAR_70_mem_A_wea          : t_arr_TPAR_70_1b;
  signal TPAR_70_mem_AV_writeaddr   : t_arr_TPAR_70_ADDR;
  signal TPAR_70_mem_AV_din         : t_arr_TPAR_70_DATA;
  signal TPAR_70_mem_A_enb          : t_arr_TPAR_70_1b;
  signal TPAR_70_mem_AV_readaddr    : t_arr_TPAR_70_ADDR;
  signal TPAR_70_mem_AV_dout        : t_arr_TPAR_70_DATA;
  signal FM_52_mem_A_wea          : t_arr_FM_52_1b;
  signal FM_52_mem_AV_writeaddr   : t_arr_FM_52_ADDR;
  signal FM_52_mem_AV_din         : t_arr_FM_52_DATA;
  signal FM_52_mem_A_enb          : t_arr_FM_52_1b;
  signal FM_52_mem_AV_readaddr    : t_arr_FM_52_ADDR;
  signal FM_52_mem_AV_dout        : t_arr_FM_52_DATA;
  signal FM_52_mem_AAV_dout_nent  : t_arr_FM_52_NENT; -- (#page)
  signal IR_done : std_logic := '0';
  signal IR_bx_out : std_logic_vector(2 downto 0);
  signal IR_bx_out_vld : std_logic;
  signal VMR_start : std_logic := '0';
  signal VMR_done : std_logic := '0';
  signal VMR_bx_out : std_logic_vector(2 downto 0);
  signal VMR_bx_out_vld : std_logic;
  signal TP_start : std_logic := '0';
  signal TP_done : std_logic := '0';
  signal TP_bx_out : std_logic_vector(2 downto 0);
  signal TP_bx_out_vld : std_logic;
  signal MP_start : std_logic := '0';
  signal TP_L1L2C_lut_addr       : std_logic_vector(10 downto 0);
  signal TP_L1L2C_lut_ce       : std_logic;
  signal TP_L1L2C_lut_dout : std_logic_vector(9 downto 0);
  signal TP_L1L2C_regionlut_addr       : std_logic_vector(10 downto 0);
  signal TP_L1L2C_regionlut_ce       : std_logic;
  signal TP_L1L2C_regionlut_dout : std_logic_vector(7 downto 0);
  signal MP_done : std_logic := '0';
  signal MP_bx_out : std_logic_vector(2 downto 0);
  signal MP_bx_out_vld : std_logic;
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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

    VMSME_16 : entity work.tf_mem_bin_cm4
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea0       => VMSME_16_mem0_A_wea(var),
        addra0     => VMSME_16_mem0_AV_writeaddr(var),
        dina0      => VMSME_16_mem0_AV_din(var),
        wea1       => VMSME_16_mem1_A_wea(var),
        addra1     => VMSME_16_mem1_AV_writeaddr(var),
        dina1      => VMSME_16_mem1_AV_din(var),
        wea2       => VMSME_16_mem2_A_wea(var),
        addra2     => VMSME_16_mem2_AV_writeaddr(var),
        dina2      => VMSME_16_mem2_AV_din(var),
        wea3       => VMSME_16_mem3_A_wea(var),
        addra3     => VMSME_16_mem3_AV_writeaddr(var),
        dina3      => VMSME_16_mem3_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSME_16_mem0_A_enb(var),
        addrb0     => VMSME_16_mem0_AV_readaddr(var),
        doutb0     => VMSME_16_mem0_AV_dout(var),
        enb1       => VMSME_16_mem1_A_enb(var),
        addrb1     => VMSME_16_mem1_AV_readaddr(var),
        doutb1     => VMSME_16_mem1_AV_dout(var),
        enb2       => VMSME_16_mem2_A_enb(var),
        addrb2     => VMSME_16_mem2_AV_readaddr(var),
        doutb2     => VMSME_16_mem2_AV_dout(var),
        enb3       => VMSME_16_mem3_A_enb(var),
        addrb3     => VMSME_16_mem3_AV_readaddr(var),
        doutb3     => VMSME_16_mem3_AV_dout(var),
        sync_nent => MP_start,
        nent_o    => VMSME_16_mem_AAAV_dout_nent(var),
        mask_o    => VMSME_16_mem_AAV_dout_mask(var)
      );

  end generate VMSME_16_loop;


  VMSME_17_loop : for var in enum_VMSME_17 generate
  begin

    VMSME_17 : entity work.tf_mem_bin_cm4
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea0       => VMSME_17_mem0_A_wea(var),
        addra0     => VMSME_17_mem0_AV_writeaddr(var),
        dina0      => VMSME_17_mem0_AV_din(var),
        wea1       => VMSME_17_mem1_A_wea(var),
        addra1     => VMSME_17_mem1_AV_writeaddr(var),
        dina1      => VMSME_17_mem1_AV_din(var),
        wea2       => VMSME_17_mem2_A_wea(var),
        addra2     => VMSME_17_mem2_AV_writeaddr(var),
        dina2      => VMSME_17_mem2_AV_din(var),
        wea3       => VMSME_17_mem3_A_wea(var),
        addra3     => VMSME_17_mem3_AV_writeaddr(var),
        dina3      => VMSME_17_mem3_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSME_17_mem0_A_enb(var),
        addrb0     => VMSME_17_mem0_AV_readaddr(var),
        doutb0     => VMSME_17_mem0_AV_dout(var),
        enb1       => VMSME_17_mem1_A_enb(var),
        addrb1     => VMSME_17_mem1_AV_readaddr(var),
        doutb1     => VMSME_17_mem1_AV_dout(var),
        enb2       => VMSME_17_mem2_A_enb(var),
        addrb2     => VMSME_17_mem2_AV_readaddr(var),
        doutb2     => VMSME_17_mem2_AV_dout(var),
        enb3       => VMSME_17_mem3_A_enb(var),
        addrb3     => VMSME_17_mem3_AV_readaddr(var),
        doutb3     => VMSME_17_mem3_AV_dout(var),
        sync_nent => MP_start,
        nent_o    => VMSME_17_mem_AAAV_dout_nent(var),
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
      )
      port map (
        clka      => clk,
        wea0       => VMSTE_16_mem0_A_wea(var),
        addra0     => VMSTE_16_mem0_AV_writeaddr(var),
        dina0      => VMSTE_16_mem0_AV_din(var),
        wea1       => VMSTE_16_mem1_A_wea(var),
        addra1     => VMSTE_16_mem1_AV_writeaddr(var),
        dina1      => VMSTE_16_mem1_AV_din(var),
        wea2       => VMSTE_16_mem2_A_wea(var),
        addra2     => VMSTE_16_mem2_AV_writeaddr(var),
        dina2      => VMSTE_16_mem2_AV_din(var),
        wea3       => VMSTE_16_mem3_A_wea(var),
        addra3     => VMSTE_16_mem3_AV_writeaddr(var),
        dina3      => VMSTE_16_mem3_AV_din(var),
        wea4       => VMSTE_16_mem4_A_wea(var),
        addra4     => VMSTE_16_mem4_AV_writeaddr(var),
        dina4      => VMSTE_16_mem4_AV_din(var),
        clkb      => clk,
        rstb      => '0',
        regceb    => '1',
        enb0       => VMSTE_16_mem0_A_enb(var),
        addrb0     => VMSTE_16_mem0_AV_readaddr(var),
        doutb0     => VMSTE_16_mem0_AV_dout(var),
        enb1       => VMSTE_16_mem1_A_enb(var),
        addrb1     => VMSTE_16_mem1_AV_readaddr(var),
        doutb1     => VMSTE_16_mem1_AV_dout(var),
        enb2       => VMSTE_16_mem2_A_enb(var),
        addrb2     => VMSTE_16_mem2_AV_readaddr(var),
        doutb2     => VMSTE_16_mem2_AV_dout(var),
        enb3       => VMSTE_16_mem3_A_enb(var),
        addrb3     => VMSTE_16_mem3_AV_readaddr(var),
        doutb3     => VMSTE_16_mem3_AV_dout(var),
        enb4       => VMSTE_16_mem4_A_enb(var),
        addrb4     => VMSTE_16_mem4_AV_readaddr(var),
        doutb4     => VMSTE_16_mem4_AV_dout(var),
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
        RAM_PERFORMANCE => "HIGH_PERFORMANCE"
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
      memoriesTEO_0_dataarray_0_data_V_we0       => VMSTE_16_mem0_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_0_data_V_address0  => VMSTE_16_mem0_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_0_data_V_d0        => VMSTE_16_mem0_AV_din(L2PHIAn3),
      memoriesTEO_0_dataarray_1_data_V_ce0       => open,
      memoriesTEO_0_dataarray_1_data_V_we0       => VMSTE_16_mem1_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_1_data_V_address0  => VMSTE_16_mem1_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_1_data_V_d0        => VMSTE_16_mem1_AV_din(L2PHIAn3),
      memoriesTEO_0_dataarray_2_data_V_ce0       => open,
      memoriesTEO_0_dataarray_2_data_V_we0       => VMSTE_16_mem2_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_2_data_V_address0  => VMSTE_16_mem2_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_2_data_V_d0        => VMSTE_16_mem2_AV_din(L2PHIAn3),
      memoriesTEO_0_dataarray_3_data_V_ce0       => open,
      memoriesTEO_0_dataarray_3_data_V_we0       => VMSTE_16_mem3_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_3_data_V_address0  => VMSTE_16_mem3_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_3_data_V_d0        => VMSTE_16_mem3_AV_din(L2PHIAn3),
      memoriesTEO_0_dataarray_4_data_V_ce0       => open,
      memoriesTEO_0_dataarray_4_data_V_we0       => VMSTE_16_mem4_A_wea(L2PHIAn3),
      memoriesTEO_0_dataarray_4_data_V_address0  => VMSTE_16_mem4_AV_writeaddr(L2PHIAn3),
      memoriesTEO_0_dataarray_4_data_V_d0        => VMSTE_16_mem4_AV_din(L2PHIAn3)
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
      memoryME_dataarray_0_data_V_we0       => VMSME_16_mem0_A_wea(L3PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_16_mem0_AV_writeaddr(L3PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_16_mem0_AV_din(L3PHIAn1),
      memoryME_dataarray_1_data_V_ce0       => open,
      memoryME_dataarray_1_data_V_we0       => VMSME_16_mem1_A_wea(L3PHIAn1),
      memoryME_dataarray_1_data_V_address0  => VMSME_16_mem1_AV_writeaddr(L3PHIAn1),
      memoryME_dataarray_1_data_V_d0        => VMSME_16_mem1_AV_din(L3PHIAn1),
      memoryME_dataarray_2_data_V_ce0       => open,
      memoryME_dataarray_2_data_V_we0       => VMSME_16_mem2_A_wea(L3PHIAn1),
      memoryME_dataarray_2_data_V_address0  => VMSME_16_mem2_AV_writeaddr(L3PHIAn1),
      memoryME_dataarray_2_data_V_d0        => VMSME_16_mem2_AV_din(L3PHIAn1),
      memoryME_dataarray_3_data_V_ce0       => open,
      memoryME_dataarray_3_data_V_we0       => VMSME_16_mem3_A_wea(L3PHIAn1),
      memoryME_dataarray_3_data_V_address0  => VMSME_16_mem3_AV_writeaddr(L3PHIAn1),
      memoryME_dataarray_3_data_V_d0        => VMSME_16_mem3_AV_din(L3PHIAn1)
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
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem0_A_wea(L4PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_writeaddr(L4PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem0_AV_din(L4PHIAn1),
      memoryME_dataarray_1_data_V_ce0       => open,
      memoryME_dataarray_1_data_V_we0       => VMSME_17_mem1_A_wea(L4PHIAn1),
      memoryME_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_writeaddr(L4PHIAn1),
      memoryME_dataarray_1_data_V_d0        => VMSME_17_mem1_AV_din(L4PHIAn1),
      memoryME_dataarray_2_data_V_ce0       => open,
      memoryME_dataarray_2_data_V_we0       => VMSME_17_mem2_A_wea(L4PHIAn1),
      memoryME_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_writeaddr(L4PHIAn1),
      memoryME_dataarray_2_data_V_d0        => VMSME_17_mem2_AV_din(L4PHIAn1),
      memoryME_dataarray_3_data_V_ce0       => open,
      memoryME_dataarray_3_data_V_we0       => VMSME_17_mem3_A_wea(L4PHIAn1),
      memoryME_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_writeaddr(L4PHIAn1),
      memoryME_dataarray_3_data_V_d0        => VMSME_17_mem3_AV_din(L4PHIAn1)
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
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem0_A_wea(L5PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_writeaddr(L5PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem0_AV_din(L5PHIAn1),
      memoryME_dataarray_1_data_V_ce0       => open,
      memoryME_dataarray_1_data_V_we0       => VMSME_17_mem1_A_wea(L5PHIAn1),
      memoryME_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_writeaddr(L5PHIAn1),
      memoryME_dataarray_1_data_V_d0        => VMSME_17_mem1_AV_din(L5PHIAn1),
      memoryME_dataarray_2_data_V_ce0       => open,
      memoryME_dataarray_2_data_V_we0       => VMSME_17_mem2_A_wea(L5PHIAn1),
      memoryME_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_writeaddr(L5PHIAn1),
      memoryME_dataarray_2_data_V_d0        => VMSME_17_mem2_AV_din(L5PHIAn1),
      memoryME_dataarray_3_data_V_ce0       => open,
      memoryME_dataarray_3_data_V_we0       => VMSME_17_mem3_A_wea(L5PHIAn1),
      memoryME_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_writeaddr(L5PHIAn1),
      memoryME_dataarray_3_data_V_d0        => VMSME_17_mem3_AV_din(L5PHIAn1)
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
      memoryME_dataarray_0_data_V_we0       => VMSME_17_mem0_A_wea(L6PHIAn1),
      memoryME_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_writeaddr(L6PHIAn1),
      memoryME_dataarray_0_data_V_d0        => VMSME_17_mem0_AV_din(L6PHIAn1),
      memoryME_dataarray_1_data_V_ce0       => open,
      memoryME_dataarray_1_data_V_we0       => VMSME_17_mem1_A_wea(L6PHIAn1),
      memoryME_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_writeaddr(L6PHIAn1),
      memoryME_dataarray_1_data_V_d0        => VMSME_17_mem1_AV_din(L6PHIAn1),
      memoryME_dataarray_2_data_V_ce0       => open,
      memoryME_dataarray_2_data_V_we0       => VMSME_17_mem2_A_wea(L6PHIAn1),
      memoryME_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_writeaddr(L6PHIAn1),
      memoryME_dataarray_2_data_V_d0        => VMSME_17_mem2_AV_din(L6PHIAn1),
      memoryME_dataarray_3_data_V_ce0       => open,
      memoryME_dataarray_3_data_V_we0       => VMSME_17_mem3_A_wea(L6PHIAn1),
      memoryME_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_writeaddr(L6PHIAn1),
      memoryME_dataarray_3_data_V_d0        => VMSME_17_mem3_AV_din(L6PHIAn1)
  );


  TP_L1L2C_lut : entity work.tf_lut
    generic map (
      lut_file  => getDirSCRIPT & "LUTs/TP_L1L2.tab",
      lut_width => 10,
      lut_depth => 2048
    )
    port map (
      clk       => clk,
      addr      => TP_L1L2C_lut_addr,
      ce        => TP_L1L2C_lut_ce,
      dout      => TP_L1L2C_lut_dout
  );


  TP_L1L2C_regionlut : entity work.tf_lut
    generic map (
      lut_file  => getDirSCRIPT & "LUTs/TP_L1L2C_usereg.tab",
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
      outerVMStubs_dataarray_data_V_0_ce0       => VMSTE_16_mem0_A_enb(L2PHIAn3),
      outerVMStubs_dataarray_data_V_0_address0  => VMSTE_16_mem0_AV_readaddr(L2PHIAn3),
      outerVMStubs_dataarray_data_V_0_q0        => VMSTE_16_mem0_AV_dout(L2PHIAn3),
      outerVMStubs_dataarray_data_V_1_ce0       => VMSTE_16_mem1_A_enb(L2PHIAn3),
      outerVMStubs_dataarray_data_V_1_address0  => VMSTE_16_mem1_AV_readaddr(L2PHIAn3),
      outerVMStubs_dataarray_data_V_1_q0        => VMSTE_16_mem1_AV_dout(L2PHIAn3),
      outerVMStubs_dataarray_data_V_2_ce0       => VMSTE_16_mem2_A_enb(L2PHIAn3),
      outerVMStubs_dataarray_data_V_2_address0  => VMSTE_16_mem2_AV_readaddr(L2PHIAn3),
      outerVMStubs_dataarray_data_V_2_q0        => VMSTE_16_mem2_AV_dout(L2PHIAn3),
      outerVMStubs_dataarray_data_V_3_ce0       => VMSTE_16_mem3_A_enb(L2PHIAn3),
      outerVMStubs_dataarray_data_V_3_address0  => VMSTE_16_mem3_AV_readaddr(L2PHIAn3),
      outerVMStubs_dataarray_data_V_3_q0        => VMSTE_16_mem3_AV_dout(L2PHIAn3),
      outerVMStubs_dataarray_data_V_4_ce0       => VMSTE_16_mem4_A_enb(L2PHIAn3),
      outerVMStubs_dataarray_data_V_4_address0  => VMSTE_16_mem4_AV_readaddr(L2PHIAn3),
      outerVMStubs_dataarray_data_V_4_q0        => VMSTE_16_mem4_AV_dout(L2PHIAn3),
      outerVMStubs_binmask8_V_0_0     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(0), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(1), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(2), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(3), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(4), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(5), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(6), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(7)),
      outerVMStubs_binmask8_V_0_1     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(8), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(9), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(10), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(11), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(12), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(13), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(14), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(15)),
      outerVMStubs_binmask8_V_0_2     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(16), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(17), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(18), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(19), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(20), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(21), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(22), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(23)),
      outerVMStubs_binmask8_V_0_3     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(24), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(25), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(26), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(27), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(28), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(29), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(30), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(31)),
      outerVMStubs_binmask8_V_0_4     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(32), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(33), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(34), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(35), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(36), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(37), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(38), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(39)),
      outerVMStubs_binmask8_V_0_5     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(40), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(41), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(42), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(43), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(44), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(45), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(46), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(47)),
      outerVMStubs_binmask8_V_0_6     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(48), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(49), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(50), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(51), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(52), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(53), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(54), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(55)),
      outerVMStubs_binmask8_V_0_7     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(56), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(57), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(58), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(59), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(60), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(61), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(62), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(0)(63)),
      outerVMStubs_nentries8_V_0_0     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(0), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(1), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(2), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(3), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(4), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(5), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(6), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(7)),
      outerVMStubs_nentries8_V_0_1     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(8), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(9), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(10), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(11), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(12), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(13), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(14), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(15)),
      outerVMStubs_nentries8_V_0_2     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(16), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(17), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(18), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(19), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(20), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(21), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(22), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(23)),
      outerVMStubs_nentries8_V_0_3     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(24), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(25), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(26), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(27), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(28), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(29), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(30), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(31)),
      outerVMStubs_nentries8_V_0_4     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(32), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(33), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(34), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(35), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(36), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(37), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(38), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(39)),
      outerVMStubs_nentries8_V_0_5     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(40), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(41), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(42), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(43), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(44), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(45), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(46), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(47)),
      outerVMStubs_nentries8_V_0_6     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(48), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(49), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(50), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(51), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(52), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(53), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(54), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(55)),
      outerVMStubs_nentries8_V_0_7     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(56), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(57), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(58), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(59), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(60), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(61), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(62), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(0)(63)),
      outerVMStubs_binmask8_V_1_0     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(0), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(1), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(2), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(3), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(4), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(5), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(6), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(7)),
      outerVMStubs_binmask8_V_1_1     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(8), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(9), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(10), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(11), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(12), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(13), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(14), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(15)),
      outerVMStubs_binmask8_V_1_2     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(16), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(17), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(18), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(19), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(20), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(21), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(22), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(23)),
      outerVMStubs_binmask8_V_1_3     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(24), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(25), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(26), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(27), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(28), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(29), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(30), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(31)),
      outerVMStubs_binmask8_V_1_4     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(32), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(33), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(34), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(35), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(36), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(37), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(38), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(39)),
      outerVMStubs_binmask8_V_1_5     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(40), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(41), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(42), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(43), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(44), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(45), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(46), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(47)),
      outerVMStubs_binmask8_V_1_6     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(48), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(49), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(50), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(51), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(52), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(53), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(54), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(55)),
      outerVMStubs_binmask8_V_1_7     => (VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(56), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(57), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(58), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(59), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(60), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(61), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(62), VMSTE_16_mem_AAV_dout_mask(L2PHIAn3)(1)(63)),
      outerVMStubs_nentries8_V_1_0     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(0), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(1), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(2), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(3), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(4), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(5), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(6), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(7)),
      outerVMStubs_nentries8_V_1_1     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(8), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(9), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(10), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(11), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(12), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(13), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(14), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(15)),
      outerVMStubs_nentries8_V_1_2     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(16), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(17), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(18), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(19), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(20), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(21), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(22), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(23)),
      outerVMStubs_nentries8_V_1_3     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(24), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(25), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(26), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(27), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(28), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(29), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(30), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(31)),
      outerVMStubs_nentries8_V_1_4     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(32), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(33), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(34), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(35), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(36), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(37), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(38), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(39)),
      outerVMStubs_nentries8_V_1_5     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(40), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(41), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(42), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(43), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(44), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(45), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(46), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(47)),
      outerVMStubs_nentries8_V_1_6     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(48), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(49), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(50), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(51), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(52), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(53), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(54), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(55)),
      outerVMStubs_nentries8_V_1_7     => (VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(56), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(57), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(58), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(59), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(60), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(61), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(62), VMSTE_16_mem_AAAV_dout_nent(L2PHIAn3)(1)(63)),
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
      instubdata_dataarray_0_data_V_ce0       => VMSME_16_mem0_A_enb(L3PHIAn1),
      instubdata_dataarray_0_data_V_address0  => VMSME_16_mem0_AV_readaddr(L3PHIAn1),
      instubdata_dataarray_0_data_V_q0        => VMSME_16_mem0_AV_dout(L3PHIAn1),
      instubdata_dataarray_1_data_V_ce0       => VMSME_16_mem1_A_enb(L3PHIAn1),
      instubdata_dataarray_1_data_V_address0  => VMSME_16_mem1_AV_readaddr(L3PHIAn1),
      instubdata_dataarray_1_data_V_q0        => VMSME_16_mem1_AV_dout(L3PHIAn1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_16_mem2_A_enb(L3PHIAn1),
      instubdata_dataarray_2_data_V_address0  => VMSME_16_mem2_AV_readaddr(L3PHIAn1),
      instubdata_dataarray_2_data_V_q0        => VMSME_16_mem2_AV_dout(L3PHIAn1),
      instubdata_dataarray_3_data_V_ce0       => VMSME_16_mem3_A_enb(L3PHIAn1),
      instubdata_dataarray_3_data_V_address0  => VMSME_16_mem3_AV_readaddr(L3PHIAn1),
      instubdata_dataarray_3_data_V_q0        => VMSME_16_mem3_AV_dout(L3PHIAn1),
      instubdata_nentries8_0_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(0),
      instubdata_nentries8_0_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(1),
      instubdata_nentries8_0_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(2),
      instubdata_nentries8_0_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(3),
      instubdata_nentries8_0_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(4),
      instubdata_nentries8_0_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(5),
      instubdata_nentries8_0_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(6),
      instubdata_nentries8_0_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(0)(7),
      instubdata_nentries8_1_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(0),
      instubdata_nentries8_1_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(1),
      instubdata_nentries8_1_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(2),
      instubdata_nentries8_1_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(3),
      instubdata_nentries8_1_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(4),
      instubdata_nentries8_1_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(5),
      instubdata_nentries8_1_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(6),
      instubdata_nentries8_1_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(1)(7),
      instubdata_nentries8_2_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(0),
      instubdata_nentries8_2_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(1),
      instubdata_nentries8_2_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(2),
      instubdata_nentries8_2_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(3),
      instubdata_nentries8_2_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(4),
      instubdata_nentries8_2_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(5),
      instubdata_nentries8_2_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(6),
      instubdata_nentries8_2_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(2)(7),
      instubdata_nentries8_3_V_0     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(0),
      instubdata_nentries8_3_V_1     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(1),
      instubdata_nentries8_3_V_2     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(2),
      instubdata_nentries8_3_V_3     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(3),
      instubdata_nentries8_3_V_4     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(4),
      instubdata_nentries8_3_V_5     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(5),
      instubdata_nentries8_3_V_6     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(6),
      instubdata_nentries8_3_V_7     => VMSME_16_mem_AAAV_dout_nent(L3PHIAn1)(3)(7),
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
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem0_A_enb(L4PHIAn1),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_readaddr(L4PHIAn1),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem0_AV_dout(L4PHIAn1),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem1_A_enb(L4PHIAn1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_readaddr(L4PHIAn1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem1_AV_dout(L4PHIAn1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem2_A_enb(L4PHIAn1),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_readaddr(L4PHIAn1),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem2_AV_dout(L4PHIAn1),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem3_A_enb(L4PHIAn1),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_readaddr(L4PHIAn1),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem3_AV_dout(L4PHIAn1),
      instubdata_nentries8_0_V_0     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(0),
      instubdata_nentries8_0_V_1     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(1),
      instubdata_nentries8_0_V_2     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(2),
      instubdata_nentries8_0_V_3     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(3),
      instubdata_nentries8_0_V_4     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(4),
      instubdata_nentries8_0_V_5     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(5),
      instubdata_nentries8_0_V_6     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(6),
      instubdata_nentries8_0_V_7     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(0)(7),
      instubdata_nentries8_1_V_0     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(0),
      instubdata_nentries8_1_V_1     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(1),
      instubdata_nentries8_1_V_2     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(2),
      instubdata_nentries8_1_V_3     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(3),
      instubdata_nentries8_1_V_4     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(4),
      instubdata_nentries8_1_V_5     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(5),
      instubdata_nentries8_1_V_6     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(6),
      instubdata_nentries8_1_V_7     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(1)(7),
      instubdata_nentries8_2_V_0     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(0),
      instubdata_nentries8_2_V_1     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(1),
      instubdata_nentries8_2_V_2     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(2),
      instubdata_nentries8_2_V_3     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(3),
      instubdata_nentries8_2_V_4     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(4),
      instubdata_nentries8_2_V_5     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(5),
      instubdata_nentries8_2_V_6     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(6),
      instubdata_nentries8_2_V_7     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(2)(7),
      instubdata_nentries8_3_V_0     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(0),
      instubdata_nentries8_3_V_1     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(1),
      instubdata_nentries8_3_V_2     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(2),
      instubdata_nentries8_3_V_3     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(3),
      instubdata_nentries8_3_V_4     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(4),
      instubdata_nentries8_3_V_5     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(5),
      instubdata_nentries8_3_V_6     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(6),
      instubdata_nentries8_3_V_7     => VMSME_17_mem_AAAV_dout_nent(L4PHIAn1)(3)(7),
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
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem0_A_enb(L5PHIAn1),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_readaddr(L5PHIAn1),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem0_AV_dout(L5PHIAn1),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem1_A_enb(L5PHIAn1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_readaddr(L5PHIAn1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem1_AV_dout(L5PHIAn1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem2_A_enb(L5PHIAn1),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_readaddr(L5PHIAn1),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem2_AV_dout(L5PHIAn1),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem3_A_enb(L5PHIAn1),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_readaddr(L5PHIAn1),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem3_AV_dout(L5PHIAn1),
      instubdata_nentries8_0_V_0     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(0),
      instubdata_nentries8_0_V_1     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(1),
      instubdata_nentries8_0_V_2     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(2),
      instubdata_nentries8_0_V_3     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(3),
      instubdata_nentries8_0_V_4     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(4),
      instubdata_nentries8_0_V_5     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(5),
      instubdata_nentries8_0_V_6     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(6),
      instubdata_nentries8_0_V_7     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(0)(7),
      instubdata_nentries8_1_V_0     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(0),
      instubdata_nentries8_1_V_1     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(1),
      instubdata_nentries8_1_V_2     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(2),
      instubdata_nentries8_1_V_3     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(3),
      instubdata_nentries8_1_V_4     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(4),
      instubdata_nentries8_1_V_5     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(5),
      instubdata_nentries8_1_V_6     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(6),
      instubdata_nentries8_1_V_7     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(1)(7),
      instubdata_nentries8_2_V_0     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(0),
      instubdata_nentries8_2_V_1     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(1),
      instubdata_nentries8_2_V_2     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(2),
      instubdata_nentries8_2_V_3     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(3),
      instubdata_nentries8_2_V_4     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(4),
      instubdata_nentries8_2_V_5     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(5),
      instubdata_nentries8_2_V_6     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(6),
      instubdata_nentries8_2_V_7     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(2)(7),
      instubdata_nentries8_3_V_0     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(0),
      instubdata_nentries8_3_V_1     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(1),
      instubdata_nentries8_3_V_2     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(2),
      instubdata_nentries8_3_V_3     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(3),
      instubdata_nentries8_3_V_4     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(4),
      instubdata_nentries8_3_V_5     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(5),
      instubdata_nentries8_3_V_6     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(6),
      instubdata_nentries8_3_V_7     => VMSME_17_mem_AAAV_dout_nent(L5PHIAn1)(3)(7),
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
      instubdata_dataarray_0_data_V_ce0       => VMSME_17_mem0_A_enb(L6PHIAn1),
      instubdata_dataarray_0_data_V_address0  => VMSME_17_mem0_AV_readaddr(L6PHIAn1),
      instubdata_dataarray_0_data_V_q0        => VMSME_17_mem0_AV_dout(L6PHIAn1),
      instubdata_dataarray_1_data_V_ce0       => VMSME_17_mem1_A_enb(L6PHIAn1),
      instubdata_dataarray_1_data_V_address0  => VMSME_17_mem1_AV_readaddr(L6PHIAn1),
      instubdata_dataarray_1_data_V_q0        => VMSME_17_mem1_AV_dout(L6PHIAn1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_17_mem2_A_enb(L6PHIAn1),
      instubdata_dataarray_2_data_V_address0  => VMSME_17_mem2_AV_readaddr(L6PHIAn1),
      instubdata_dataarray_2_data_V_q0        => VMSME_17_mem2_AV_dout(L6PHIAn1),
      instubdata_dataarray_3_data_V_ce0       => VMSME_17_mem3_A_enb(L6PHIAn1),
      instubdata_dataarray_3_data_V_address0  => VMSME_17_mem3_AV_readaddr(L6PHIAn1),
      instubdata_dataarray_3_data_V_q0        => VMSME_17_mem3_AV_dout(L6PHIAn1),
      instubdata_nentries8_0_V_0     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(0),
      instubdata_nentries8_0_V_1     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(1),
      instubdata_nentries8_0_V_2     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(2),
      instubdata_nentries8_0_V_3     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(3),
      instubdata_nentries8_0_V_4     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(4),
      instubdata_nentries8_0_V_5     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(5),
      instubdata_nentries8_0_V_6     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(6),
      instubdata_nentries8_0_V_7     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(0)(7),
      instubdata_nentries8_1_V_0     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(0),
      instubdata_nentries8_1_V_1     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(1),
      instubdata_nentries8_1_V_2     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(2),
      instubdata_nentries8_1_V_3     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(3),
      instubdata_nentries8_1_V_4     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(4),
      instubdata_nentries8_1_V_5     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(5),
      instubdata_nentries8_1_V_6     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(6),
      instubdata_nentries8_1_V_7     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(1)(7),
      instubdata_nentries8_2_V_0     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(0),
      instubdata_nentries8_2_V_1     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(1),
      instubdata_nentries8_2_V_2     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(2),
      instubdata_nentries8_2_V_3     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(3),
      instubdata_nentries8_2_V_4     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(4),
      instubdata_nentries8_2_V_5     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(5),
      instubdata_nentries8_2_V_6     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(6),
      instubdata_nentries8_2_V_7     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(2)(7),
      instubdata_nentries8_3_V_0     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(0),
      instubdata_nentries8_3_V_1     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(1),
      instubdata_nentries8_3_V_2     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(2),
      instubdata_nentries8_3_V_3     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(3),
      instubdata_nentries8_3_V_4     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(4),
      instubdata_nentries8_3_V_5     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(5),
      instubdata_nentries8_3_V_6     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(6),
      instubdata_nentries8_3_V_7     => VMSME_17_mem_AAAV_dout_nent(L6PHIAn1)(3)(7),
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
