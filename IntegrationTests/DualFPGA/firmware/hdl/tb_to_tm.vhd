--=============================================================================
-- @file tb_to_tm.vhd
-- @brief Module to convert between TB output format and TM input format
-- @author Michael Oshiro <mco62@cornell.edu> based on work by Filippo Marini <filippo.marini@cern.ch>
-- @date 2025-11-17
-- @version v.1.0
--=============================================================================

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.emp_data_types.all;

use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;

use work.tf_data_types.all;
use work.tf_data_formats.all;
use work.tf_tools.all;
use work.tf_config.all;

entity tb_to_tm is
  port (
    clk240         : in  std_logic;
    clk360         : in  std_logic;
    rst            : in  std_logic;
    TW_113_data    : in  t_arr_TW_113_data;
    TW_113_valid   : in  t_arr_TW_113_1b;
    DW_49_data     : in  t_arr_DW_49_DATA;
    DW_49_valid    : in  t_arr_DW_49_1b;
    BW_46_data     : in  t_arr_BW_46_DATA;
    BW_46_valid    : in  t_arr_BW_46_1b;
    start_of_orbit : in  std_logic;
    start          : in  std_logic;
    valid          : in  std_logic;
    dout           : out ldata(0 to tbNumLinks - 1);
    orbit360       : out std_logic_vector( 0 to tbNumSeedTypes - 1 )
    );
end entity tb_to_tm;

architecture rtl of tb_to_tm is

  --TODO move to tf_config.vhd
  constant widthTrackletLmap : natural := 33;
  constant widthTBStubPhiRegion : natural := 3;
  constant widthTBStubIndex : natural := 7;

  constant TW_valid_pos : natural := widthTBseedType + widthTBStubPhiRegion
                                     + widthTBStubPhiRegion + widthTBStubIndex 
                                     + widthTBStubIndex + widthTBinv2R 
                                     + widthTBphi0 + widthTBz0 + widthTBcot 
                                     + widthTrackletLmap;
  constant TW_seedtype_pos : natural := widthTBStubPhiRegion
                                     + widthTBStubPhiRegion + widthTBStubIndex 
                                     + widthTBStubIndex + widthTBinv2R 
                                     + widthTBphi0 + widthTBz0 + widthTBcot 
                                     + widthTrackletLmap;
  constant TW_inPhiRegion_pos : natural := widthTBStubPhiRegion + widthTBStubIndex 
                                        + widthTBStubIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_outPhiRegion_pos : natural := widthTBStubIndex 
                                        + widthTBStubIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_inIndex_pos : natural := widthTBStubIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_outIndex_pos : natural := widthTBinv2R + widthTBphi0 
                                        + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_inv2r_pos    : natural := widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_phi0_pos     : natural := widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_z0_pos       : natural := widthTBcot + widthTrackletLmap;
  constant TW_cot_pos      : natural := widthTrackletLmap;

  constant BW_valid_pos   : natural := widthTBtrackId + widthTBstubId 
                                       + widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_trackid_pos : natural := widthTBstubId 
                                       + widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_stubid_pos  : natural := widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_r_pos       : natural := widthsTBphi(0) + widthsTBz(0);
  constant BW_phi_pos     : natural := widthsTBz(0);
  constant BW_z_pos       : natural := 0;

  constant DW_valid_pos   : natural := widthTBtrackId + widthTBstubId 
                                       + widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_trackid_pos : natural := widthTBstubId 
                                       + widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_stubid_pos  : natural := widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_r_pos       : natural := widthsTBphi(2) + widthsTBz(2);
  constant DW_phi_pos     : natural := widthsTBz(2);
  constant DW_z_pos       : natural := 0;
  constant TB_LATENCY360  : natural := 571;
  constant TB_LATENCY240  : natural := 378;

  constant widthTW_TM     : natural := 1 + widthTBseedType + widthTBinv2R 
                                       + widthTBphi0 + widthTBz0 
                                       + widthTBcot; --60
  constant widthBW_TM     : natural := 1 + widthTBstubId + widthsTBr(0)
                                       + widthsTBphi(0) + widthsTBz(0); --39
  constant widthDW_TM     : natural := 1 + widthTBstubId + widthsTBr(2) 
                                       + widthsTBphi(2) + widthsTBz(2); --42
  constant widthSeed_TM   : natural := 1 + widthTBStubPhiRegion 
                                       + widthTBStubIndex; --11

  constant PIPELINE_STAGES : natural := 2;
  type t_arr_t_arr_TW_113_data is array(PIPELINE_STAGES-1 downto 0) of t_arr_TW_113_data;
  type t_arr_t_arr_BW_46_data is array(PIPELINE_STAGES-1 downto 0) of t_arr_BW_46_data;
  type t_arr_t_arr_DW_49_data is array(PIPELINE_STAGES-1 downto 0) of t_arr_DW_49_data;

  signal TW_113_data_pipeline : t_arr_t_arr_TW_113_data := (others => (others => (others => '0')));
  signal DW_49_data_pipeline  : t_arr_t_arr_DW_49_data := (others => (others => (others => '0')));
  signal BW_46_data_pipeline  : t_arr_t_arr_BW_46_data := (others => (others => (others => '0')));

  signal sr_orbit : std_logic_vector(0 to TB_LATENCY360-1) := (others => '0');
  signal sr_start : std_logic_vector(0 to TB_LATENCY240-1) := (others => '0');
  signal sr_valid : std_logic_vector(0 to TB_LATENCY240-1) := (others => '0');
  signal start_of_orbit_latch      : std_logic := '0';
  signal start_of_orbit_latch_prev : std_logic := '0';

  type t_arr_stub_DW is array(0 to tbMaxNumProjectionLayers - 1) of enum_DW_49;
  type t_arr_stub_BW is array(0 to tbMaxNumProjectionLayers - 1) of enum_BW_46;
  type t_arr_seed_arr_stub_DW is array(integer range 0 to tbNumSeedTypes-1) of t_arr_stub_DW;
  type t_arr_seed_arr_stub_BW is array(integer range 0 to tbNumSeedTypes-1) of t_arr_stub_BW;

  --constants used to look up which barrel/disk stubs should be assigned to which seed type
  constant disk_stub_lut : t_arr_seed_arr_stub_DW := (
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4), --L1L2
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4), --L2L3
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,BBBB_D1,BBBB_D2,AAAA_D1,AAAA_D1), --L3L4
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --L5L6
      (AAAA_D1,AAAA_D1,BBBB_D3,BBBB_D4,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1), --D1D2
      (AAAA_D1,BBBB_D1,BBBB_D2,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --D3D4
      (BBBB_D2,BBBB_D3,BBBB_D4,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --L1D1
      (AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1)  --L2D1
      );

  constant barrel_stub_lut : t_arr_seed_arr_stub_BW := (
      (AAAA_L3,AAAA_L4,AAAA_L5,AAAA_L6,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L1L2
      (AAAA_L1,AAAA_L4,AAAA_L5,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L2L3
      (BBBB_L1,BBBB_L2,BBBB_L5,BBBB_L6,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L3L4
      (AAAA_L1,AAAA_L2,AAAA_L3,AAAA_L4,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L5L6
      (BBBB_L1,BBBB_L2,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --D1D2
      (BBBB_L1,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --D3D4
      (AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L1D1
      (AAAA_L1,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3)  --L2D1
      );

begin  -- architecture rtl

  --propagate start_of_orbit signal
  --eventually, this should just be something like a long shift register
  --currently, it is also a 240 MHz to 360 MHz CDC

  --using frame 6 convention (first 6 frames empty in simulation) the following
  --signal should only change on common 240/360 clock edges, making it safe to
  --sample in either domain
  --WARNING THIS MAY NOT WORK IN HARDWARE (depends on alignment of input)
  start_of_orbit_latch <= '1' when start_of_orbit='1' else
                          '0' when valid='0' else
                          start_of_orbit_latch;

  p_orbit : process (clk360) is
  begin
    if rising_edge(clk360) then

      start_of_orbit_latch_prev <= start_of_orbit_latch; 

      sr_orbit <= (start_of_orbit_latch and (not start_of_orbit_latch_prev)) 
                  & sr_orbit(sr_orbit'low to sr_orbit'high - 1);

      for iseedtype in 0 to (tbNumSeedTypes-1) loop
        orbit360(iseedtype) <= sr_orbit(sr_orbit'high-1);
      end loop; 

    end if; --rising 360 edge
  end process p_orbit;

  --main 240 MHz logic
  p_demultiplex : process (clk240) is

    variable seed_type : natural range 0 to 7;
    variable proj_idx : natural range 0 to 15;
    variable base_channel : natural range 0 to tbNumLinks-1;
    variable iBW_enum : enum_BW_46;
    variable iDW_enum : enum_DW_49;

  begin -- process p_tf_to_kf
    if rising_edge(clk240) then -- rising clock edge

      --propagate pipelining
     
      for itw in TW_113_data'range loop
        TW_113_data_pipeline(0)(itw) <= 
            (TW_113_valid(itw) and TW_113_data(itw)(TW_113_data(itw)'high)) 
            & TW_113_data(itw)(TW_113_data(itw)'high - 1 downto 0);
      end loop;

      for ibw in BW_46_data'range loop
        BW_46_data_pipeline(0)(ibw) <= 
            (BW_46_valid(ibw) and BW_46_data(ibw)(BW_46_data(ibw)'high)) 
            & BW_46_data(ibw)(BW_46_data(ibw)'high - 1 downto 0);
      end loop;

      for idw in DW_49_data'range loop
        DW_49_data_pipeline(0)(idw) <= 
            (DW_49_valid(idw) and DW_49_data(idw)(DW_49_data(idw)'high)) 
            & DW_49_data(idw)(DW_49_data(idw)'high - 1 downto 0);
      end loop; 

      for ipipe in 1 to PIPELINE_STAGES-1 loop
        for itw in TW_113_data'range loop
          TW_113_data_pipeline(ipipe)(itw) <= TW_113_data_pipeline(ipipe-1)(itw);
        end loop;

        for ibw in BW_46_data'range loop
          BW_46_data_pipeline(ipipe)(ibw) <= BW_46_data_pipeline(ipipe-1)(ibw);
        end loop;

        for idw in DW_49_data'range loop
          DW_49_data_pipeline(ipipe)(idw) <= DW_49_data_pipeline(ipipe-1)(idw);
        end loop;
      end loop; --loop over pipeline stages

      -- propagate start and valid from input using pattern recognition latency
      -- and default all channels to null
      sr_start <= start_of_orbit & sr_start(sr_start'low to sr_start'high - 1);
      sr_valid <= valid & sr_valid(sr_valid'low to sr_valid'high - 1);
      for ichannel in 0 to tbNumLinks-1 loop
        dout(ichannel) <= nulll;
        dout(ichannel).start_of_orbit <= sr_start(sr_start'high-1);
        dout(ichannel).valid <= sr_valid(sr_valid'high-1);
      end loop;

      --demultiplex track builder output into track processor channels
      --NB this style of loop not recommended for synthesis, but used elsewhere
      for itw in TW_113_data'range loop 
        seed_type := to_integer(unsigned(TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos)));
        base_channel := tbLimitsChannel(seed_type);
        if (TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(TW_valid_pos)='1') then

          --TM expects track, stubs, seeds, track, stubs, seeds, ...
          --assign track
          dout(base_channel).data(widthTW_TM - 1 downto 0) <= 
              TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(TW_valid_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBinv2R - 1 + TW_inv2r_pos downto TW_inv2r_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBphi0 - 1 + TW_phi0_pos downto TW_phi0_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBz0 - 1 + TW_z0_pos downto TW_z0_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBcot - 1 + TW_cot_pos downto TW_cot_pos);

          --assign stubs
          --We want Vivado to unroll these loops over seed types and projection
          --layers, but it is unclear if it will do so correctly. May need
          --optimization for implementation
          for iprojection in 0 to tbNumsProjectionLayers(seed_type)-1 loop
          --for iprojection in 0 to tbMaxNumProjectionLayers-1 loop
            proj_idx := seedTypesProjectionLayers(seed_type)(iprojection);

            --L2L3_L6 projection doesn't exist
            --hacky fix for now, eventually modify either KF or tracklet
            if seed_type = 1 and proj_idx = 6 then
              dout(base_channel+1+iprojection).data(widthBW_TM - 1 downto 0) <= (others => '0');

            --barrel
            elsif proj_idx >= 1 and proj_idx <= 6 then
              iBW_enum := barrel_stub_lut(seed_type)(iprojection);

              dout(base_channel+1+iprojection).data(widthBW_TM - 1 downto 0) <= 
                  BW_46_data_pipeline(PIPELINE_STAGES-1)(iBW_enum)(BW_valid_pos)
                  & BW_46_data_pipeline(PIPELINE_STAGES-1)(iBW_enum)(widthTBstubId + BW_stubid_pos - 1 downto BW_stubid_pos)
                  & BW_46_data_pipeline(PIPELINE_STAGES-1)(iBW_enum)(widthsTBr(0) + BW_r_pos - 1 downto BW_r_pos)
                  & BW_46_data_pipeline(PIPELINE_STAGES-1)(iBW_enum)(widthsTBphi(0) + BW_phi_pos - 1 downto BW_phi_pos)
                  & BW_46_data_pipeline(PIPELINE_STAGES-1)(iBW_enum)(widthsTBz(0) - 1 + BW_z_pos downto BW_z_pos);

            --disk
            elsif proj_idx >= 11 then
              iDW_enum := disk_stub_lut(seed_type)(iprojection);

              dout(base_channel+1+iprojection).data(widthDW_TM - 1 downto 0) <= 
                  DW_49_data_pipeline(PIPELINE_STAGES-1)(iDW_enum)(DW_valid_pos)
                  & DW_49_data_pipeline(PIPELINE_STAGES-1)(iDW_enum)(widthTBstubId + DW_stubid_pos - 1 downto DW_stubid_pos)
                  & DW_49_data_pipeline(PIPELINE_STAGES-1)(iDW_enum)(widthsTBr(2) + DW_r_pos - 1 downto DW_r_pos)
                  & DW_49_data_pipeline(PIPELINE_STAGES-1)(iDW_enum)(widthsTBphi(2) + DW_phi_pos - 1 downto DW_phi_pos)
                  & DW_49_data_pipeline(PIPELINE_STAGES-1)(iDW_enum)(widthsTBz(2) - 1 + DW_z_pos downto DW_z_pos);
            
            end if;
          end loop; -- loop over projections

          --assign seeds
          dout(base_channel+tbNumsProjectionLayers(seed_type)+1).data(widthSeed_TM - 1 downto 0) <= 
              TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(TW_valid_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBStubPhiRegion - 1 + TW_inPhiRegion_pos downto TW_inPhiRegion_pos) 
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBStubIndex - 1 + TW_inIndex_pos downto TW_inIndex_pos);

          dout(base_channel+tbNumsProjectionLayers(seed_type)+2).data(widthSeed_TM - 1 downto 0) <= 
              TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(TW_valid_pos)
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBStubPhiRegion - 1 + TW_outPhiRegion_pos downto TW_outPhiRegion_pos) 
              & TW_113_data_pipeline(PIPELINE_STAGES-1)(itw)(widthTBStubIndex - 1 + TW_outIndex_pos downto TW_outIndex_pos);

        end if; --valid track
      end loop; --loop over track builders
    end if; --rising clock edge
  end process p_demultiplex;

end architecture rtl;
