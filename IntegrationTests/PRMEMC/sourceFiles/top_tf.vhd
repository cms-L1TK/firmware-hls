--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;
--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.mytypes_pkg.all;


entity top_tf is
  port(
    clk       : in std_logic;
    reset     : in std_logic;
    PR_start  : in std_logic;
    PR_idle   : out std_logic;
    PR_ready  : out std_logic;
    PR_bx_in  : in std_logic_vector(2 downto 0);
    -- TrackletProjections input
    TPROJ_L3PHIC_dataarray_data_V_wea       : in t_myarray8_1b;
    TPROJ_L3PHIC_dataarray_data_V_writeaddr : in t_myarray8_8b;
    TPROJ_L3PHIC_dataarray_data_V_din       : in t_myarray8_60b;
    TPROJ_L3PHIC_nentries_V_we  : in t_myarray2_8_1b;
    TPROJ_L3PHIC_nentries_V_din : in t_myarray2_8_8b;
    -- VMStubsME input
    VMSME_L3PHIC17to24n1_dataarray_data_V_wea       : in t_myarray8_1b;
    VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr : in t_myarray8_10b;
    VMSME_L3PHIC17to24n1_dataarray_data_V_din       : in t_myarray8_14b;
    VMSME_L3PHIC17to24n1_nentries_V_we  : in t_myarray8_8_8_1b;
    VMSME_L3PHIC17to24n1_nentries_V_din : in t_myarray8_8_8_4b;
    -- AllStubs input
    AS_L3PHICn4_dataarray_data_V_wea       : in std_logic;
    AS_L3PHICn4_dataarray_data_V_writeaddr : in std_logic_vector(9 downto 0);
    AS_L3PHICn4_dataarray_data_V_din       : in std_logic_vector(35 downto 0);
    AS_L3PHICn4_nentries_V_we  : in t_myarray8_1b;
    AS_L3PHICn4_nentries_V_din : in t_myarray8_8b;
    -- FullMatches output
    FM_L1L2XX_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L1L2XX_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L1L2XX_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L1L2XX_L3PHIC_nentries_V_dout : out t_myarray2_8b;
    FM_L5L6XX_L3PHIC_dataarray_data_V_enb      : in std_logic;
    FM_L5L6XX_L3PHIC_dataarray_data_V_readaddr : in std_logic_vector(7 downto 0);
    FM_L5L6XX_L3PHIC_dataarray_data_V_dout     : out std_logic_vector(44 downto 0);
    FM_L5L6XX_L3PHIC_nentries_V_dout : out t_myarray2_8b;
    -- MatchCalculator output
    MC_bx_out     : out std_logic_vector(2 downto 0);
    MC_bx_out_vld : out std_logic;
    MC_done       : out std_logic
    );

end top_tf;

architecture rtl of top_tf is

-- KH implmenting clogb2 for addressing
function clogb2 (bit_depth : integer) return integer is
  variable depth : integer := bit_depth;
  variable count : integer := 1;
begin
  for clogb2 in 1 to bit_depth loop     -- Works for up to 32 bit integers
    if (bit_depth <= 2) then
      count := 1;
    else
      if(depth <= 1) then
        count := count;
      else
        depth := depth / 2;
        count := count + 1;
      end if;
    end if;
  end loop;
  return(count-1);
end;

COMPONENT myMemory
GENERIC (
  RAM_WIDTH       : integer := 18;                  -- Specify RAM data width
  RAM_DEPTH       : integer := 1024;                -- Specify RAM depth (number of entries)
  INIT_FILE       : string  := "";                  -- Specify name/location of RAM initialization file if using one (leave blank if not)
  RAM_PERFORMANCE : string  := "HIGH_PERFORMANCE";  -- Select "HIGH_PERFORMANCE" or "LOW_LATENCY"
  HEX             : integer := 1
  );
PORT (
  addra    : in std_logic_vector(clogb2(RAM_DEPTH) - 1 downto 0);  -- Write address bus, width determined from RAM_DEPTH
  addrb    : in std_logic_vector(clogb2(RAM_DEPTH) - 1 downto 0);  -- Read address bus, width determined from RAM_DEPTH
  dina     : in std_logic_vector(RAM_WIDTH - 1 downto 0);          -- RAM input data
  clka     : in std_logic;                                         -- Write clock
  clkb     : in std_logic;                                         -- Read clock
  wea      : in std_logic;                                         -- Write enable
  enb      : in std_logic;                                         -- Read Enable, for additional power savings, disable when not in use
  rstb     : in std_logic;                                         -- Output reset (does not affect memory contents)
  regceb   : in std_logic;                                         -- Output register enable
  nent_i0  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we0 : in std_logic;                                         -- Write enable
  nent_o0  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i1  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we1 : in std_logic;                                         -- Write enable
  nent_o1  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i2  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we2 : in std_logic;                                         -- Write enable
  nent_o2  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i3  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we3 : in std_logic;                                         -- Write enable
  nent_o3  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i4  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we4 : in std_logic;                                         -- Write enable
  nent_o4  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i5  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we5 : in std_logic;                                         -- Write enable
  nent_o5  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i6  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we6 : in std_logic;                                         -- Write enable
  nent_o6  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  nent_i7  : in std_logic_vector(7 downto 0);                      -- Num entries received
  nent_we7 : in std_logic;                                         -- Write enable
  nent_o7  : out std_logic_vector(7 downto 0);                     -- Num entries per page [4 bits each]
  doutb    : out std_logic_vector(RAM_WIDTH-1 downto 0)            -- RAM output data
  );
END COMPONENT;

COMPONENT myMemoryBinned
GENERIC (
  RAM_WIDTH       : integer := 14;                  -- Specify RAM data width, VM Stub: 14 for Barral LPS, 15 for Barral L2S/DISK
  RAM_DEPTH       : integer := 512;                 -- Specify RAM depth (number of entries) 512 is for 4 pages
  INIT_FILE       : string  := "";                  -- Specify name/location of RAM initialization file if using one (leave blank if not)
  RAM_PERFORMANCE : string  := "HIGH_PERFORMANCE";  -- Select "HIGH_PERFORMANCE" or "LOW_LATENCY"
  HEX             : integer := 1
  );
PORT (
  addra      : in std_logic_vector(clogb2(RAM_DEPTH) - 1 downto 0);  -- Write address bus, width determined from RAM_DEPTH
  addrb      : in std_logic_vector(clogb2(RAM_DEPTH) - 1 downto 0);  -- Read address bus, width determined from RAM_DEPTH
  dina       : in std_logic_vector(RAM_WIDTH - 1 downto 0);          -- RAM input data
  clka       : in std_logic;                                         -- Write clock
  clkb       : in std_logic;                                         -- Read clock
  wea        : in std_logic;                                         -- Write enable
  enb        : in std_logic;                                         -- Read Enable, for additional power savings, disable when not in use
  rstb       : in std_logic;                                         -- Output reset (does not affect memory contents)
  regceb     : in std_logic;                                         -- Output register enable
  nent_0_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we0 : in std_logic;                                         -- Write enable
  nent_0_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we1 : in std_logic;                                         -- Write enable
  nent_0_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we2 : in std_logic;                                         -- Write enable
  nent_0_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we3 : in std_logic;                                         -- Write enable
  nent_0_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we4 : in std_logic;                                         -- Write enable
  nent_0_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we5 : in std_logic;                                         -- Write enable
  nent_0_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we6 : in std_logic;                                         -- Write enable
  nent_0_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_0_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_0_we7 : in std_logic;                                         -- Write enable
  nent_0_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 0 [4 bits each]
  nent_1_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we0 : in std_logic;                                         -- Write enable
  nent_1_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we1 : in std_logic;                                         -- Write enable
  nent_1_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we2 : in std_logic;                                         -- Write enable
  nent_1_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we3 : in std_logic;                                         -- Write enable
  nent_1_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we4 : in std_logic;                                         -- Write enable
  nent_1_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we5 : in std_logic;                                         -- Write enable
  nent_1_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we6 : in std_logic;                                         -- Write enable
  nent_1_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_1_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_1_we7 : in std_logic;                                         -- Write enable
  nent_1_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 1 [4 bits each]
  nent_2_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we0 : in std_logic;                                         -- Write enable
  nent_2_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we1 : in std_logic;                                         -- Write enable
  nent_2_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we2 : in std_logic;                                         -- Write enable
  nent_2_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we3 : in std_logic;                                         -- Write enable
  nent_2_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we4 : in std_logic;                                         -- Write enable
  nent_2_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we5 : in std_logic;                                         -- Write enable
  nent_2_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we6 : in std_logic;                                         -- Write enable
  nent_2_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_2_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_2_we7 : in std_logic;                                         -- Write enable
  nent_2_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 2 [4 bits each]
  nent_3_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we0 : in std_logic;                                         -- Write enable
  nent_3_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we1 : in std_logic;                                         -- Write enable
  nent_3_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we2 : in std_logic;                                         -- Write enable
  nent_3_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we3 : in std_logic;                                         -- Write enable
  nent_3_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we4 : in std_logic;                                         -- Write enable
  nent_3_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we5 : in std_logic;                                         -- Write enable
  nent_3_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we6 : in std_logic;                                         -- Write enable
  nent_3_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_3_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_3_we7 : in std_logic;                                         -- Write enable
  nent_3_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 3 [4 bits each]
  nent_4_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we0 : in std_logic;                                         -- Write enable
  nent_4_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we1 : in std_logic;                                         -- Write enable
  nent_4_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we2 : in std_logic;                                         -- Write enable
  nent_4_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we3 : in std_logic;                                         -- Write enable
  nent_4_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we4 : in std_logic;                                         -- Write enable
  nent_4_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we5 : in std_logic;                                         -- Write enable
  nent_4_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we6 : in std_logic;                                         -- Write enable
  nent_4_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_4_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_4_we7 : in std_logic;                                         -- Write enable
  nent_4_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 4 [4 bits each]
  nent_5_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we0 : in std_logic;                                         -- Write enable
  nent_5_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we1 : in std_logic;                                         -- Write enable
  nent_5_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we2 : in std_logic;                                         -- Write enable
  nent_5_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we3 : in std_logic;                                         -- Write enable
  nent_5_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we4 : in std_logic;                                         -- Write enable
  nent_5_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we5 : in std_logic;                                         -- Write enable
  nent_5_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we6 : in std_logic;                                         -- Write enable
  nent_5_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_5_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_5_we7 : in std_logic;                                         -- Write enable
  nent_5_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 5 [4 bits each]
  nent_6_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we0 : in std_logic;                                         -- Write enable
  nent_6_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we1 : in std_logic;                                         -- Write enable
  nent_6_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we2 : in std_logic;                                         -- Write enable
  nent_6_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we3 : in std_logic;                                         -- Write enable
  nent_6_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we4 : in std_logic;                                         -- Write enable
  nent_6_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we5 : in std_logic;                                         -- Write enable
  nent_6_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we6 : in std_logic;                                         -- Write enable
  nent_6_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_6_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_6_we7 : in std_logic;                                         -- Write enable
  nent_6_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 6 [4 bits each]
  nent_7_i0  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we0 : in std_logic;                                         -- Write enable
  nent_7_o0  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i1  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we1 : in std_logic;                                         -- Write enable
  nent_7_o1  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i2  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we2 : in std_logic;                                         -- Write enable
  nent_7_o2  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i3  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we3 : in std_logic;                                         -- Write enable
  nent_7_o3  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i4  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we4 : in std_logic;                                         -- Write enable
  nent_7_o4  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i5  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we5 : in std_logic;                                         -- Write enable
  nent_7_o5  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i6  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we6 : in std_logic;                                         -- Write enable
  nent_7_o6  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  nent_7_i7  : in std_logic_vector(3 downto 0);                      -- Num entries received
  nent_7_we7 : in std_logic;                                         -- Write enable
  nent_7_o7  : out std_logic_vector(3 downto 0);                     -- Num entries for page 7 [4 bits each]
  doutb      : out std_logic_vector(RAM_WIDTH-1 downto 0)            -- RAM output data
  );
END COMPONENT;

  -- connecting TrackletProjections memories to ProjectionRouter input
  -- (0-7) -> (L1L2F-L1L2J, L5L6B-L5L6D)
  signal TPROJ_L3PHIC_dataarray_data_V_enb      : t_myarray8_1b;
  signal TPROJ_L3PHIC_dataarray_data_V_readaddr : t_myarray8_8b;
  signal TPROJ_L3PHIC_dataarray_data_V_dout     : t_myarray8_60b;
  signal TPROJ_L3PHIC_nentries_V_dout : t_myarray2_8_8b;

  -- ProjectionRouter signals
  signal PR_done       : std_logic := '0';
  signal PR_bx_out     : std_logic_vector(2 downto 0);
  signal PR_bx_out_vld : std_logic;

  -- connecting ProjectionRouter output to AllProjection memories
  signal AP_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal AP_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_din       : std_logic_vector(59 downto 0);
  signal AP_L3PHIC_nentries_V_we  : t_myarray8_1b;
  signal AP_L3PHIC_nentries_V_din : t_myarray8_8b;

  -- connecting ProjectionRouter output to VMProjection memories
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_wea       : t_myarray8_1b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr : t_myarray8_8b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_din       : t_myarray8_21b;
  signal VMPROJ_L3PHIC17to24_nentries_V_we  : t_myarray2_8_1b;
  signal VMPROJ_L3PHIC17to24_nentries_V_din : t_myarray2_8_8b;

  -- connecting VMProjections memories to MatchEngine input
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_enb      : t_myarray8_1b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr : t_myarray8_8b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_dout     : t_myarray8_21b;
  signal VMPROJ_L3PHIC17to24_nentries_V_dout : t_myarray2_8_8b;

  -- connecting VMStubME memories to MatchEngine input
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_enb      : t_myarray8_1b;
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr : t_myarray8_10b;
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_dout     : t_myarray8_14b;
  signal VMSME_L3PHIC17to24n1_nentries_V_dout           : t_myarray8_8_8_5b := (others => (others => (others => (others => '0')))); -- (#page, #bin, #mem); set MSbit to zero

  -- Note: myMemoryBinned class allocates 4-bits for nentries in each bin, while
  -- MatchEngine ports are expecting 5-bits. Leaving the 5th bit unconnected seems
  -- to cause Vivado to trim away logic and messes up some LUT logic in the ME
  -- module. Assign 'dont_touch' attribute to the nentries signal to prevent this.
  attribute dont_touch : string;
  attribute dont_touch of VMSME_L3PHIC17to24n1_nentries_V_dout : signal is "true";

  -- MatchEngine signals
  signal ME_start : std_logic := '0';
  signal ME_done  : t_myarray8_1b := (others => '0');
  signal ME_idle  : std_logic := '0';
  signal ME_ready : std_logic := '0';
  signal ME_bx_out     : t_myarray8_3b;
  signal ME_bx_out_vld : t_myarray8_1b;
  signal ME_all_done   : std_logic := '0';

  -- connecting MatchEngine output to CandidateMatches memories 
  signal CM_L3PHIC17to24_dataarray_data_V_wea       : t_myarray8_1b;
  signal CM_L3PHIC17to24_dataarray_data_V_writeaddr : t_myarray8_8b;
  signal CM_L3PHIC17to24_dataarray_data_V_din       : t_myarray8_14b;
  signal CM_L3PHIC17to24_nentries_V_we  : t_myarray2_8_1b;
  signal CM_L3PHIC17to24_nentries_V_din : t_myarray2_8_8b;

  -- connecting AllStubs memory to MatchCalculator input
  signal AS_L3PHICn4_dataarray_data_V_enb      : std_logic;
  signal AS_L3PHICn4_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AS_L3PHICn4_dataarray_data_V_dout     : std_logic_vector(35 downto 0);
  signal AS_L3PHICn4_nentries_V_dout : t_myarray8_8b;

  -- connecting AllProjections memory to MatchCalculator input
  signal AP_L3PHIC_dataarray_data_V_enb      : std_logic;
  signal AP_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_dout     : std_logic_vector(59 downto 0);
  signal AP_L3PHIC_nentries_V_dout : t_myarray8_8b;

  -- connecting CandidateMatches memories to MatchCalculator input
  signal CM_L3PHIC17to24_dataarray_data_V_enb      : t_myarray8_1b;
  signal CM_L3PHIC17to24_dataarray_data_V_readaddr : t_myarray8_8b;
  signal CM_L3PHIC17to24_dataarray_data_V_dout     : t_myarray8_14b;
  signal CM_L3PHIC17to24_nentries_V_dout : t_myarray2_8_8b;

  -- MatchCalculator signals
  signal MC_start : std_logic := '0';
  signal MC_idle  : std_logic := '0';
  signal MC_ready : std_logic := '0';

  -- connecting MatchCalculator output to FullMatches memories
  signal FM_L1L2XX_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L1L2XX_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);
  signal FM_L1L2XX_L3PHIC_nentries_V_we  : t_myarray2_1b;
  signal FM_L1L2XX_L3PHIC_nentries_V_din : t_myarray2_8b;
  signal FM_L5L6XX_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(7 downto 0);
  signal FM_L5L6XX_L3PHIC_dataarray_data_V_din       : std_logic_vector(44 downto 0);
  signal FM_L5L6XX_L3PHIC_nentries_V_we  : t_myarray2_1b;
  signal FM_L5L6XX_L3PHIC_nentries_V_din : t_myarray2_8b;

begin

  --------------------------------------------------------------
  -- Signaling section
  --------------------------------------------------------------
  p_ME_start : process(clk)
  begin
    if rising_edge(clk) then
      if PR_done = '1' then
        if (ME_ready='1' or ME_idle='1') then
          ME_start <= '1';
        else
          ME_start <= '0';
        end if;
      else
        ME_start <= '0';
      end if;
    end if;
  end process;

  ME_all_done <= ME_done(0) and ME_done(1) and ME_done(2) and ME_done(3) and ME_done(4) and ME_done(5) and ME_done(6) and ME_done(7);

  p_MC_start : process(clk)
  begin
    if rising_edge(clk) then
      if ME_all_done = '1' then
        if (MC_ready='1' or MC_idle='1') then
          MC_start <= '1';
        else
          MC_start <= '0';
        end if;
      else
        MC_start <= '0';
      end if;
    end if;
  end process;

  --------------------------------------------------------------
  -- TrackletProjection memories
  --------------------------------------------------------------
  gen_TPROJ_L3PHIC : for tpidx in 7 downto 0 generate
  begin
    TPROJ_L3PHIC : myMemory
      generic map (
        RAM_WIDTH       => 60,
        RAM_DEPTH       => 256,
        INIT_FILE       => "",
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        HEX             => 1
        )
      port map (
        clka     => clk,
        wea      => TPROJ_L3PHIC_dataarray_data_V_wea(tpidx),
        addra    => TPROJ_L3PHIC_dataarray_data_V_writeaddr(tpidx),
        dina     => TPROJ_L3PHIC_dataarray_data_V_din(tpidx),
        nent_we0 => TPROJ_L3PHIC_nentries_V_we(0)(tpidx),
        nent_i0  => TPROJ_L3PHIC_nentries_V_din(0)(tpidx),
        nent_we1 => TPROJ_L3PHIC_nentries_V_we(1)(tpidx),
        nent_i1  => TPROJ_L3PHIC_nentries_V_din(1)(tpidx),
        nent_we2 => '0',
        nent_i2  => (others=>'0'),
        nent_we3 => '0',
        nent_i3  => (others=>'0'),
        nent_we4 => '0',
        nent_i4  => (others=>'0'),
        nent_we5 => '0',
        nent_i5  => (others=>'0'),
        nent_we6 => '0',
        nent_i6  => (others=>'0'),
        nent_we7 => '0',
        nent_i7  => (others=>'0'),
        clkb     => clk,
        rstb     => '0',
        regceb   => '1',
        enb      => TPROJ_L3PHIC_dataarray_data_V_enb(tpidx),
        addrb    => TPROJ_L3PHIC_dataarray_data_V_readaddr(tpidx),
        doutb    => TPROJ_L3PHIC_dataarray_data_V_dout(tpidx),
        nent_o0  => TPROJ_L3PHIC_nentries_V_dout(0)(tpidx),
        nent_o1  => TPROJ_L3PHIC_nentries_V_dout(1)(tpidx),
        nent_o2  => open,
        nent_o3  => open,
        nent_o4  => open,
        nent_o5  => open,
        nent_o6  => open,
        nent_o7  => open
        );

  end generate gen_TPROJ_L3PHIC;


  --------------------------------------------------------------
  -- ProjectionRouter
  --------------------------------------------------------------
  PR_L3PHIC : entity work.PR_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => PR_start,
      ap_done  => PR_done,
      ap_idle  => PR_idle,
      ap_ready => PR_ready,
      bx_V     => PR_bx_in,
      projin_0_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(0),
      projin_0_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(0),
      projin_0_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(0),
      projin_0_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(0),
      projin_0_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(0),
      projin_1_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(1),
      projin_1_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(1),
      projin_1_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(1),
      projin_1_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(1),
      projin_1_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(1),
      projin_2_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(2),
      projin_2_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(2),
      projin_2_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(2),
      projin_2_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(2),
      projin_2_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(2),
      projin_3_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(3),
      projin_3_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(3),
      projin_3_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(3),
      projin_3_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(3),
      projin_3_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(3),
      projin_4_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(4),
      projin_4_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(4),
      projin_4_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(4),
      projin_4_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(4),
      projin_4_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(4),
      projin_5_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(5),
      projin_5_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(5),
      projin_5_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(5),
      projin_5_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(5),
      projin_5_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(5),
      projin_6_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(6),
      projin_6_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(6),
      projin_6_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(6),
      projin_6_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(6),
      projin_6_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(6),
      projin_7_dataarray_data_V_address0 => TPROJ_L3PHIC_dataarray_data_V_readaddr(7),
      projin_7_dataarray_data_V_ce0      => TPROJ_L3PHIC_dataarray_data_V_enb(7),
      projin_7_dataarray_data_V_q0       => TPROJ_L3PHIC_dataarray_data_V_dout(7),
      projin_7_nentries_0_V              => TPROJ_L3PHIC_nentries_V_dout(0)(7),
      projin_7_nentries_1_V              => TPROJ_L3PHIC_nentries_V_dout(1)(7),
      bx_o_V        => PR_bx_out,
      bx_o_V_ap_vld => PR_bx_out_vld,
      allprojout_dataarray_data_V_address0 => AP_L3PHIC_dataarray_data_V_writeaddr,
      allprojout_dataarray_data_V_ce0      => open,
      allprojout_dataarray_data_V_we0      => AP_L3PHIC_dataarray_data_V_wea,
      allprojout_dataarray_data_V_d0       => AP_L3PHIC_dataarray_data_V_din,
      allprojout_nentries_0_V        => AP_L3PHIC_nentries_V_din(0),
      allprojout_nentries_0_V_ap_vld =>  AP_L3PHIC_nentries_V_we(0),
      allprojout_nentries_1_V        => AP_L3PHIC_nentries_V_din(1),
      allprojout_nentries_1_V_ap_vld =>  AP_L3PHIC_nentries_V_we(1),
      allprojout_nentries_2_V        => AP_L3PHIC_nentries_V_din(2),
      allprojout_nentries_2_V_ap_vld =>  AP_L3PHIC_nentries_V_we(2),
      allprojout_nentries_3_V        => AP_L3PHIC_nentries_V_din(3),
      allprojout_nentries_3_V_ap_vld =>  AP_L3PHIC_nentries_V_we(3),
      allprojout_nentries_4_V        => AP_L3PHIC_nentries_V_din(4),
      allprojout_nentries_4_V_ap_vld =>  AP_L3PHIC_nentries_V_we(4),
      allprojout_nentries_5_V        => AP_L3PHIC_nentries_V_din(5),
      allprojout_nentries_5_V_ap_vld =>  AP_L3PHIC_nentries_V_we(5),
      allprojout_nentries_6_V        => AP_L3PHIC_nentries_V_din(6),
      allprojout_nentries_6_V_ap_vld =>  AP_L3PHIC_nentries_V_we(6),
      allprojout_nentries_7_V        => AP_L3PHIC_nentries_V_din(7),
      allprojout_nentries_7_V_ap_vld =>  AP_L3PHIC_nentries_V_we(7),
      vmprojout_0_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(0),
      vmprojout_0_dataarray_data_V_ce0      => open,
      vmprojout_0_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(0),
      vmprojout_0_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(0),
      vmprojout_0_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(0),
      vmprojout_0_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(0),
      vmprojout_0_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(0),
      vmprojout_0_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(0),
      vmprojout_1_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(1),
      vmprojout_1_dataarray_data_V_ce0      => open,
      vmprojout_1_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(1),
      vmprojout_1_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(1),
      vmprojout_1_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(1),
      vmprojout_1_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(1),
      vmprojout_1_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(1),
      vmprojout_1_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(1),
      vmprojout_2_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(2),
      vmprojout_2_dataarray_data_V_ce0      => open,
      vmprojout_2_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(2),
      vmprojout_2_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(2),
      vmprojout_2_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(2),
      vmprojout_2_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(2),
      vmprojout_2_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(2),
      vmprojout_2_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(2),
      vmprojout_3_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(3),
      vmprojout_3_dataarray_data_V_ce0      => open,
      vmprojout_3_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(3),
      vmprojout_3_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(3),
      vmprojout_3_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(3),
      vmprojout_3_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(3),
      vmprojout_3_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(3),
      vmprojout_3_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(3),
      vmprojout_4_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(4),
      vmprojout_4_dataarray_data_V_ce0      => open,
      vmprojout_4_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(4),
      vmprojout_4_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(4),
      vmprojout_4_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(4),
      vmprojout_4_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(4),
      vmprojout_4_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(4),
      vmprojout_4_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(4),
      vmprojout_5_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(5),
      vmprojout_5_dataarray_data_V_ce0      => open,
      vmprojout_5_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(5),
      vmprojout_5_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(5),
      vmprojout_5_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(5),
      vmprojout_5_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(5),
      vmprojout_5_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(5),
      vmprojout_5_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(5),
      vmprojout_6_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(6),
      vmprojout_6_dataarray_data_V_ce0      => open,
      vmprojout_6_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(6),
      vmprojout_6_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(6),
      vmprojout_6_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(6),
      vmprojout_6_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(6),
      vmprojout_6_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(6),
      vmprojout_6_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(6),
      vmprojout_7_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(7),
      vmprojout_7_dataarray_data_V_ce0      => open,
      vmprojout_7_dataarray_data_V_we0      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(7),
      vmprojout_7_dataarray_data_V_d0       => VMPROJ_L3PHIC17to24_dataarray_data_V_din(7),
      vmprojout_7_nentries_0_V              => VMPROJ_L3PHIC17to24_nentries_V_din(0)(7),
      vmprojout_7_nentries_0_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(7),
      vmprojout_7_nentries_1_V              => VMPROJ_L3PHIC17to24_nentries_V_din(1)(7),
      vmprojout_7_nentries_1_V_ap_vld       =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(7)
      );


  --------------------------------------------------------------
  -- AllProjection memory
  --------------------------------------------------------------
  AP_L3PHIC : myMemory
    generic map (
      RAM_WIDTH       => 60,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
      HEX             => 1
      )
    port map (
      clka     => clk,
      wea      => AP_L3PHIC_dataarray_data_V_wea,
      addra    => AP_L3PHIC_dataarray_data_V_writeaddr,
      dina     => AP_L3PHIC_dataarray_data_V_din,
      nent_we0 =>  AP_L3PHIC_nentries_V_we(0),
      nent_i0  => AP_L3PHIC_nentries_V_din(0),
      nent_we1 =>  AP_L3PHIC_nentries_V_we(1),
      nent_i1  => AP_L3PHIC_nentries_V_din(1),
      nent_we2 =>  AP_L3PHIC_nentries_V_we(2),
      nent_i2  => AP_L3PHIC_nentries_V_din(2),
      nent_we3 =>  AP_L3PHIC_nentries_V_we(3),
      nent_i3  => AP_L3PHIC_nentries_V_din(3),
      nent_we4 =>  AP_L3PHIC_nentries_V_we(4),
      nent_i4  => AP_L3PHIC_nentries_V_din(4),
      nent_we5 =>  AP_L3PHIC_nentries_V_we(5),
      nent_i5  => AP_L3PHIC_nentries_V_din(5),
      nent_we6 =>  AP_L3PHIC_nentries_V_we(6),
      nent_i6  => AP_L3PHIC_nentries_V_din(6),
      nent_we7 =>  AP_L3PHIC_nentries_V_we(7),
      nent_i7  => AP_L3PHIC_nentries_V_din(7),
      clkb     => clk,
      rstb     => '0',
      regceb   => '1',
      enb      => AP_L3PHIC_dataarray_data_V_enb,
      addrb    => AP_L3PHIC_dataarray_data_V_readaddr,
      doutb    => AP_L3PHIC_dataarray_data_V_dout,
      nent_o0  => AP_L3PHIC_nentries_V_dout(0),
      nent_o1  => AP_L3PHIC_nentries_V_dout(1),
      nent_o2  => AP_L3PHIC_nentries_V_dout(2),
      nent_o3  => AP_L3PHIC_nentries_V_dout(3),
      nent_o4  => AP_L3PHIC_nentries_V_dout(4),
      nent_o5  => AP_L3PHIC_nentries_V_dout(5),
      nent_o6  => AP_L3PHIC_nentries_V_dout(6),
      nent_o7  => AP_L3PHIC_nentries_V_dout(7)
      );


  --------------------------------------------------------------
  -- VMProjection memories
  --------------------------------------------------------------
  gen_VMPROJ_L3PHIC17to24 : for vmpidx in 7 downto 0 generate
  begin
    VMPROJ_L3PHIC17to24 : myMemory
      generic map (
        RAM_WIDTH       => 21,
        RAM_DEPTH       => 256,
        INIT_FILE       => "",
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        HEX             => 0
        )
      port map (
        clka     => clk,
        wea      => VMPROJ_L3PHIC17to24_dataarray_data_V_wea(vmpidx),
        addra    => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(vmpidx),
        dina     => VMPROJ_L3PHIC17to24_dataarray_data_V_din(vmpidx),
        nent_we0 =>  VMPROJ_L3PHIC17to24_nentries_V_we(0)(vmpidx),
        nent_i0  => VMPROJ_L3PHIC17to24_nentries_V_din(0)(vmpidx),
        nent_we1 =>  VMPROJ_L3PHIC17to24_nentries_V_we(1)(vmpidx),
        nent_i1  => VMPROJ_L3PHIC17to24_nentries_V_din(1)(vmpidx),
        nent_we2 => '0',
        nent_i2  => (others=>'0'),
        nent_we3 => '0',
        nent_i3  => (others=>'0'),
        nent_we4 => '0',
        nent_i4  => (others=>'0'),
        nent_we5 => '0',
        nent_i5  => (others=>'0'),
        nent_we6 => '0',
        nent_i6  => (others=>'0'),
        nent_we7 => '0',
        nent_i7  => (others=>'0'),
        clkb     => clk,
        rstb     => '0',
        regceb   => '1',
        enb      => VMPROJ_L3PHIC17to24_dataarray_data_V_enb(vmpidx),
        addrb    => VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr(vmpidx),
        doutb    => VMPROJ_L3PHIC17to24_dataarray_data_V_dout(vmpidx),
        nent_o0  => VMPROJ_L3PHIC17to24_nentries_V_dout(0)(vmpidx),
        nent_o1  => VMPROJ_L3PHIC17to24_nentries_V_dout(1)(vmpidx),
        nent_o2  => open,
        nent_o3  => open,
        nent_o4  => open,
        nent_o5  => open,
        nent_o6  => open,
        nent_o7  => open
        );
  
  end generate gen_VMPROJ_L3PHIC17to24;


  --------------------------------------------------------------
  -- VMStubME memories
  --------------------------------------------------------------
  gen_VMSME_L3PHIC17to24n1 : for vmsidx in 7 downto 0 generate
  begin
    VMSME_L3PHIC17to24n1 : myMemoryBinned
      generic map (
        RAM_WIDTH       => 14,
        RAM_DEPTH       => 1024,
        INIT_FILE       => "",
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        HEX             => 0
        )
      port map (
        clka       => clk,
        wea        => VMSME_L3PHIC17to24n1_dataarray_data_V_wea(vmsidx),
        addra      => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(vmsidx),
        dina       => VMSME_L3PHIC17to24n1_dataarray_data_V_din(vmsidx),
        nent_0_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(0)(vmsidx),
        nent_0_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(0)(vmsidx),
        nent_0_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(1)(vmsidx),
        nent_0_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(1)(vmsidx),
        nent_0_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(2)(vmsidx),
        nent_0_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(2)(vmsidx),
        nent_0_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(3)(vmsidx),
        nent_0_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(3)(vmsidx),
        nent_0_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(4)(vmsidx),
        nent_0_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(4)(vmsidx),
        nent_0_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(5)(vmsidx),
        nent_0_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(5)(vmsidx),
        nent_0_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(6)(vmsidx),
        nent_0_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(6)(vmsidx),
        nent_0_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(0)(7)(vmsidx),
        nent_0_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(0)(7)(vmsidx),
        nent_1_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(0)(vmsidx),
        nent_1_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(0)(vmsidx),
        nent_1_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(1)(vmsidx),
        nent_1_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(1)(vmsidx),
        nent_1_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(2)(vmsidx),
        nent_1_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(2)(vmsidx),
        nent_1_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(3)(vmsidx),
        nent_1_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(3)(vmsidx),
        nent_1_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(4)(vmsidx),
        nent_1_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(4)(vmsidx),
        nent_1_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(5)(vmsidx),
        nent_1_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(5)(vmsidx),
        nent_1_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(6)(vmsidx),
        nent_1_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(6)(vmsidx),
        nent_1_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(1)(7)(vmsidx),
        nent_1_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(1)(7)(vmsidx),
        nent_2_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(0)(vmsidx),
        nent_2_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(0)(vmsidx),
        nent_2_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(1)(vmsidx),
        nent_2_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(1)(vmsidx),
        nent_2_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(2)(vmsidx),
        nent_2_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(2)(vmsidx),
        nent_2_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(3)(vmsidx),
        nent_2_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(3)(vmsidx),
        nent_2_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(4)(vmsidx),
        nent_2_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(4)(vmsidx),
        nent_2_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(5)(vmsidx),
        nent_2_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(5)(vmsidx),
        nent_2_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(6)(vmsidx),
        nent_2_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(6)(vmsidx),
        nent_2_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(2)(7)(vmsidx),
        nent_2_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(2)(7)(vmsidx),
        nent_3_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(0)(vmsidx),
        nent_3_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(0)(vmsidx),
        nent_3_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(1)(vmsidx),
        nent_3_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(1)(vmsidx),
        nent_3_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(2)(vmsidx),
        nent_3_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(2)(vmsidx),
        nent_3_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(3)(vmsidx),
        nent_3_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(3)(vmsidx),
        nent_3_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(4)(vmsidx),
        nent_3_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(4)(vmsidx),
        nent_3_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(5)(vmsidx),
        nent_3_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(5)(vmsidx),
        nent_3_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(6)(vmsidx),
        nent_3_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(6)(vmsidx),
        nent_3_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(3)(7)(vmsidx),
        nent_3_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(3)(7)(vmsidx),
        nent_4_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(0)(vmsidx),
        nent_4_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(0)(vmsidx),
        nent_4_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(1)(vmsidx),
        nent_4_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(1)(vmsidx),
        nent_4_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(2)(vmsidx),
        nent_4_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(2)(vmsidx),
        nent_4_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(3)(vmsidx),
        nent_4_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(3)(vmsidx),
        nent_4_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(4)(vmsidx),
        nent_4_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(4)(vmsidx),
        nent_4_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(5)(vmsidx),
        nent_4_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(5)(vmsidx),
        nent_4_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(6)(vmsidx),
        nent_4_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(6)(vmsidx),
        nent_4_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(4)(7)(vmsidx),
        nent_4_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(4)(7)(vmsidx),
        nent_5_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(0)(vmsidx),
        nent_5_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(0)(vmsidx),
        nent_5_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(1)(vmsidx),
        nent_5_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(1)(vmsidx),
        nent_5_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(2)(vmsidx),
        nent_5_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(2)(vmsidx),
        nent_5_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(3)(vmsidx),
        nent_5_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(3)(vmsidx),
        nent_5_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(4)(vmsidx),
        nent_5_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(4)(vmsidx),
        nent_5_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(5)(vmsidx),
        nent_5_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(5)(vmsidx),
        nent_5_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(6)(vmsidx),
        nent_5_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(6)(vmsidx),
        nent_5_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(5)(7)(vmsidx),
        nent_5_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(5)(7)(vmsidx),
        nent_6_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(0)(vmsidx),
        nent_6_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(0)(vmsidx),
        nent_6_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(1)(vmsidx),
        nent_6_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(1)(vmsidx),
        nent_6_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(2)(vmsidx),
        nent_6_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(2)(vmsidx),
        nent_6_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(3)(vmsidx),
        nent_6_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(3)(vmsidx),
        nent_6_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(4)(vmsidx),
        nent_6_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(4)(vmsidx),
        nent_6_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(5)(vmsidx),
        nent_6_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(5)(vmsidx),
        nent_6_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(6)(vmsidx),
        nent_6_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(6)(vmsidx),
        nent_6_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(6)(7)(vmsidx),
        nent_6_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(6)(7)(vmsidx),
        nent_7_we0 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(0)(vmsidx),
        nent_7_i0  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(0)(vmsidx),
        nent_7_we1 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(1)(vmsidx),
        nent_7_i1  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(1)(vmsidx),
        nent_7_we2 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(2)(vmsidx),
        nent_7_i2  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(2)(vmsidx),
        nent_7_we3 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(3)(vmsidx),
        nent_7_i3  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(3)(vmsidx),
        nent_7_we4 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(4)(vmsidx),
        nent_7_i4  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(4)(vmsidx),
        nent_7_we5 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(5)(vmsidx),
        nent_7_i5  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(5)(vmsidx),
        nent_7_we6 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(6)(vmsidx),
        nent_7_i6  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(6)(vmsidx),
        nent_7_we7 =>  VMSME_L3PHIC17to24n1_nentries_V_we(7)(7)(vmsidx),
        nent_7_i7  => VMSME_L3PHIC17to24n1_nentries_V_din(7)(7)(vmsidx),
        clkb       => clk,
        rstb       => '0',
        regceb     => '1',
        enb        => VMSME_L3PHIC17to24n1_dataarray_data_V_enb(vmsidx),
        addrb      => VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr(vmsidx),
        doutb      => VMSME_L3PHIC17to24n1_dataarray_data_V_dout(vmsidx),
        nent_0_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(0)(vmsidx)(3 downto 0),
        nent_0_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(1)(vmsidx)(3 downto 0),
        nent_0_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(2)(vmsidx)(3 downto 0),
        nent_0_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(3)(vmsidx)(3 downto 0),
        nent_0_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(4)(vmsidx)(3 downto 0),
        nent_0_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(5)(vmsidx)(3 downto 0),
        nent_0_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(6)(vmsidx)(3 downto 0),
        nent_0_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(7)(vmsidx)(3 downto 0),
        nent_1_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(0)(vmsidx)(3 downto 0),
        nent_1_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(1)(vmsidx)(3 downto 0),
        nent_1_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(2)(vmsidx)(3 downto 0),
        nent_1_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(3)(vmsidx)(3 downto 0),
        nent_1_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(4)(vmsidx)(3 downto 0),
        nent_1_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(5)(vmsidx)(3 downto 0),
        nent_1_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(6)(vmsidx)(3 downto 0),
        nent_1_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(7)(vmsidx)(3 downto 0),
        nent_2_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(0)(vmsidx)(3 downto 0),
        nent_2_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(1)(vmsidx)(3 downto 0),
        nent_2_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(2)(vmsidx)(3 downto 0),
        nent_2_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(3)(vmsidx)(3 downto 0),
        nent_2_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(4)(vmsidx)(3 downto 0),
        nent_2_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(5)(vmsidx)(3 downto 0),
        nent_2_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(6)(vmsidx)(3 downto 0),
        nent_2_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(7)(vmsidx)(3 downto 0),
        nent_3_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(0)(vmsidx)(3 downto 0),
        nent_3_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(1)(vmsidx)(3 downto 0),
        nent_3_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(2)(vmsidx)(3 downto 0),
        nent_3_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(3)(vmsidx)(3 downto 0),
        nent_3_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(4)(vmsidx)(3 downto 0),
        nent_3_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(5)(vmsidx)(3 downto 0),
        nent_3_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(6)(vmsidx)(3 downto 0),
        nent_3_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(7)(vmsidx)(3 downto 0),
        nent_4_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(0)(vmsidx)(3 downto 0),
        nent_4_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(1)(vmsidx)(3 downto 0),
        nent_4_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(2)(vmsidx)(3 downto 0),
        nent_4_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(3)(vmsidx)(3 downto 0),
        nent_4_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(4)(vmsidx)(3 downto 0),
        nent_4_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(5)(vmsidx)(3 downto 0),
        nent_4_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(6)(vmsidx)(3 downto 0),
        nent_4_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(7)(vmsidx)(3 downto 0),
        nent_5_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(0)(vmsidx)(3 downto 0),
        nent_5_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(1)(vmsidx)(3 downto 0),
        nent_5_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(2)(vmsidx)(3 downto 0),
        nent_5_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(3)(vmsidx)(3 downto 0),
        nent_5_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(4)(vmsidx)(3 downto 0),
        nent_5_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(5)(vmsidx)(3 downto 0),
        nent_5_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(6)(vmsidx)(3 downto 0),
        nent_5_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(7)(vmsidx)(3 downto 0),
        nent_6_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(0)(vmsidx)(3 downto 0),
        nent_6_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(1)(vmsidx)(3 downto 0),
        nent_6_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(2)(vmsidx)(3 downto 0),
        nent_6_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(3)(vmsidx)(3 downto 0),
        nent_6_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(4)(vmsidx)(3 downto 0),
        nent_6_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(5)(vmsidx)(3 downto 0),
        nent_6_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(6)(vmsidx)(3 downto 0),
        nent_6_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(7)(vmsidx)(3 downto 0),
        nent_7_o0  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(0)(vmsidx)(3 downto 0),
        nent_7_o1  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(1)(vmsidx)(3 downto 0),
        nent_7_o2  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(2)(vmsidx)(3 downto 0),
        nent_7_o3  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(3)(vmsidx)(3 downto 0),
        nent_7_o4  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(4)(vmsidx)(3 downto 0),
        nent_7_o5  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(5)(vmsidx)(3 downto 0),
        nent_7_o6  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(6)(vmsidx)(3 downto 0),
        nent_7_o7  => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(7)(vmsidx)(3 downto 0)
        );

  end generate gen_VMSME_L3PHIC17to24n1;


  --------------------------------------------------------------
  -- MatchEngine
  --------------------------------------------------------------
  gen_ME : for meidx in 7 downto 0 generate
  begin
    i_ME : entity work.MatchEngineTopL3_0
      port map (
        ap_clk   => clk,
        ap_rst   => reset,
        ap_start => ME_start,
        ap_done  => ME_done(meidx),
        ap_idle  => ME_idle,
        ap_ready => ME_ready,
        bx_V          => PR_bx_out,
        bx_o_V        => ME_bx_out(meidx),
        bx_o_V_ap_vld => ME_bx_out_vld(meidx),
        inputStubData_dataarray_data_V_address0 => VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr(meidx),
        inputStubData_dataarray_data_V_ce0      => VMSME_L3PHIC17to24n1_dataarray_data_V_enb(meidx),
        inputStubData_dataarray_data_V_q0       => VMSME_L3PHIC17to24n1_dataarray_data_V_dout(meidx)(12 downto 0),
        inputStubData_nentries_0_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(0)(meidx),
        inputStubData_nentries_0_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(1)(meidx),
        inputStubData_nentries_0_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(2)(meidx),
        inputStubData_nentries_0_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(3)(meidx),
        inputStubData_nentries_0_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(4)(meidx),
        inputStubData_nentries_0_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(5)(meidx),
        inputStubData_nentries_0_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(6)(meidx),
        inputStubData_nentries_0_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(0)(7)(meidx),
        inputStubData_nentries_1_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(0)(meidx),
        inputStubData_nentries_1_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(1)(meidx),
        inputStubData_nentries_1_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(2)(meidx),
        inputStubData_nentries_1_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(3)(meidx),
        inputStubData_nentries_1_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(4)(meidx),
        inputStubData_nentries_1_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(5)(meidx),
        inputStubData_nentries_1_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(6)(meidx),
        inputStubData_nentries_1_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(1)(7)(meidx),
        inputStubData_nentries_2_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(0)(meidx),
        inputStubData_nentries_2_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(1)(meidx),
        inputStubData_nentries_2_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(2)(meidx),
        inputStubData_nentries_2_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(3)(meidx),
        inputStubData_nentries_2_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(4)(meidx),
        inputStubData_nentries_2_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(5)(meidx),
        inputStubData_nentries_2_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(6)(meidx),
        inputStubData_nentries_2_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(2)(7)(meidx),
        inputStubData_nentries_3_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(0)(meidx),
        inputStubData_nentries_3_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(1)(meidx),
        inputStubData_nentries_3_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(2)(meidx),
        inputStubData_nentries_3_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(3)(meidx),
        inputStubData_nentries_3_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(4)(meidx),
        inputStubData_nentries_3_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(5)(meidx),
        inputStubData_nentries_3_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(6)(meidx),
        inputStubData_nentries_3_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(3)(7)(meidx),
        inputStubData_nentries_4_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(0)(meidx),
        inputStubData_nentries_4_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(1)(meidx),
        inputStubData_nentries_4_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(2)(meidx),
        inputStubData_nentries_4_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(3)(meidx),
        inputStubData_nentries_4_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(4)(meidx),
        inputStubData_nentries_4_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(5)(meidx),
        inputStubData_nentries_4_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(6)(meidx),
        inputStubData_nentries_4_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(4)(7)(meidx),
        inputStubData_nentries_5_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(0)(meidx),
        inputStubData_nentries_5_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(1)(meidx),
        inputStubData_nentries_5_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(2)(meidx),
        inputStubData_nentries_5_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(3)(meidx),
        inputStubData_nentries_5_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(4)(meidx),
        inputStubData_nentries_5_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(5)(meidx),
        inputStubData_nentries_5_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(6)(meidx),
        inputStubData_nentries_5_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(5)(7)(meidx),
        inputStubData_nentries_6_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(0)(meidx),
        inputStubData_nentries_6_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(1)(meidx),
        inputStubData_nentries_6_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(2)(meidx),
        inputStubData_nentries_6_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(3)(meidx),
        inputStubData_nentries_6_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(4)(meidx),
        inputStubData_nentries_6_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(5)(meidx),
        inputStubData_nentries_6_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(6)(meidx),
        inputStubData_nentries_6_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(6)(7)(meidx),
        inputStubData_nentries_7_V_0 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(0)(meidx),
        inputStubData_nentries_7_V_1 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(1)(meidx),
        inputStubData_nentries_7_V_2 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(2)(meidx),
        inputStubData_nentries_7_V_3 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(3)(meidx),
        inputStubData_nentries_7_V_4 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(4)(meidx),
        inputStubData_nentries_7_V_5 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(5)(meidx),
        inputStubData_nentries_7_V_6 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(6)(meidx),
        inputStubData_nentries_7_V_7 => VMSME_L3PHIC17to24n1_nentries_V_dout(7)(7)(meidx),
        inputProjectionData_dataarray_data_V_address0 => VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr(meidx),
        inputProjectionData_dataarray_data_V_ce0      => VMPROJ_L3PHIC17to24_dataarray_data_V_enb(meidx),
        inputProjectionData_dataarray_data_V_q0       => VMPROJ_L3PHIC17to24_dataarray_data_V_dout(meidx),
        inputProjectionData_nentries_0_V => VMPROJ_L3PHIC17to24_nentries_V_dout(0)(meidx),
        inputProjectionData_nentries_1_V => VMPROJ_L3PHIC17to24_nentries_V_dout(1)(meidx),
        outputCandidateMatch_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_writeaddr(meidx),
        outputCandidateMatch_dataarray_data_V_ce0      => open,
        outputCandidateMatch_dataarray_data_V_we0      => CM_L3PHIC17to24_dataarray_data_V_wea(meidx),
        outputCandidateMatch_dataarray_data_V_d0       => CM_L3PHIC17to24_dataarray_data_V_din(meidx),
        outputCandidateMatch_nentries_0_V        => CM_L3PHIC17to24_nentries_V_din(0)(meidx),
        outputCandidateMatch_nentries_0_V_ap_vld =>  CM_L3PHIC17to24_nentries_V_we(0)(meidx),
        outputCandidateMatch_nentries_1_V        => CM_L3PHIC17to24_nentries_V_din(1)(meidx),
        outputCandidateMatch_nentries_1_V_ap_vld =>  CM_L3PHIC17to24_nentries_V_we(1)(meidx)
        );

  end generate gen_ME;

  --------------------------------------------------------------
  -- AllStubs memory
  --------------------------------------------------------------
  AS_L3PHICn4 : myMemory
    generic map (
      RAM_WIDTH       => 36,
      RAM_DEPTH       => 1024,
      INIT_FILE       => "",
      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
      HEX             => 0
      )
    port map (
      clka     => clk,
      wea      => AS_L3PHICn4_dataarray_data_V_wea,
      addra    => AS_L3PHICn4_dataarray_data_V_writeaddr,
      dina     => AS_L3PHICn4_dataarray_data_V_din,
      nent_we0 =>  AS_L3PHICn4_nentries_V_we(0),
      nent_i0  => AS_L3PHICn4_nentries_V_din(0),
      nent_we1 =>  AS_L3PHICn4_nentries_V_we(1),
      nent_i1  => AS_L3PHICn4_nentries_V_din(1),
      nent_we2 =>  AS_L3PHICn4_nentries_V_we(2),
      nent_i2  => AS_L3PHICn4_nentries_V_din(2),
      nent_we3 =>  AS_L3PHICn4_nentries_V_we(3),
      nent_i3  => AS_L3PHICn4_nentries_V_din(3),
      nent_we4 =>  AS_L3PHICn4_nentries_V_we(4),
      nent_i4  => AS_L3PHICn4_nentries_V_din(4),
      nent_we5 =>  AS_L3PHICn4_nentries_V_we(5),
      nent_i5  => AS_L3PHICn4_nentries_V_din(5),
      nent_we6 =>  AS_L3PHICn4_nentries_V_we(6),
      nent_i6  => AS_L3PHICn4_nentries_V_din(6),
      nent_we7 =>  AS_L3PHICn4_nentries_V_we(7),
      nent_i7  => AS_L3PHICn4_nentries_V_din(7),
      clkb     => clk,
      rstb     => '0',
      regceb   => '1',
      enb      => AS_L3PHICn4_dataarray_data_V_enb,
      addrb    => AS_L3PHICn4_dataarray_data_V_readaddr,
      doutb    => AS_L3PHICn4_dataarray_data_V_dout,
      nent_o0  => AS_L3PHICn4_nentries_V_dout(0),
      nent_o1  => AS_L3PHICn4_nentries_V_dout(1),
      nent_o2  => AS_L3PHICn4_nentries_V_dout(2),
      nent_o3  => AS_L3PHICn4_nentries_V_dout(3),
      nent_o4  => AS_L3PHICn4_nentries_V_dout(4),
      nent_o5  => AS_L3PHICn4_nentries_V_dout(5),
      nent_o6  => AS_L3PHICn4_nentries_V_dout(6),
      nent_o7  => AS_L3PHICn4_nentries_V_dout(7)
      );


  --------------------------------------------------------------
  -- CandidateMatches memories
  --------------------------------------------------------------
  gen_CM_L3PHIC17to24 : for cmidx in 7 downto 0 generate
  begin
    CM_L3PHIC17to24 : myMemory
      generic map (
        RAM_WIDTH       => 14,
        RAM_DEPTH       => 256,
        INIT_FILE       => "",
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        HEX             => 1
        )
      port map (
        clka     => clk,
        wea      => CM_L3PHIC17to24_dataarray_data_V_wea(cmidx),
        addra    => CM_L3PHIC17to24_dataarray_data_V_writeaddr(cmidx),
        dina     => CM_L3PHIC17to24_dataarray_data_V_din(cmidx),
        nent_we0 =>  CM_L3PHIC17to24_nentries_V_we(0)(cmidx),
        nent_i0  => CM_L3PHIC17to24_nentries_V_din(0)(cmidx),
        nent_we1 =>  CM_L3PHIC17to24_nentries_V_we(1)(cmidx),
        nent_i1  => CM_L3PHIC17to24_nentries_V_din(1)(cmidx),
        nent_we2 => '0',
        nent_i2  => (others=>'0'),
        nent_we3 => '0',
        nent_i3  => (others=>'0'),
        nent_we4 => '0',
        nent_i4  => (others=>'0'),
        nent_we5 => '0',
        nent_i5  => (others=>'0'),
        nent_we6 => '0',
        nent_i6  => (others=>'0'),
        nent_we7 => '0',
        nent_i7  => (others=>'0'),
        clkb     => clk,
        rstb     => '0',
        regceb   => '1',
        enb      => CM_L3PHIC17to24_dataarray_data_V_enb(cmidx),
        addrb    => CM_L3PHIC17to24_dataarray_data_V_readaddr(cmidx),
        doutb    => CM_L3PHIC17to24_dataarray_data_V_dout(cmidx),
        nent_o0  => CM_L3PHIC17to24_nentries_V_dout(0)(cmidx),
        nent_o1  => CM_L3PHIC17to24_nentries_V_dout(1)(cmidx),
        nent_o2  => open,
        nent_o3  => open,
        nent_o4  => open,
        nent_o5  => open,
        nent_o6  => open,
        nent_o7  => open
        );

  end generate gen_CM_L3PHIC17to24;


  --------------------------------------------------------------
  -- MatchCalculator
  --------------------------------------------------------------
  MC_L3PHIC : entity work.MC_L3PHIC
    port map (
      ap_clk   => clk,
      ap_rst   => reset,
      ap_start => MC_start,
      ap_done  => MC_done,
      ap_idle  => MC_idle,
      ap_ready => MC_ready,
      bx_V     => ME_bx_out(0), -- All MEs should have the same counter value
      match_0_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(0),
      match_0_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(0),
      match_0_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(0),
      match_0_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(0),
      match_0_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(0),
      match_1_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(1),
      match_1_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(1),
      match_1_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(1),
      match_1_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(1),
      match_1_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(1),
      match_2_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(2),
      match_2_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(2),
      match_2_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(2),
      match_2_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(2),
      match_2_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(2),
      match_3_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(3),
      match_3_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(3),
      match_3_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(3),
      match_3_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(3),
      match_3_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(3),
      match_4_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(4),
      match_4_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(4),
      match_4_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(4),
      match_4_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(4),
      match_4_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(4),
      match_5_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(5),
      match_5_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(5),
      match_5_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(5),
      match_5_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(5),
      match_5_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(5),
      match_6_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(6),
      match_6_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(6),
      match_6_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(6),
      match_6_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(6),
      match_6_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(6),
      match_7_dataarray_data_V_address0 => CM_L3PHIC17to24_dataarray_data_V_readaddr(7),
      match_7_dataarray_data_V_ce0      => CM_L3PHIC17to24_dataarray_data_V_enb(7),
      match_7_dataarray_data_V_q0       => CM_L3PHIC17to24_dataarray_data_V_dout(7),
      match_7_nentries_0_V              => CM_L3PHIC17to24_nentries_V_dout(0)(7),
      match_7_nentries_1_V              => CM_L3PHIC17to24_nentries_V_dout(1)(7),
      allstub_dataarray_data_V_address0 => AS_L3PHICn4_dataarray_data_V_readaddr,
      allstub_dataarray_data_V_ce0      => AS_L3PHICn4_dataarray_data_V_enb,
      allstub_dataarray_data_V_q0       => AS_L3PHICn4_dataarray_data_V_dout,
      --allstub_nentries_0_V => AS_L3PHICn4_nentries_V_dout(0),
      --allstub_nentries_1_V => AS_L3PHICn4_nentries_V_dout(1),
      --allstub_nentries_2_V => (others=>'0'),
      --allstub_nentries_3_V => (others=>'0'),
      --allstub_nentries_4_V => (others=>'0'),
      --allstub_nentries_5_V => (others=>'0'),
      --allstub_nentries_6_V => (others=>'0'),
      --allstub_nentries_7_V => (others=>'0'),
      allproj_dataarray_data_V_address0 => AP_L3PHIC_dataarray_data_V_readaddr,
      allproj_dataarray_data_V_ce0      => AP_L3PHIC_dataarray_data_V_enb,
      allproj_dataarray_data_V_q0       => AP_L3PHIC_dataarray_data_V_dout,
      --allproj_nentries_0_V => AP_L3PHIC_nentries_0_V_dout,
      --allproj_nentries_1_V => AP_L3PHIC_nentries_1_V_dout,
      --allproj_nentries_2_V => (others=>'0'),
      --allproj_nentries_3_V => (others=>'0'),
      --allproj_nentries_4_V => (others=>'0'),
      --allproj_nentries_5_V => (others=>'0'),
      --allproj_nentries_6_V => (others=>'0'),
      --allproj_nentries_7_V => (others=>'0'),
      bx_o_V        => MC_bx_out,
      bx_o_V_ap_vld => MC_bx_out_vld,
      fullmatch_0_dataarray_data_V_address0 => FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr,
      fullmatch_0_dataarray_data_V_ce0      => open,
      fullmatch_0_dataarray_data_V_we0      => FM_L1L2XX_L3PHIC_dataarray_data_V_wea,
      fullmatch_0_dataarray_data_V_d0       => FM_L1L2XX_L3PHIC_dataarray_data_V_din,
      fullmatch_0_nentries_0_V              => FM_L1L2XX_L3PHIC_nentries_V_din(0),
      fullmatch_0_nentries_0_V_ap_vld       => FM_L1L2XX_L3PHIC_nentries_V_we(0),
      fullmatch_0_nentries_1_V              => FM_L1L2XX_L3PHIC_nentries_V_din(1),
      fullmatch_0_nentries_1_V_ap_vld       => FM_L1L2XX_L3PHIC_nentries_V_we(1),
      fullmatch_1_dataarray_data_V_address0 => open,
      fullmatch_1_dataarray_data_V_ce0      => open,
      fullmatch_1_dataarray_data_V_we0      => open,
      fullmatch_1_dataarray_data_V_d0       => open,
      fullmatch_1_nentries_0_V              => open,
      fullmatch_1_nentries_0_V_ap_vld       => open,
      fullmatch_1_nentries_1_V              => open,
      fullmatch_1_nentries_1_V_ap_vld       => open,
      fullmatch_2_dataarray_data_V_address0 => open,
      fullmatch_2_dataarray_data_V_ce0      => open,
      fullmatch_2_dataarray_data_V_we0      => open,
      fullmatch_2_dataarray_data_V_d0       => open,
      fullmatch_2_nentries_0_V              => open,
      fullmatch_2_nentries_0_V_ap_vld       => open,
      fullmatch_2_nentries_1_V              => open,
      fullmatch_2_nentries_1_V_ap_vld       => open,
      fullmatch_3_dataarray_data_V_address0 => FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr,
      fullmatch_3_dataarray_data_V_ce0      => open,
      fullmatch_3_dataarray_data_V_we0      => FM_L5L6XX_L3PHIC_dataarray_data_V_wea,
      fullmatch_3_dataarray_data_V_d0       => FM_L5L6XX_L3PHIC_dataarray_data_V_din,
      fullmatch_3_nentries_0_V              => FM_L5L6XX_L3PHIC_nentries_V_din(0),
      fullmatch_3_nentries_0_V_ap_vld       => FM_L5L6XX_L3PHIC_nentries_V_we(0),
      fullmatch_3_nentries_1_V              => FM_L5L6XX_L3PHIC_nentries_V_din(1),
      fullmatch_3_nentries_1_V_ap_vld       => FM_L5L6XX_L3PHIC_nentries_V_we(1),
      fullmatch_4_dataarray_data_V_address0 => open,
      fullmatch_4_dataarray_data_V_ce0      => open,
      fullmatch_4_dataarray_data_V_we0      => open,
      fullmatch_4_dataarray_data_V_d0       => open,
      fullmatch_4_nentries_0_V              => open,
      fullmatch_4_nentries_0_V_ap_vld       => open,
      fullmatch_4_nentries_1_V              => open,
      fullmatch_4_nentries_1_V_ap_vld       => open,
      fullmatch_5_dataarray_data_V_address0 => open,
      fullmatch_5_dataarray_data_V_ce0      => open,
      fullmatch_5_dataarray_data_V_we0      => open,
      fullmatch_5_dataarray_data_V_d0       => open,
      fullmatch_5_nentries_0_V              => open,
      fullmatch_5_nentries_0_V_ap_vld       => open,
      fullmatch_5_nentries_1_V              => open,
      fullmatch_5_nentries_1_V_ap_vld       => open,
      fullmatch_6_dataarray_data_V_address0 => open,
      fullmatch_6_dataarray_data_V_ce0      => open,
      fullmatch_6_dataarray_data_V_we0      => open,
      fullmatch_6_dataarray_data_V_d0       => open,
      fullmatch_6_nentries_0_V              => open,
      fullmatch_6_nentries_0_V_ap_vld       => open,
      fullmatch_6_nentries_1_V              => open,
      fullmatch_6_nentries_1_V_ap_vld       => open,
      fullmatch_7_dataarray_data_V_address0 => open,
      fullmatch_7_dataarray_data_V_ce0      => open,
      fullmatch_7_dataarray_data_V_we0      => open,
      fullmatch_7_dataarray_data_V_d0       => open,
      fullmatch_7_nentries_0_V              => open,
      fullmatch_7_nentries_0_V_ap_vld       => open,
      fullmatch_7_nentries_1_V              => open,
      fullmatch_7_nentries_1_V_ap_vld       => open
      );


  --------------------------------------------------------------
  -- FullMatches memories
  --------------------------------------------------------------
  FM_L1L2XX_L3PHIC : myMemory
    generic map (
      RAM_WIDTH       => 45,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
      HEX             => 0
      )
    port map (
      clka     => clk,
      wea      => FM_L1L2XX_L3PHIC_dataarray_data_V_wea,
      addra    => FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr,
      dina     => FM_L1L2XX_L3PHIC_dataarray_data_V_din,
      nent_we0 => FM_L1L2XX_L3PHIC_nentries_V_we(0),
      nent_i0  => FM_L1L2XX_L3PHIC_nentries_V_din(0),
      nent_we1 => FM_L1L2XX_L3PHIC_nentries_V_we(1),
      nent_i1  => FM_L1L2XX_L3PHIC_nentries_V_din(1),
      nent_we2 => '0',
      nent_i2  => (others=>'0'),
      nent_we3 => '0',
      nent_i3  => (others=>'0'),
      nent_we4 => '0',
      nent_i4  => (others=>'0'),
      nent_we5 => '0',
      nent_i5  => (others=>'0'),
      nent_we6 => '0',
      nent_i6  => (others=>'0'),
      nent_we7 => '0',
      nent_i7  => (others=>'0'),
      clkb     => clk,
      rstb     => '0',
      regceb   => '1',
      enb      => FM_L1L2XX_L3PHIC_dataarray_data_V_enb,
      addrb    => FM_L1L2XX_L3PHIC_dataarray_data_V_readaddr,
      doutb    => FM_L1L2XX_L3PHIC_dataarray_data_V_dout,
      nent_o0  => FM_L1L2XX_L3PHIC_nentries_V_dout(0),
      nent_o1  => FM_L1L2XX_L3PHIC_nentries_V_dout(1),
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
      );

  FM_L5L6XX_L3PHIC : myMemory
    generic map (
      RAM_WIDTH       => 45,
      RAM_DEPTH       => 256,
      INIT_FILE       => "",
      RAM_PERFORMANCE => "HIGH_PERFORMANCE",
      HEX             => 0
      )
    port map (
      clka     => clk,
      wea      => FM_L5L6XX_L3PHIC_dataarray_data_V_wea,
      addra    => FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr,
      dina     => FM_L5L6XX_L3PHIC_dataarray_data_V_din,
      nent_we0 => FM_L5L6XX_L3PHIC_nentries_V_we(0),
      nent_i0  => FM_L5L6XX_L3PHIC_nentries_V_din(0),
      nent_we1 => FM_L5L6XX_L3PHIC_nentries_V_we(1),
      nent_i1  => FM_L5L6XX_L3PHIC_nentries_V_din(1),
      nent_we2 => '0',
      nent_i2  => (others=>'0'),
      nent_we3 => '0',
      nent_i3  => (others=>'0'),
      nent_we4 => '0',
      nent_i4  => (others=>'0'),
      nent_we5 => '0',
      nent_i5  => (others=>'0'),
      nent_we6 => '0',
      nent_i6  => (others=>'0'),
      nent_we7 => '0',
      nent_i7  => (others=>'0'),
      clkb     => clk,
      rstb     => '0',
      regceb   => '1',
      enb      => FM_L5L6XX_L3PHIC_dataarray_data_V_enb,
      addrb    => FM_L5L6XX_L3PHIC_dataarray_data_V_readaddr,
      doutb    => FM_L5L6XX_L3PHIC_dataarray_data_V_dout,
      nent_o0  => FM_L5L6XX_L3PHIC_nentries_V_dout(0),
      nent_o1  => FM_L5L6XX_L3PHIC_nentries_V_dout(1),
      nent_o2  => open,
      nent_o3  => open,
      nent_o4  => open,
      nent_o5  => open,
      nent_o6  => open,
      nent_o7  => open
      );

end rtl;
