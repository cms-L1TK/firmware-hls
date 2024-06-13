--===========================================================================
--! @file kf_input_merger.vhd
--! @brief Temporary module to merge input to KF until DR is ready
--! @author Michael Oshiro <mco62@cornell.edu>
--! @date 2024-05-14
--! @version v.1.0
--===========================================================================

 --TODO: move some of this kludge to separate files

--BEGIN Common Types

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.tf_interface_pkg.all;
use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_config.all;

package KfMergeTypes is
 constant width_tracktb   : natural := (2 + widthTBseedType + widthTBinv2R +
                                        widthTBphi0 + widthTBz0 + widthTBcot);
 constant width_stubtb    : natural := (2 + widthTBtrackId + widthTBstubId +
                                        widthTBr + widthTBphi + widthTBz);
 constant width_channeltb : natural := (width_tracktb + (width_stubtb * maxNumProjectionLayers));
 constant width_stubstb   : natural := width_stubtb * maxNumProjectionLayers;
end KfMergeTypes;

--END Common Types

--BEGIN RAM

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.tf_interface_pkg.all;
use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_config.all;

use work.KfMergeTypes.all;


entity kf_merge_ram is
  generic (
    depth        : natural := 54
  );
  port (
    clk          : in std_logic;
    rst          : in std_logic;
    din          : in std_logic_vector(width_channeltb-1 downto 0);
    write_enable : in boolean;
    read_enable  : in boolean;
    empty        : out boolean;
    dout         : out std_logic_vector(width_channeltb-1 downto 0)
    );
end entity kf_merge_ram;

architecture rtl of kf_merge_ram is

  type t_ram is array(0 to depth-1) of std_logic_vector(width_channeltb-1 downto 0);

  signal ram                 : t_ram := (others => (others => '0' ));
  attribute ram_style        : string;
  attribute ram_style of ram : signal is "block";
  signal write_address       : integer range 0 to depth-1;
  signal read_address        : integer range 0 to depth-1;
  signal full                : boolean;

begin

  process_ramwrite : process (clk) is
  begin
    if (rising_edge(clk)) then

      --assign addresses and ram
      if (rst = '1') then
        write_address <= 0;
        read_address <= 0;
      elsif (write_enable and (not read_enable) and (not full)) then
        ram(write_address) <= din;
        write_address <= write_address + 1;
        read_address <= write_address;
      elsif (read_enable and not write_enable) then
        write_address <= write_address - 1;
        read_address <= write_address;
      end if; 

      --assign dout 
      if (write_enable and read_enable) then
        dout <= din;
      else
        dout <= ram(read_address);
      end if;

    end if; --rising_edge(clk)
  end process;

  empty <= true when write_address = 0 else false;
  full <= true when write_address = (depth-1) else false;
  
end architecture rtl;

--END RAM

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.tf_interface_pkg.all;
use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_config.all;

use work.KfMergeTypes.all;

--BEGIN WRAPPER

entity kf_input_merger is
  port (
    clk       : in std_logic;
    din       : in t_channlesTB(numTW_104 - 1 downto 0);
    dout      : out t_channlesTB(numNodesKF - 1 downto 0)
    );
end entity kf_input_merger;

architecture rtl of kf_input_merger is

 constant loc_cot          : natural := width_stubstb;
 constant loc_z0           : natural := width_stubstb+widthTBcot; 
 constant loc_phi0         : natural := width_stubstb+widthTBcot+widthTBz0; 
 constant loc_inv2r        : natural := width_stubstb+widthTBcot+widthTBz0+widthTBphi0;
 constant loc_seedtype     : natural := width_stubstb+widthTBcot+widthTBz0+widthTBphi0+widthTBinv2R;
 constant loc_valid        : natural := width_stubstb+widthTBcot+widthTBz0+widthTBphi0+widthTBinv2R+widthTBseedType;
 constant loc_reset        : natural := width_stubstb+widthTBcot+widthTBz0+widthTBphi0+widthTBinv2R+widthTBseedType+1;

 constant loc_stub_phi     : natural := widthTBz;
 constant loc_stub_r       : natural := widthTBz+widthTBphi;
 constant loc_stub_stubid  : natural := widthTBz+widthTBphi+widthTBr;
 constant loc_stub_trackid : natural := widthTBz+widthTBphi+widthTBr+widthTBstubId;
 constant loc_stub_valid   : natural := widthTBz+widthTBphi+widthTBr+widthTBstubId+widthTBtrackId;
 constant loc_stub_reset   : natural := widthTBz+widthTBphi+widthTBr+widthTBstubId+widthTBtrackId+1;

 function tchanneltb_to_stdlogicvector (tb_data : t_channelTB) return std_logic_vector is
   variable ret : std_logic_vector(width_channeltb-1 downto 0) := (others => '0');
 begin
   ret(loc_reset)                       := tb_data.track.reset;
   ret(loc_valid)                       := tb_data.track.valid;
   ret(loc_valid-1 downto loc_seedtype) := tb_data.track.seedType;
   ret(loc_seedtype-1 downto loc_inv2r) := tb_data.track.inv2R;
   ret(loc_inv2r-1 downto loc_phi0)     := tb_data.track.phi0;
   ret(loc_phi0-1 downto loc_z0)        := tb_data.track.z0;
   ret(loc_z0-1 downto loc_cot)         := tb_data.track.cot;
   for istub in 0 to maxNumProjectionLayers-1 loop
     ret(loc_stub_reset+(istub*width_stubtb))                                             := tb_data.stubs(istub).reset;
     ret(loc_stub_valid+(istub*width_stubtb))                                             := tb_data.stubs(istub).valid;
     ret(loc_stub_valid-1+istub*width_stubtb downto loc_stub_trackid+istub*width_stubtb)  := tb_data.stubs(istub).trackId;
     ret(loc_stub_trackid-1+istub*width_stubtb downto loc_stub_stubid+istub*width_stubtb) := tb_data.stubs(istub).stubId;
     ret(loc_stub_stubid-1+istub*width_stubtb downto loc_stub_r+istub*width_stubtb)       := tb_data.stubs(istub).r;
     ret(loc_stub_r-1+istub*width_stubtb downto loc_stub_phi+istub*width_stubtb)          := tb_data.stubs(istub).phi;
     ret(loc_stub_phi-1+istub*width_stubtb downto istub*width_stubtb)                     := tb_data.stubs(istub).z;
   end loop;
   return ret;
 end function;

 function stdlogicvector_to_tchanneltb (ram_data : std_logic_vector) return t_channelTB is
   variable ret : t_channelTB;
 begin
   ret.track.reset    := ram_data(loc_reset);
   ret.track.valid    := ram_data(loc_valid);
   ret.track.seedType := ram_data(loc_valid-1 downto loc_seedtype);
   ret.track.inv2R    := ram_data(loc_seedtype-1 downto loc_inv2r);
   ret.track.phi0     := ram_data(loc_inv2r-1 downto loc_phi0);
   ret.track.z0       := ram_data(loc_phi0-1 downto loc_z0);
   ret.track.cot      := ram_data(loc_z0-1 downto loc_cot);
   for istub in 0 to maxNumProjectionLayers-1 loop
     ret.stubs(istub).reset   := ram_data(loc_stub_reset+(istub*width_stubtb));
     ret.stubs(istub).valid   := ram_data(loc_stub_valid+(istub*width_stubtb));
     ret.stubs(istub).trackId := ram_data(loc_stub_valid-1+istub*width_stubtb downto loc_stub_trackid+istub*width_stubtb);
     ret.stubs(istub).stubId  := ram_data(loc_stub_trackid-1+istub*width_stubtb downto loc_stub_stubid+istub*width_stubtb);
     ret.stubs(istub).r       := ram_data(loc_stub_stubid-1+istub*width_stubtb downto loc_stub_r+istub*width_stubtb);
     ret.stubs(istub).phi     := ram_data(loc_stub_r-1+istub*width_stubtb downto loc_stub_phi+istub*width_stubtb);
     ret.stubs(istub).z       := ram_data(loc_stub_phi-1+istub*width_stubtb downto istub*width_stubtb);
   end loop;
   return ret;
 end function;

 --these RAMs are really wide (~500 bits) so want as little depth as possible
 constant ram_depth : integer := 54; 
 subtype t_address is integer range 0 to ram_depth-1;
 type t_arr_address is array(0 to din'length-1) of t_address;
 type t_arr_bool is array(0 to din'length-1) of boolean;
 type t_arr_ramdata is array(0 to din'length-1) of std_logic_vector(width_channeltb-1 downto 0);

 signal write_enable : t_arr_bool;
 signal read_enable  : t_arr_bool;
 signal ram_empty    : t_arr_bool;

 --signal write_addr   : t_arr_address;
 --signal read_addr    : t_arr_address;
 signal ram_in       : t_channlesTB(numTW_104 - 1 downto 0);
 signal ram_out_raw  : t_arr_ramdata;
 signal ram_out      : t_channlesTB(numTW_104 - 1 downto 0);

 signal bx_change    : std_logic;

 --this defines merging scheme
 --currently merge first 4 seeds (L1L2, L2L3, L3L4, L5L6) 
 --and second 4 seeds (D1D2, D3D4, L1D1, L2D1)
 type t_kf_mergesubscheme is array(0 to 3) of integer range 0 to 7;
 type t_kf_mergescheme is array(0 to 1) of t_kf_mergesubscheme;
 constant seed_merge : t_kf_mergescheme := ((0,1,2,3),
                                            (4,5,6,7));

begin

  bx_change <= din(0).track.reset;

  -- generate RAMs
  generate_ram : for iseedtype in 0 to (din'length-1) generate
    ram_1 : entity work.kf_merge_ram
    generic map(
      depth        => ram_depth
      )
    port map(
      clk          => clk,
      rst          => bx_change,
      din          => tchanneltb_to_stdlogicvector(ram_in(iseedtype)),
      write_enable => write_enable(iseedtype),
      read_enable  => read_enable(iseedtype),
      empty        => ram_empty(iseedtype),
      dout         => ram_out_raw(iseedtype)
      );
    ram_out(iseedtype) <= stdlogicvector_to_tchanneltb(ram_out_raw(iseedtype));
  end generate generate_ram;

  -- handle writing to RAMs
  process_ramwrite : process (clk) is
  begin
    if (rising_edge(clk)) then
      for iseedtype in 0 to (din'length-1) loop
        if (din(iseedtype).track.valid = '1') then
          ram_in(iseedtype)       <= din(iseedtype);
          write_enable(iseedtype) <= true;
        else
          write_enable(iseedtype) <= false;
        end if;
      end loop;
    end if;
  end process;

  -- handle reading from RAMs
  process_ramread : process (clk) is
  begin
    if (rising_edge(clk)) then
      for ikfchannel in 0 to (numNodesKF-1) loop 
        if not ram_empty(seed_merge(ikfchannel)(0)) then
          dout(ikfchannel)                       <= ram_out(seed_merge(ikfchannel)(0));
          read_enable(seed_merge(ikfchannel)(0)) <= true;
          read_enable(seed_merge(ikfchannel)(1)) <= false;
          read_enable(seed_merge(ikfchannel)(2)) <= false;
          read_enable(seed_merge(ikfchannel)(3)) <= false;
        elsif not ram_empty(seed_merge(ikfchannel)(1)) then
          dout(ikfchannel)                       <= ram_out(seed_merge(ikfchannel)(1));
          read_enable(seed_merge(ikfchannel)(0)) <= false;
          read_enable(seed_merge(ikfchannel)(1)) <= true;
          read_enable(seed_merge(ikfchannel)(2)) <= false;
          read_enable(seed_merge(ikfchannel)(3)) <= false;
        elsif not ram_empty(seed_merge(ikfchannel)(2)) then
          dout(ikfchannel)                       <= ram_out(seed_merge(ikfchannel)(2));
          read_enable(seed_merge(ikfchannel)(0)) <= false;
          read_enable(seed_merge(ikfchannel)(1)) <= false;
          read_enable(seed_merge(ikfchannel)(2)) <= true;
          read_enable(seed_merge(ikfchannel)(3)) <= false;
        elsif not ram_empty(seed_merge(ikfchannel)(3)) then
          dout(ikfchannel)                       <= ram_out(seed_merge(ikfchannel)(3));
          read_enable(seed_merge(ikfchannel)(0)) <= false;
          read_enable(seed_merge(ikfchannel)(1)) <= false;
          read_enable(seed_merge(ikfchannel)(2)) <= false;
          read_enable(seed_merge(ikfchannel)(3)) <= true;
        else
          dout(ikfchannel)                       <= nulll;
          read_enable(seed_merge(ikfchannel)(0)) <= false;
          read_enable(seed_merge(ikfchannel)(1)) <= false;
          read_enable(seed_merge(ikfchannel)(2)) <= false;
          read_enable(seed_merge(ikfchannel)(3)) <= false;
        end if;
      end loop;
    end if;
  end process;

end architecture rtl;

--END WRAPPER

