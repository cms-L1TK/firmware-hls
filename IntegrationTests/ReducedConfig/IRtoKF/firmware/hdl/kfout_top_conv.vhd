library ieee;
use ieee.std_logic_1164.all;

use work.kfout_data_formats.all;
use work.kfout_config.all;
use work.DataType.all;
use work.ArrayTypes.all;

use work.emp_data_types.all;
use work.hybrid_config.all;
use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;


entity kfout_top_conv is
  port (
    clk        : in  std_logic;
    kfout_din  : in  t_channelsKF(numNodesKF - 1 downto 0);
    kfout_dout : out t_frames(numLinksTFP - 1 downto 0)
    );
end;


architecture rtl of kfout_top_conv is

  component conv96to64 is
    port (
      clk_i           : in  std_logic;
      rst_i           : in  std_logic;
      sorted_tracks_i : in  vector;
      packet_data_o   : out t_frames);
  end component conv96to64;

  constant reset_delay        : integer := 29;
  constant router_reset_delay : integer := 8;

  signal TTTracks     : Vector(numNodesKF -1 downto 0)            := NullVector(numNodesKF);
  signal TTTracksTQ   : Vector(numOutLinks -1 downto 0)           := NullVector(numOutLinks);
  signal SortedTracks : Vector(numOutLinks -1 downto 0)           := NullVector(numOutLinks);
  signal Reset        : std_logic_vector(0 to reset_delay - 1)    := (others => '0');
  signal PacketData   : PacketArray(numOutLinks -1 downto 0)      := (others => (others => '0'));
  signal PacketValid  : std_logic_vector(numOutLinks -1 downto 0) := (others => '0');

begin

  process (clk)
  begin
    if RISING_EDGE(clk) then
      Reset <= kfout_din(0).track.reset & Reset(0 to reset_delay - 2);
    end if;
  end process;

-- ------------------------------------------------------------------------
-- Convert KF tracks and KF stubs to TTTracks
  TrackTransformInstance : entity work.kfout_trackTransform
    port map(
      clk         => clk,
      KFObjectsIn => kfout_din,
      TTTracksOut => TTTracks
      );
-- ------------------------------------------------------------------------
-- ------------------------------------------------------------------------
-- Convert Route TTTracks in Eta
  RouterInstance : entity work.kfout_router
    port map(
      clk     => clk,
      reset   => reset(router_reset_delay - 1),
      DataIn  => TTTracks,
      DataOut => SortedTracks
      );
----------------------------------------------------------------------
-------------------------------------------------------------------
-- ------------------------------------------------------------------------
-- Run Track Quality BDT 
  TrackQualityInstance : entity work.kfout_trackQuality
    port map(
      clk         => clk,
      TTTracksIn  => SortedTracks,
      TTTracksOut => TTTracksTQ
      );
-- Output 64-bit partial tracks in correct link structure
-- OutObjectsToPacketsInstance : ENTITY work.kfout_outObjectsToPackets
-- PORT MAP(
--   clk                 => clk ,
--   reset               => reset( reset_delay - 1 ),
--   sortedtracks        => TTTracksTQ,
--   packetdata          => kfout_dout
-- );
  conv96to64_1 : conv96to64
    port map (
      clk_i           => clk,
      rst_i           => reset(reset_delay - 1),
      sorted_tracks_i => TTTracksTQ,
      packet_data_o   => kfout_dout
      );
-- ------------------------------------------------------------------------
-- ------------------------------------------------------------------------
end rtl;
