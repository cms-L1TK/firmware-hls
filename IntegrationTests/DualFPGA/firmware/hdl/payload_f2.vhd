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

  signal AS_36_link_data   : t_arr_AS_36_37b;
  signal MPAR_73_link_data : t_arr_MTPAR_73_76b;
  signal bx_link_data      : std_logic_vector(2 downto 0);

  signal PC_start          : std_logic;
  signal PC_bx_in          : std_logic_vector(2 downto 0);
  signal AS_36_wea         : t_arr_AS_36_1b;
  signal AS_36_writeaddr   : t_arr_AS_36_ADDR;
  signal AS_36_din         : t_arr_AS_36_DATA;
  signal MPAR_73_wea       : t_arr_MTPAR_73_1b;
  signal MPAR_73_writeaddr : t_arr_MTPAR_73_ADDR;
  signal MPAR_73_din       : t_arr_MTPAR_73_DATA;
  signal s_tftokf          : t_channlesTB(numTW_104 - 1 downto 0);
  signal s_kfin            : t_channlesTB(numNodesKF - 1 downto 0);
  signal s_kfout           : t_frames(numLinksTFP - 1 downto 0);
  signal s_tfout           : ldata(numLinksTFP - 1 downto 0);
  signal FT_bx_out_0       : std_logic_vector(2 downto 0);
  signal FT_bx_out_vld     : std_logic;
  signal FT_done           : std_logic;
  signal FT_last_track     : std_logic;
  signal FT_last_track_vld : std_logic;
  signal TW_104_stream_AV_din  : t_arr_TW_104_DATA;
  signal TW_104_stream_A_write : t_arr_TW_104_1b;
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
      clk               => clk_p,
      rst               => rst,
      d                 => d,
      AS_36_link_data   => AS_36_link_data,
      MPAR_73_link_data => MPAR_73_link_data,
      bx_link_data      => bx_link_data
      );

  -----------------------------------------------------------------------------
  -- Drive memory writes for SectorProcessor
  -----------------------------------------------------------------------------
  sp2_mem_writer_1 : entity work.sp2_mem_writer
    port map (
      clk               => clk_p,
      reset             => rst,
      bx_link_data      => bx_link_data,
      AS_36_link_data   => AS_36_link_data,
      MPAR_73_link_data => MPAR_73_link_data,
      AS_36_wea         => AS_36_wea,
      AS_36_writeaddr   => AS_36_writeaddr,
      AS_36_din         => AS_36_din,
      MPAR_73_wea       => MPAR_73_wea,
      MPAR_73_writeaddr => MPAR_73_writeaddr,
      MPAR_73_din       => MPAR_73_din,
      PC_start          => PC_start,
      PC_bx_in          => PC_bx_in
      );

  -----------------------------------------------------------------------------
  -- FPGA2 Sector Processor (PC/VMSMER -> MP -> TB)
  -----------------------------------------------------------------------------
  tf2_wrapper_1 : entity work.tf2_wrapper
    port map (
      clk                       => clk_p,
      reset                     => rst,
      start_first_write         => '0',
      PC_start                  => PC_start,
      PC_bx_in                  => PC_bx_in,
      FT_bx_out_0               => FT_bx_out_0,
      FT_bx_out_vld             => FT_bx_out_vld,
      FT_done                   => FT_done,
      FT_last_track             => FT_last_track,
      FT_last_track_vld         => FT_last_track_vld,
      AS_36_wea                 => AS_36_wea,
      AS_36_writeaddr           => AS_36_writeaddr,
      AS_36_din                 => AS_36_din,
      MPAR_73_wea               => MPAR_73_wea,
      MPAR_73_writeaddr         => MPAR_73_writeaddr,
      MPAR_73_din               => MPAR_73_din,
      TW_104_stream_AV_din      => TW_104_stream_AV_din,
      TW_104_stream_A_full_neg  => (others => '1'),
      TW_104_stream_A_write     => TW_104_stream_A_write,
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
      TW_104_data_i  => TW_104_stream_AV_din,
      TW_104_valid_i => TW_104_stream_A_write,
      DW_49_data_i   => DW_49_stream_AV_din,
      DW_49_valid_i  => DW_49_stream_A_write,
      BW_46_data_i   => BW_46_stream_AV_din,
      BW_46_valid_i  => BW_46_stream_A_write,
      kf_reset_i     => FT_bx_out_vld,
      tftokf_o       => s_tftokf
      );

  -----------------------------------------------------------------------------
  -- KF Input merger (to be replaced by DR)
  -----------------------------------------------------------------------------
  kf_input_merger_1 : entity work.kf_input_merger
    port map (
      clk            => clk_p,
      din            => s_tftokf,
      dout           => s_kfin
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
      out_packet => conv(d),
      out_din    => s_kfout,
      out_dout   => s_tfout
      );

  q(108)        <= s_tfout(0);
  q(109)        <= s_tfout(1);

  ---- This example code sends 156-word-long TMUX18 packets (i.e. same packet length as track finder output)
  ---- with channel index, packet index, and word index embedded in the data word
  --gen : for i in N_REGION * 4 - 1 downto 0 generate

  --  -- Index of word within a packet
  --  signal word_index : std_logic_vector(7 downto 0) := x"00";
  --  -- Index of packet within an orbit
  --  signal packet_index : std_logic_vector(8 downto 0) := "000000000";

  --begin

  --  process (clk_p)
  --  begin
  --    if rising_edge(clk_p) then
  --      -- Reset counters on receiving BC0 from TCDS
  --      if (ctrs(i/4).bctr = x"000") and (ctrs(i/4).pctr = "0000") then
  --        word_index <= x"00";
  --        packet_index <= "000000000";
  --      -- Reset word index and increment packet index every 162 clock cycles (TMUX18: 18BX * 9 clocks/BX)
  --      elsif word_index = x"A1" then
  --        word_index <= x"00";
  --        packet_index <= std_logic_vector(unsigned(packet_index) + 1);
  --      else
  --        word_index <= std_logic_vector(unsigned(word_index) + 1);
  --      end if;
  --    end if;
  --  end process;

  --  -- Set valid high for full duration of packet
  --  q(i).valid <= '1' when word_index <= x"9B" else '0';
  --  -- Start & last are only high for first & last clock cycle of packet
  --  q(i).start <= '1' when word_index = x"00" else '0';
  --  q(i).last <= '1' when word_index = x"9B" else '0';

  --  -- Start of orbit is high in the first clock cycle of the first packet in orbit - though in final system this should instead
  --  -- be high in the first clock cycle of the packet containing the data from BX0 (or BXn in time slice n of a TMUX system)
  --  q(i).start_of_orbit <= '1' when ((word_index = x"00") and (packet_index = "000000000")) else '0';

  --  -- Data word: Bits 63 to 32 = channel index; bits 31 to 16 = packet index; bits 15 to 0 = word index.
  --  q(i).data(63 downto 32) <= std_logic_vector(to_unsigned(i, 32));
  --  q(i).data(31 downto 16) <= "0000000" & packet_index;
  --  q(i).data(15 downto 0) <= x"00" & word_index;

  --end generate gen;

end rtl;
