library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;
use work.ipbus.all;
use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;
use work.emp_ttc_decl.all;
use work.emp_slink_types.all;
-- TF
use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f1.all;
use work.hybrid_data_types.all;
use work.conv_pkg_f1.all;

entity emp_payload is
  port(
    clk         : in  std_logic;        -- ipbus signals
    rst         : in  std_logic;
    ipb_in      : in  ipb_wbus;
    ipb_out     : out ipb_rbus;
    clk40       : in  std_logic;
    clk_payload : in  std_logic_vector(2 downto 0);
    rst_payload : in  std_logic_vector(2 downto 0);
    clk_p       : in  std_logic;        -- data clock
    rst_loc     : in  std_logic_vector(N_REGION - 1 downto 0);
    clken_loc   : in  std_logic_vector(N_REGION - 1 downto 0);
    ctrs        : in  ttc_stuff_array;
    bc0         : out std_logic;
    d           : in  ldata(4 * N_REGION - 1 downto 0);  -- data in
    q           : out ldata(4 * N_REGION - 1 downto 0);  -- data out
    gpio        : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector
    gpio_en     : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector (three-state enables)
    slink_q : out slink_input_data_quad_array(SLINK_MAX_QUADS-1 downto 0);
    backpressure : in std_logic_vector(SLINK_MAX_QUADS-1 downto 0)
    );

end emp_payload;

architecture rtl of emp_payload is

  signal s_IR_data             : t_arr_DL_39_DATA;
  signal s_ir_start            : std_logic;
  signal s_bx                  : std_logic_vector(2 downto 0);
  signal tp_bx                 : std_logic_vector(2 downto 0);
  signal s_TP_bx_out_vld       : std_logic;
  signal AS_37_stream          : t_arr_AS_37_DATA;
  signal MPAR_76_stream        : t_arr_MPAR_76_DATA;

begin

  -----------------------------------------------------------------------------
  -- EMP ports
  -----------------------------------------------------------------------------
  slink_q <= (others => SLINK_INPUT_DATA_ARRAY_NULL);
  gpio    <= (others => '0');
  gpio_en <= (others => '0');
  ipb_out <= IPB_RBUS_NULL;
  bc0     <= '0';

  -----------------------------------------------------------------------------
  -- Link to Sector Processor formatter
  -----------------------------------------------------------------------------
  linktosecproc_1 : entity work.linktosecproc
    port map (
      clk_i                => clk_p,
      rst_i                => rst,
      ttc_i                => ctrs,
      din_i                => d,
      ir_start_o           => s_ir_start,
      bx_o                 => s_bx,
      DL_39_link_AV_dout   => s_IR_data,
      DL_39_link_empty_neg => open,
      DL_39_link_read      => (others => '0')
      );

  -----------------------------------------------------------------------------
  -- Sector Processor 
  -----------------------------------------------------------------------------
  tf1_wrapper_1 : entity work.tf1_wrapper
    port map (
      clk                      => clk_p,
      reset                    => rst,
      IR_start                 => s_ir_start,
      IR_bx_in                 => s_bx,
      TP_bx_out_0              => tp_bx,
      TP_bx_out_vld            => s_TP_bx_out_vld,
      TP_done                  => open,
      DL_39_link_AV_dout       => s_IR_data,
      DL_39_link_empty_neg     => (others => '1'),
      DL_39_link_read          => open,
      AS_37_stream_V_dout      => AS_37_stream,
      MPAR_76_stream_V_dout    => MPAR_76_stream
      );

  -----------------------------------------------------------------------------
  -- Link formatter
  -----------------------------------------------------------------------------
  secproc1tolink_1 : entity work.secproc1tolink
    port map (
      clk                      => clk_p,
      rst                      => rst,
      TP_bx_out                => tp_bx,
      AS_37_stream_V_dout      => AS_37_stream,
      MPAR_76_stream_V_dout    => MPAR_76_stream,
      node_packet              => conv_single(d),
      q                        => q
      );

end rtl;
