-- dummy project for testing
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.ipbus.all;
use work.emp_data_types.all;
use work.emp_project_decl.all;

use work.emp_device_decl.all;
use work.emp_ttc_decl.all;

use work.emp_slink_types.all;

use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;
use work.tf_interface_pkg.all;
use work.hybrid_data_types.all;
use work.hybrid_config.all;
use work.hybrid_data_formats.all;

entity emp_payload is
  port(
    clk          : in  std_logic;        -- ipbus signals
    rst          : in  std_logic;
    ipb_in       : in  ipb_wbus;
    ipb_out      : out ipb_rbus;
    clk40        : in  std_logic;
    clk_payload  : in  std_logic_vector(2 downto 0);
    rst_payload  : in  std_logic_vector(2 downto 0);
    clk_p        : in  std_logic;        -- data clock
    rst_loc      : in  std_logic_vector(N_REGION - 1 downto 0);
    clken_loc    : in  std_logic_vector(N_REGION - 1 downto 0);
    ctrs         : in  ttc_stuff_array;
    bc0          : out std_logic;
    d            : in  ldata(4 * N_REGION - 1 downto 0);  -- data in
    q            : out ldata(4 * N_REGION - 1 downto 0);  -- data out
    gpio         : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector
    gpio_en      : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector (three-state enables)
    slink_q      : out slink_input_data_quad_array(SLINK_MAX_QUADS-1 downto 0);
    backpressure : in std_logic_vector(SLINK_MAX_QUADS-1 downto 0)
    );

end emp_payload;

architecture rtl of emp_payload is

  signal AS_36_link_data       : t_arr_AS_36_37b;
  signal MPAR_73_link_data     : t_arr_MTPAR_73_76b;
  signal AS_36_link_valid      : t_arr_AS_36_1b;
  signal MPAR_73_link_valid    : t_arr_MTPAR_73_1b;
  signal bx_link_data          : std_logic_vector(2 downto 0);
  signal bx_link_valid         : std_logic;
  signal PC_start              : std_logic;
  signal PC_bx_in              : std_logic_vector(2 downto 0);
  signal AS_36_wea             : t_arr_AS_36_1b;
  signal AS_36_writeaddr       : t_arr_AS_36_ADDR;
  signal AS_36_din             : t_arr_AS_36_DATA;
  signal MPAR_73_wea           : t_arr_MTPAR_73_1b;
  signal MPAR_73_writeaddr     : t_arr_MTPAR_73_ADDR;
  signal MPAR_73_din           : t_arr_MTPAR_73_DATA;
  signal s_tftokf              : t_channlesTB(numTW_104 - 1 downto 0);
  signal s_kfin                : t_channlesTB(numNodesKF - 1 downto 0);
  signal s_kfout               : t_frames(numLinksTFP - 1 downto 0);
  signal s_tfout               : ldata(numLinksTFP - 1 downto 0);
  signal TB_bx_out_0           : std_logic_vector(2 downto 0);
  signal TB_bx_out_vld         : std_logic;
  signal TB_done               : std_logic;
  signal TB_last_track         : std_logic;
  signal TB_last_track_vld     : std_logic;
  signal TW_113_stream_AV_din  : t_arr_TW_113_DATA;
  signal TW_113_stream_A_write : t_arr_TW_113_1b;
  signal DW_49_stream_AV_din   : t_arr_DW_49_DATA;
  signal DW_49_stream_A_write  : t_arr_DW_49_1b;
  signal BW_46_stream_AV_din   : t_arr_BW_46_DATA;
  signal BW_46_stream_A_write  : t_arr_BW_46_1b;

begin

  -----------------------------------------------------------------------------
  -- Link to Sector Processor Formatter
  -----------------------------------------------------------------------------
  linktosecproc2_1 : entity work.linktosecproc2
    port map (
      clk                => clk_p,
      rst                => rst,
      d                  => d,
      AS_36_link_data    => AS_36_link_data,
      MPAR_73_link_data  => MPAR_73_link_data,
      bx_link_data       => bx_link_data,
      AS_36_link_valid   => AS_36_link_valid,
      MPAR_73_link_valid => MPAR_73_link_valid,
      bx_link_valid      => bx_link_valid
      );

  -----------------------------------------------------------------------------
  -- Drive memory writes for SectorProcessor
  -----------------------------------------------------------------------------
  sp2_mem_writer_1 : entity work.sp2_mem_writer
    port map (
      clk                => clk_p,
      reset              => rst,
      AS_36_link_data    => AS_36_link_data,
      MPAR_73_link_data  => MPAR_73_link_data,
      bx_link_data       => bx_link_data,
      AS_36_link_valid   => AS_36_link_valid,
      MPAR_73_link_valid => MPAR_73_link_valid,
      bx_link_valid      => bx_link_valid,
      AS_36_wea          => AS_36_wea,
      AS_36_writeaddr    => AS_36_writeaddr,
      AS_36_din          => AS_36_din,
      MPAR_73_wea        => MPAR_73_wea,
      MPAR_73_writeaddr  => MPAR_73_writeaddr,
      MPAR_73_din        => MPAR_73_din,
      PC_start           => PC_start,
      PC_bx_in           => PC_bx_in
      );

  -----------------------------------------------------------------------------
  -- FPGA2 Sector Processor (PC/VMSMER -> MP -> TB)
  -----------------------------------------------------------------------------
  tf2_wrapper_1 : entity work.tf2_wrapper
    port map (
      clk                       => clk_p,
      reset                     => rst,
      PC_start                  => PC_start,
      PC_bx_in                  => PC_bx_in,
      PC_bx_out                 => open,
      PC_bx_out_vld             => open,
      PC_done                   => open,
      TB_bx_out                 => TB_bx_out_0,
      TB_bx_out_vld             => TB_bx_out_vld,
      TB_done                   => TB_done,
      TB_last_track             => TB_last_track,
      TB_last_track_vld         => TB_last_track_vld,
      AS_36_wea                 => AS_36_wea,
      AS_36_writeaddr           => AS_36_writeaddr,
      AS_36_din                 => AS_36_din,
      MPAR_73_wea               => MPAR_73_wea,
      MPAR_73_writeaddr         => MPAR_73_writeaddr,
      MPAR_73_din               => MPAR_73_din,
      TW_113_stream_AV_din      => TW_113_stream_AV_din,
      TW_113_stream_A_full_neg  => (others => '1'),
      TW_113_stream_A_write     => TW_113_stream_A_write,
      DW_49_stream_AV_din       => DW_49_stream_AV_din,
      DW_49_stream_A_full_neg   => (others => '1'),
      DW_49_stream_A_write      => DW_49_stream_A_write,
      BW_46_stream_AV_din       => BW_46_stream_AV_din,
      BW_46_stream_A_full_neg   => (others => '1'),
      BW_46_stream_A_write      => BW_46_stream_A_write
      );

  -----------------------------------------------------------------------------
  -- Sector Processor to KF formatter
  -----------------------------------------------------------------------------
  tf_to_kf_1 : entity work.tf_to_kf
    port map (
      clk_i          => clk_p,
      TW_113_data_i  => TW_113_stream_AV_din,
      TW_113_valid_i => TW_113_stream_A_write,
      DW_49_data_i   => DW_49_stream_AV_din,
      DW_49_valid_i  => DW_49_stream_A_write,
      BW_46_data_i   => BW_46_stream_AV_din,
      BW_46_valid_i  => BW_46_stream_A_write,
      kf_reset_i     => TB_bx_out_vld,
      tftokf_o       => s_kfin
      );

  -----------------------------------------------------------------------------
  -- KF
  -----------------------------------------------------------------------------
  kf_wrapper_1 : entity work.kf_wrapper
    port map (
      clk_i   => clk_p,
      kfin_i  => s_kfin,
      kfout_o => s_kfout
      );

  -----------------------------------------------------------------------------
  -- Output step
  -----------------------------------------------------------------------------
  kfout_isolation_out_1 : entity work.kfout_isolation_out
    port map (
      clk        => clk_p,
      out_packet => conv_f2(d),
      out_din    => s_kfout,
      out_dout   => s_tfout
      );

  q(92)        <= s_tfout(0);
  q(93)        <= s_tfout(1);

end rtl;
