--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;

entity SectorProcessorFull is
  port(
    clk240     : in std_logic;
    clk360     : in std_logic;
    reset      : in std_logic;
    PC_start  : in std_logic;
    PC_bx_in : in std_logic_vector(2 downto 0);
    PC_bx_out : out std_logic_vector(2 downto 0);
    PC_bx_out_vld : out std_logic;
    PC_done : out std_logic;
    TB_bx_out : out std_logic_vector(2 downto 0);
    TB_bx_out_vld : out std_logic;
    TB_done   : out std_logic;
    TB_AAAA_last_track   : out std_logic;
    TB_AAAA_last_track_vld   : out std_logic;
    VMSMER_bx_out : out std_logic_vector(2 downto 0);
    VMSMER_bx_out_vld : out std_logic;
    VMSMER_done   : out std_logic;
    MP_bx_out : out std_logic_vector(2 downto 0);
    MP_bx_out_vld : out std_logic;
    MP_done   : out std_logic;

    -- ####### Legacy port #####
    -- AS_L1PHIAin_wea        : in t_AS_36_1b;
    -- AS_L1PHIAin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIAin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    -- AS_L1PHIAin_read_en_FIFO   : out std_logic;  -- or fancier? like t_AS_36_1b which is still std_logic?
    AS_L1PHIAin_empty_neg_FIFO : in std_logic;
    AS_L1PHIAin_data_FIFO : in t_AS_36_DATA;  
    -- readAS_L1PHIAin_start_FIFO : out std_logic;
    
    -- ####### Legacy port ##########
    -- AS_L1PHIBin_wea        : in t_AS_36_1b;
    -- AS_L1PHIBin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIBin_din       : in t_AS_36_DATA;
    -- ######## New port ########
    AS_L1PHIBin_empty_neg_FIFO : in std_logic;
    AS_L1PHIBin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L1PHICin_wea        : in t_AS_36_1b;
    -- AS_L1PHICin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHICin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHICin_empty_neg_FIFO : in std_logic;
    AS_L1PHICin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L1PHIDin_wea        : in t_AS_36_1b;
    -- AS_L1PHIDin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIDin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHIDin_empty_neg_FIFO : in std_logic;
    AS_L1PHIDin_data_FIFO : in t_AS_36_DATA;  

    

    -- ####### Legacy port ##########
    -- AS_L1PHIEin_wea        : in t_AS_36_1b;
    -- AS_L1PHIEin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIEin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHIEin_empty_neg_FIFO : in std_logic;
    AS_L1PHIEin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L1PHIFin_wea        : in t_AS_36_1b;
    -- AS_L1PHIFin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIFin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHIFin_empty_neg_FIFO : in std_logic;
    AS_L1PHIFin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L1PHIGin_wea        : in t_AS_36_1b;
    -- AS_L1PHIGin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIGin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHIGin_empty_neg_FIFO : in std_logic;
    AS_L1PHIGin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L1PHIHin_wea        : in t_AS_36_1b;
    -- AS_L1PHIHin_writeaddr : in t_AS_36_ADDR;
    -- AS_L1PHIHin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L1PHIHin_empty_neg_FIFO : in std_logic;
    AS_L1PHIHin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L2PHIAin_wea        : in t_AS_36_1b;
    -- AS_L2PHIAin_writeaddr : in t_AS_36_ADDR;
    -- AS_L2PHIAin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L2PHIAin_empty_neg_FIFO : in std_logic;
    AS_L2PHIAin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L2PHIBin_wea        : in t_AS_36_1b;
    -- AS_L2PHIBin_writeaddr : in t_AS_36_ADDR;
    -- AS_L2PHIBin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L2PHIBin_empty_neg_FIFO : in std_logic;
    AS_L2PHIBin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L2PHICin_wea        : in t_AS_36_1b;
    -- AS_L2PHICin_writeaddr : in t_AS_36_ADDR;
    -- AS_L2PHICin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L2PHICin_empty_neg_FIFO : in std_logic;
    AS_L2PHICin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L2PHIDin_wea        : in t_AS_36_1b;
    -- AS_L2PHIDin_writeaddr : in t_AS_36_ADDR;
    -- AS_L2PHIDin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L2PHIDin_empty_neg_FIFO : in std_logic;
    AS_L2PHIDin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L3PHIAin_wea        : in t_AS_36_1b;
    -- AS_L3PHIAin_writeaddr : in t_AS_36_ADDR;
    -- AS_L3PHIAin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L3PHIAin_empty_neg_FIFO : in std_logic;
    AS_L3PHIAin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L3PHIBin_wea        : in t_AS_36_1b;
    -- AS_L3PHIBin_writeaddr : in t_AS_36_ADDR;
    -- AS_L3PHIBin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L3PHIBin_empty_neg_FIFO : in std_logic;
    AS_L3PHIBin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L3PHICin_wea        : in t_AS_36_1b;
    -- AS_L3PHICin_writeaddr : in t_AS_36_ADDR;
    -- AS_L3PHICin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L3PHICin_empty_neg_FIFO : in std_logic;
    AS_L3PHICin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L3PHIDin_wea        : in t_AS_36_1b;
    -- AS_L3PHIDin_writeaddr : in t_AS_36_ADDR;
    -- AS_L3PHIDin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L3PHIDin_empty_neg_FIFO : in std_logic;
    AS_L3PHIDin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L4PHIAin_wea        : in t_AS_36_1b;
    -- AS_L4PHIAin_writeaddr : in t_AS_36_ADDR;
    -- AS_L4PHIAin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L4PHIAin_empty_neg_FIFO : in std_logic;
    AS_L4PHIAin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L4PHIBin_wea        : in t_AS_36_1b;
    -- AS_L4PHIBin_writeaddr : in t_AS_36_ADDR;
    -- AS_L4PHIBin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L4PHIBin_empty_neg_FIFO : in std_logic;
    AS_L4PHIBin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L4PHICin_wea        : in t_AS_36_1b;
    -- AS_L4PHICin_writeaddr : in t_AS_36_ADDR;
    -- AS_L4PHICin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L4PHICin_empty_neg_FIFO : in std_logic;
    AS_L4PHICin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    -- AS_L4PHIDin_wea        : in t_AS_36_1b;
    -- AS_L4PHIDin_writeaddr : in t_AS_36_ADDR;
    -- AS_L4PHIDin_din       : in t_AS_36_DATA;

    -- ######## New port ########
    AS_L4PHIDin_empty_neg_FIFO : in std_logic;
    AS_L4PHIDin_data_FIFO : in t_AS_36_DATA;  

    
    -- ####### Legacy port ##########
    VMSME_L1PHIAn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIAn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIAn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIBn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIBn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIBn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHICn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHICn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHICn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIDn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIDn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIDn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIEn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIEn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIEn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIFn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIFn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIFn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIGn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIGn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIGn2_din       : out t_VMSME_16_DATA;
    VMSME_L1PHIHn2_wea        : out t_VMSME_16_1b;
    VMSME_L1PHIHn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L1PHIHn2_din       : out t_VMSME_16_DATA;
    VMSME_L2PHIAn2_wea        : out t_VMSME_16_1b;
    VMSME_L2PHIAn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L2PHIAn2_din       : out t_VMSME_16_DATA;
    VMSME_L2PHIBn2_wea        : out t_VMSME_16_1b;
    VMSME_L2PHIBn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L2PHIBn2_din       : out t_VMSME_16_DATA;
    VMSME_L2PHICn2_wea        : out t_VMSME_16_1b;
    VMSME_L2PHICn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L2PHICn2_din       : out t_VMSME_16_DATA;
    VMSME_L2PHIDn2_wea        : out t_VMSME_16_1b;
    VMSME_L2PHIDn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L2PHIDn2_din       : out t_VMSME_16_DATA;
    VMSME_L3PHIAn2_wea        : out t_VMSME_16_1b;
    VMSME_L3PHIAn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L3PHIAn2_din       : out t_VMSME_16_DATA;
    VMSME_L3PHIBn2_wea        : out t_VMSME_16_1b;
    VMSME_L3PHIBn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L3PHIBn2_din       : out t_VMSME_16_DATA;
    VMSME_L3PHICn2_wea        : out t_VMSME_16_1b;
    VMSME_L3PHICn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L3PHICn2_din       : out t_VMSME_16_DATA;
    VMSME_L3PHIDn2_wea        : out t_VMSME_16_1b;
    VMSME_L3PHIDn2_writeaddr : out t_VMSME_16_ADDR;
    VMSME_L3PHIDn2_din       : out t_VMSME_16_DATA;
    VMSME_L4PHIAn2_wea        : out t_VMSME_17_1b;
    VMSME_L4PHIAn2_writeaddr : out t_VMSME_17_ADDR;
    VMSME_L4PHIAn2_din       : out t_VMSME_17_DATA;
    VMSME_L4PHIBn2_wea        : out t_VMSME_17_1b;
    VMSME_L4PHIBn2_writeaddr : out t_VMSME_17_ADDR;
    VMSME_L4PHIBn2_din       : out t_VMSME_17_DATA;
    VMSME_L4PHICn2_wea        : out t_VMSME_17_1b;
    VMSME_L4PHICn2_writeaddr : out t_VMSME_17_ADDR;
    VMSME_L4PHICn2_din       : out t_VMSME_17_DATA;
    VMSME_L4PHIDn2_wea        : out t_VMSME_17_1b;
    VMSME_L4PHIDn2_writeaddr : out t_VMSME_17_ADDR;
    VMSME_L4PHIDn2_din       : out t_VMSME_17_DATA;
    MPAR_L5L6ABCDin_wea        : in t_MPAR_73_1b;
    MPAR_L5L6ABCDin_writeaddr : in t_MPAR_73_ADDR;
    MPAR_L5L6ABCDin_din       : in t_MPAR_73_DATA;
    MPROJ_L5L6ABCD_L1PHIA_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIA_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIA_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIB_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIB_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIB_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIC_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIC_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIC_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHID_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHID_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHID_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIE_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIE_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIE_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIF_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIF_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIF_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIG_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIG_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIG_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L1PHIH_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L1PHIH_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L1PHIH_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L2PHIA_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L2PHIA_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L2PHIA_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L2PHIB_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L2PHIB_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L2PHIB_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L2PHIC_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L2PHIC_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L2PHIC_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L2PHID_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L2PHID_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L2PHID_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L3PHIA_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L3PHIA_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L3PHIA_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L3PHIB_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L3PHIB_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L3PHIB_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L3PHIC_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L3PHIC_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L3PHIC_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L3PHID_wea        : out t_MPROJ_60_1b;
    MPROJ_L5L6ABCD_L3PHID_writeaddr : out t_MPROJ_60_ADDR;
    MPROJ_L5L6ABCD_L3PHID_din       : out t_MPROJ_60_DATA;
    MPROJ_L5L6ABCD_L4PHIA_wea        : out t_MPROJ_58_1b;
    MPROJ_L5L6ABCD_L4PHIA_writeaddr : out t_MPROJ_58_ADDR;
    MPROJ_L5L6ABCD_L4PHIA_din       : out t_MPROJ_58_DATA;
    MPROJ_L5L6ABCD_L4PHIB_wea        : out t_MPROJ_58_1b;
    MPROJ_L5L6ABCD_L4PHIB_writeaddr : out t_MPROJ_58_ADDR;
    MPROJ_L5L6ABCD_L4PHIB_din       : out t_MPROJ_58_DATA;
    MPROJ_L5L6ABCD_L4PHIC_wea        : out t_MPROJ_58_1b;
    MPROJ_L5L6ABCD_L4PHIC_writeaddr : out t_MPROJ_58_ADDR;
    MPROJ_L5L6ABCD_L4PHIC_din       : out t_MPROJ_58_DATA;
    MPROJ_L5L6ABCD_L4PHID_wea        : out t_MPROJ_58_1b;
    MPROJ_L5L6ABCD_L4PHID_writeaddr : out t_MPROJ_58_ADDR;
    MPROJ_L5L6ABCD_L4PHID_din       : out t_MPROJ_58_DATA;
    FM_AAAA_L1PHIA_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIA_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIA_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIB_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIB_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIB_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIC_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIC_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIC_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHID_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHID_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHID_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIE_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIE_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIE_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIF_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIF_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIF_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIG_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIG_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIG_din       : out t_FM_52_DATA;
    FM_AAAA_L1PHIH_wea        : out t_FM_52_1b;
    FM_AAAA_L1PHIH_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L1PHIH_din       : out t_FM_52_DATA;
    FM_AAAA_L2PHIA_wea        : out t_FM_52_1b;
    FM_AAAA_L2PHIA_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L2PHIA_din       : out t_FM_52_DATA;
    FM_AAAA_L2PHIB_wea        : out t_FM_52_1b;
    FM_AAAA_L2PHIB_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L2PHIB_din       : out t_FM_52_DATA;
    FM_AAAA_L2PHIC_wea        : out t_FM_52_1b;
    FM_AAAA_L2PHIC_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L2PHIC_din       : out t_FM_52_DATA;
    FM_AAAA_L2PHID_wea        : out t_FM_52_1b;
    FM_AAAA_L2PHID_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L2PHID_din       : out t_FM_52_DATA;
    FM_AAAA_L3PHIA_wea        : out t_FM_52_1b;
    FM_AAAA_L3PHIA_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L3PHIA_din       : out t_FM_52_DATA;
    FM_AAAA_L3PHIB_wea        : out t_FM_52_1b;
    FM_AAAA_L3PHIB_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L3PHIB_din       : out t_FM_52_DATA;
    FM_AAAA_L3PHIC_wea        : out t_FM_52_1b;
    FM_AAAA_L3PHIC_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L3PHIC_din       : out t_FM_52_DATA;
    FM_AAAA_L3PHID_wea        : out t_FM_52_1b;
    FM_AAAA_L3PHID_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L3PHID_din       : out t_FM_52_DATA;
    FM_AAAA_L4PHIA_wea        : out t_FM_52_1b;
    FM_AAAA_L4PHIA_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L4PHIA_din       : out t_FM_52_DATA;
    FM_AAAA_L4PHIB_wea        : out t_FM_52_1b;
    FM_AAAA_L4PHIB_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L4PHIB_din       : out t_FM_52_DATA;
    FM_AAAA_L4PHIC_wea        : out t_FM_52_1b;
    FM_AAAA_L4PHIC_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L4PHIC_din       : out t_FM_52_DATA;
    FM_AAAA_L4PHID_wea        : out t_FM_52_1b;
    FM_AAAA_L4PHID_writeaddr : out t_FM_52_ADDR;
    FM_AAAA_L4PHID_din       : out t_FM_52_DATA;
    TW_AAAA_stream_AV_din       : out t_TW_113_DATA;
    TW_AAAA_stream_A_full_neg   : in t_TW_113_1b;
    TW_AAAA_stream_A_write      : out t_TW_113_1b;
    DW_AAAA_D1_stream_AV_din       : out t_DW_49_DATA;
    DW_AAAA_D1_stream_A_full_neg   : in t_DW_49_1b;
    DW_AAAA_D1_stream_A_write      : out t_DW_49_1b;
    DW_AAAA_D2_stream_AV_din       : out t_DW_49_DATA;
    DW_AAAA_D2_stream_A_full_neg   : in t_DW_49_1b;
    DW_AAAA_D2_stream_A_write      : out t_DW_49_1b;
    DW_AAAA_D3_stream_AV_din       : out t_DW_49_DATA;
    DW_AAAA_D3_stream_A_full_neg   : in t_DW_49_1b;
    DW_AAAA_D3_stream_A_write      : out t_DW_49_1b;
    DW_AAAA_D4_stream_AV_din       : out t_DW_49_DATA;
    DW_AAAA_D4_stream_A_full_neg   : in t_DW_49_1b;
    DW_AAAA_D4_stream_A_write      : out t_DW_49_1b;
    DW_AAAA_D5_stream_AV_din       : out t_DW_49_DATA;
    DW_AAAA_D5_stream_A_full_neg   : in t_DW_49_1b;
    DW_AAAA_D5_stream_A_write      : out t_DW_49_1b;
    BW_AAAA_L1_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L1_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L1_stream_A_write      : out t_BW_46_1b;
    BW_AAAA_L2_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L2_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L2_stream_A_write      : out t_BW_46_1b;
    BW_AAAA_L3_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L3_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L3_stream_A_write      : out t_BW_46_1b;
    BW_AAAA_L4_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L4_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L4_stream_A_write      : out t_BW_46_1b;
    BW_AAAA_L5_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L5_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L5_stream_A_write      : out t_BW_46_1b;
    BW_AAAA_L6_stream_AV_din       : out t_BW_46_DATA;
    BW_AAAA_L6_stream_A_full_neg   : in t_BW_46_1b;
    BW_AAAA_L6_stream_A_write      : out t_BW_46_1b
  );
end SectorProcessorFull;

architecture rtl of SectorProcessorFull is


  -- signal AS_L1PHIAin_start                   : std_logic;
  -- signal AS_L1PHIAin_wea_delay          : t_AS_36_1b;
  -- signal AS_L1PHIAin_writeaddr_delay   : t_AS_36_ADDR;

  -- ######## Legacy signal########
  -- signal AS_L1PHIAin_din_delay         : t_AS_36_DATA;
  -- signal AS_L1PHIAin_enb          : t_AS_36_1b := '1';
  -- signal AS_L1PHIAin_V_readaddr    : t_AS_36_ADDR;
  -- signal AS_L1PHIAin_V_dout        : t_AS_36_DATA;
  -- signal AS_L1PHIAin_V_as        : t_AS_36_DATA;
  -- signal AS_L1PHIAin_valid        : STD_LOGIC;
  -- signal AS_L1PHIAin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIAin_AV_dout_nent  : t_AS_36_NENT; -- (#page)

-- ############ New signal ##########
  -- signal AS_L1PHIAin_DELAY_wea_FIFO : std_logic := '1';
  -- signal AS_L1PHIAin_DELAY_wea_FIFO_delay : std_logic;

  signal AS_L1PHIBin_start                   : std_logic;
  signal AS_L1PHIBin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIBin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIBin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIBin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIBin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIBin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIBin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIBin_valid        : STD_LOGIC;
  signal AS_L1PHIBin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIBin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHICin_start                   : std_logic;
  signal AS_L1PHICin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHICin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHICin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHICin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHICin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHICin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHICin_V_as        : t_AS_36_DATA;
  signal AS_L1PHICin_valid        : STD_LOGIC;
  signal AS_L1PHICin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHICin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIDin_start                   : std_logic;
  signal AS_L1PHIDin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIDin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIDin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIDin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIDin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIDin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIDin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIDin_valid        : STD_LOGIC;
  signal AS_L1PHIDin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIDin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIEin_start                   : std_logic;
  signal AS_L1PHIEin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIEin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIEin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIEin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIEin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIEin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIEin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIEin_valid        : STD_LOGIC;
  signal AS_L1PHIEin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIEin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIFin_start                   : std_logic;
  signal AS_L1PHIFin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIFin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIFin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIFin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIFin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIFin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIFin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIFin_valid        : STD_LOGIC;
  signal AS_L1PHIFin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIFin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIGin_start                   : std_logic;
  signal AS_L1PHIGin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIGin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIGin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIGin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIGin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIGin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIGin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIGin_valid        : STD_LOGIC;
  signal AS_L1PHIGin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIGin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIHin_start                   : std_logic;
  signal AS_L1PHIHin_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIHin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIHin_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIHin_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIHin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIHin_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIHin_V_as        : t_AS_36_DATA;
  signal AS_L1PHIHin_valid        : STD_LOGIC;
  signal AS_L1PHIHin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L1PHIHin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIAin_start                   : std_logic;
  signal AS_L2PHIAin_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIAin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIAin_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIAin_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIAin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIAin_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIAin_V_as        : t_AS_36_DATA;
  signal AS_L2PHIAin_valid        : STD_LOGIC;
  signal AS_L2PHIAin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L2PHIAin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIBin_start                   : std_logic;
  signal AS_L2PHIBin_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIBin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIBin_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIBin_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIBin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIBin_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIBin_V_as        : t_AS_36_DATA;
  signal AS_L2PHIBin_valid        : STD_LOGIC;
  signal AS_L2PHIBin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L2PHIBin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHICin_start                   : std_logic;
  signal AS_L2PHICin_wea_delay          : t_AS_36_1b;
  signal AS_L2PHICin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHICin_din_delay         : t_AS_36_DATA;
  signal AS_L2PHICin_enb          : t_AS_36_1b := '1';
  signal AS_L2PHICin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHICin_V_dout        : t_AS_36_DATA;
  signal AS_L2PHICin_V_as        : t_AS_36_DATA;
  signal AS_L2PHICin_valid        : STD_LOGIC;
  signal AS_L2PHICin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L2PHICin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIDin_start                   : std_logic;
  signal AS_L2PHIDin_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIDin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIDin_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIDin_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIDin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIDin_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIDin_V_as        : t_AS_36_DATA;
  signal AS_L2PHIDin_valid        : STD_LOGIC;
  signal AS_L2PHIDin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L2PHIDin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIAin_start                   : std_logic;
  signal AS_L3PHIAin_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIAin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIAin_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIAin_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIAin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIAin_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIAin_V_as        : t_AS_36_DATA;
  signal AS_L3PHIAin_valid        : STD_LOGIC;
  signal AS_L3PHIAin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L3PHIAin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIBin_start                   : std_logic;
  signal AS_L3PHIBin_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIBin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIBin_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIBin_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIBin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIBin_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIBin_V_as        : t_AS_36_DATA;
  signal AS_L3PHIBin_valid        : STD_LOGIC;
  signal AS_L3PHIBin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L3PHIBin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHICin_start                   : std_logic;
  signal AS_L3PHICin_wea_delay          : t_AS_36_1b;
  signal AS_L3PHICin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHICin_din_delay         : t_AS_36_DATA;
  signal AS_L3PHICin_enb          : t_AS_36_1b := '1';
  signal AS_L3PHICin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHICin_V_dout        : t_AS_36_DATA;
  signal AS_L3PHICin_V_as        : t_AS_36_DATA;
  signal AS_L3PHICin_valid        : STD_LOGIC;
  signal AS_L3PHICin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L3PHICin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIDin_start                   : std_logic;
  signal AS_L3PHIDin_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIDin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIDin_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIDin_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIDin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIDin_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIDin_V_as        : t_AS_36_DATA;
  signal AS_L3PHIDin_valid        : STD_LOGIC;
  signal AS_L3PHIDin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L3PHIDin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIAin_start                   : std_logic;
  signal AS_L4PHIAin_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIAin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIAin_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIAin_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIAin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIAin_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIAin_V_as        : t_AS_36_DATA;
  signal AS_L4PHIAin_valid        : STD_LOGIC;
  signal AS_L4PHIAin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L4PHIAin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIBin_start                   : std_logic;
  signal AS_L4PHIBin_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIBin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIBin_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIBin_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIBin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIBin_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIBin_V_as        : t_AS_36_DATA;
  signal AS_L4PHIBin_valid        : STD_LOGIC;
  signal AS_L4PHIBin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L4PHIBin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHICin_start                   : std_logic;
  signal AS_L4PHICin_wea_delay          : t_AS_36_1b;
  signal AS_L4PHICin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHICin_din_delay         : t_AS_36_DATA;
  signal AS_L4PHICin_enb          : t_AS_36_1b := '1';
  signal AS_L4PHICin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHICin_V_dout        : t_AS_36_DATA;
  signal AS_L4PHICin_V_as        : t_AS_36_DATA;
  signal AS_L4PHICin_valid        : STD_LOGIC;
  signal AS_L4PHICin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L4PHICin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIDin_start                   : std_logic;
  signal AS_L4PHIDin_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIDin_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIDin_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIDin_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIDin_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIDin_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIDin_V_as        : t_AS_36_DATA;
  signal AS_L4PHIDin_valid        : STD_LOGIC;
  signal AS_L4PHIDin_index        : STD_LOGIC_VECTOR(31 downto 0);
  signal AS_L4PHIDin_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIAn2_start                   : std_logic;
  signal AS_L1PHIAn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIAn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIAn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIAn2_wea          : t_AS_36_1b;
  signal AS_L1PHIAn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIAn2_din         : t_AS_36_DATA;
  signal AS_L1PHIAn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIAn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIAn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIAn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIBn2_start                   : std_logic;
  signal AS_L1PHIBn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIBn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIBn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIBn2_wea          : t_AS_36_1b;
  signal AS_L1PHIBn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIBn2_din         : t_AS_36_DATA;
  signal AS_L1PHIBn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIBn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIBn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIBn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHICn2_start                   : std_logic;
  signal AS_L1PHICn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHICn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHICn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHICn2_wea          : t_AS_36_1b;
  signal AS_L1PHICn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHICn2_din         : t_AS_36_DATA;
  signal AS_L1PHICn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHICn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHICn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHICn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIDn2_start                   : std_logic;
  signal AS_L1PHIDn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIDn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIDn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIDn2_wea          : t_AS_36_1b;
  signal AS_L1PHIDn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIDn2_din         : t_AS_36_DATA;
  signal AS_L1PHIDn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIDn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIDn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIDn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIEn2_start                   : std_logic;
  signal AS_L1PHIEn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIEn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIEn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIEn2_wea          : t_AS_36_1b;
  signal AS_L1PHIEn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIEn2_din         : t_AS_36_DATA;
  signal AS_L1PHIEn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIEn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIEn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIEn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIFn2_start                   : std_logic;
  signal AS_L1PHIFn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIFn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIFn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIFn2_wea          : t_AS_36_1b;
  signal AS_L1PHIFn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIFn2_din         : t_AS_36_DATA;
  signal AS_L1PHIFn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIFn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIFn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIFn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIGn2_start                   : std_logic;
  signal AS_L1PHIGn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIGn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIGn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIGn2_wea          : t_AS_36_1b;
  signal AS_L1PHIGn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIGn2_din         : t_AS_36_DATA;
  signal AS_L1PHIGn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIGn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIGn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIGn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L1PHIHn2_start                   : std_logic;
  signal AS_L1PHIHn2_wea_delay          : t_AS_36_1b;
  signal AS_L1PHIHn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L1PHIHn2_din_delay         : t_AS_36_DATA;
  signal AS_L1PHIHn2_wea          : t_AS_36_1b;
  signal AS_L1PHIHn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L1PHIHn2_din         : t_AS_36_DATA;
  signal AS_L1PHIHn2_enb          : t_AS_36_1b := '1';
  signal AS_L1PHIHn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L1PHIHn2_V_dout        : t_AS_36_DATA;
  signal AS_L1PHIHn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIAn2_start                   : std_logic;
  signal AS_L2PHIAn2_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIAn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIAn2_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIAn2_wea          : t_AS_36_1b;
  signal AS_L2PHIAn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L2PHIAn2_din         : t_AS_36_DATA;
  signal AS_L2PHIAn2_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIAn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIAn2_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIAn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIBn2_start                   : std_logic;
  signal AS_L2PHIBn2_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIBn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIBn2_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIBn2_wea          : t_AS_36_1b;
  signal AS_L2PHIBn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L2PHIBn2_din         : t_AS_36_DATA;
  signal AS_L2PHIBn2_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIBn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIBn2_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIBn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHICn2_start                   : std_logic;
  signal AS_L2PHICn2_wea_delay          : t_AS_36_1b;
  signal AS_L2PHICn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHICn2_din_delay         : t_AS_36_DATA;
  signal AS_L2PHICn2_wea          : t_AS_36_1b;
  signal AS_L2PHICn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L2PHICn2_din         : t_AS_36_DATA;
  signal AS_L2PHICn2_enb          : t_AS_36_1b := '1';
  signal AS_L2PHICn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHICn2_V_dout        : t_AS_36_DATA;
  signal AS_L2PHICn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L2PHIDn2_start                   : std_logic;
  signal AS_L2PHIDn2_wea_delay          : t_AS_36_1b;
  signal AS_L2PHIDn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L2PHIDn2_din_delay         : t_AS_36_DATA;
  signal AS_L2PHIDn2_wea          : t_AS_36_1b;
  signal AS_L2PHIDn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L2PHIDn2_din         : t_AS_36_DATA;
  signal AS_L2PHIDn2_enb          : t_AS_36_1b := '1';
  signal AS_L2PHIDn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L2PHIDn2_V_dout        : t_AS_36_DATA;
  signal AS_L2PHIDn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIAn2_start                   : std_logic;
  signal AS_L3PHIAn2_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIAn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIAn2_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIAn2_wea          : t_AS_36_1b;
  signal AS_L3PHIAn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L3PHIAn2_din         : t_AS_36_DATA;
  signal AS_L3PHIAn2_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIAn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIAn2_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIAn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIBn2_start                   : std_logic;
  signal AS_L3PHIBn2_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIBn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIBn2_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIBn2_wea          : t_AS_36_1b;
  signal AS_L3PHIBn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L3PHIBn2_din         : t_AS_36_DATA;
  signal AS_L3PHIBn2_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIBn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIBn2_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIBn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHICn2_start                   : std_logic;
  signal AS_L3PHICn2_wea_delay          : t_AS_36_1b;
  signal AS_L3PHICn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHICn2_din_delay         : t_AS_36_DATA;
  signal AS_L3PHICn2_wea          : t_AS_36_1b;
  signal AS_L3PHICn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L3PHICn2_din         : t_AS_36_DATA;
  signal AS_L3PHICn2_enb          : t_AS_36_1b := '1';
  signal AS_L3PHICn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHICn2_V_dout        : t_AS_36_DATA;
  signal AS_L3PHICn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L3PHIDn2_start                   : std_logic;
  signal AS_L3PHIDn2_wea_delay          : t_AS_36_1b;
  signal AS_L3PHIDn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L3PHIDn2_din_delay         : t_AS_36_DATA;
  signal AS_L3PHIDn2_wea          : t_AS_36_1b;
  signal AS_L3PHIDn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L3PHIDn2_din         : t_AS_36_DATA;
  signal AS_L3PHIDn2_enb          : t_AS_36_1b := '1';
  signal AS_L3PHIDn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L3PHIDn2_V_dout        : t_AS_36_DATA;
  signal AS_L3PHIDn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIAn2_start                   : std_logic;
  signal AS_L4PHIAn2_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIAn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIAn2_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIAn2_wea          : t_AS_36_1b;
  signal AS_L4PHIAn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L4PHIAn2_din         : t_AS_36_DATA;
  signal AS_L4PHIAn2_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIAn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIAn2_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIAn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIBn2_start                   : std_logic;
  signal AS_L4PHIBn2_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIBn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIBn2_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIBn2_wea          : t_AS_36_1b;
  signal AS_L4PHIBn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L4PHIBn2_din         : t_AS_36_DATA;
  signal AS_L4PHIBn2_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIBn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIBn2_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIBn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHICn2_start                   : std_logic;
  signal AS_L4PHICn2_wea_delay          : t_AS_36_1b;
  signal AS_L4PHICn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHICn2_din_delay         : t_AS_36_DATA;
  signal AS_L4PHICn2_wea          : t_AS_36_1b;
  signal AS_L4PHICn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L4PHICn2_din         : t_AS_36_DATA;
  signal AS_L4PHICn2_enb          : t_AS_36_1b := '1';
  signal AS_L4PHICn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHICn2_V_dout        : t_AS_36_DATA;
  signal AS_L4PHICn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal AS_L4PHIDn2_start                   : std_logic;
  signal AS_L4PHIDn2_wea_delay          : t_AS_36_1b;
  signal AS_L4PHIDn2_writeaddr_delay   : t_AS_36_ADDR;
  signal AS_L4PHIDn2_din_delay         : t_AS_36_DATA;
  signal AS_L4PHIDn2_wea          : t_AS_36_1b;
  signal AS_L4PHIDn2_writeaddr   : t_AS_36_ADDR;
  signal AS_L4PHIDn2_din         : t_AS_36_DATA;
  signal AS_L4PHIDn2_enb          : t_AS_36_1b := '1';
  signal AS_L4PHIDn2_V_readaddr    : t_AS_36_ADDR;
  signal AS_L4PHIDn2_V_dout        : t_AS_36_DATA;
  signal AS_L4PHIDn2_AV_dout_nent  : t_AS_36_NENT; -- (#page)
  signal VMSME_L1PHIAn2_start                   : std_logic;
  signal VMSME_L1PHIAn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIAn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIAn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIAn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIAn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIAn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIAn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIAn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIAn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIAn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIAn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIAn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIAn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIAn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIAn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIAn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIAn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIAn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIBn2_start                   : std_logic;
  signal VMSME_L1PHIBn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIBn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIBn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIBn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIBn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIBn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIBn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIBn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIBn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIBn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIBn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIBn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIBn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIBn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIBn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIBn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIBn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIBn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHICn2_start                   : std_logic;
  signal VMSME_L1PHICn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHICn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHICn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHICn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHICn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHICn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHICn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHICn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHICn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHICn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHICn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHICn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHICn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHICn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHICn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHICn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHICn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHICn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIDn2_start                   : std_logic;
  signal VMSME_L1PHIDn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIDn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIDn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIDn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIDn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIDn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIDn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIDn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIDn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIDn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIDn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIDn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIDn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIDn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIDn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIDn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIDn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIDn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIEn2_start                   : std_logic;
  signal VMSME_L1PHIEn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIEn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIEn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIEn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIEn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIEn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIEn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIEn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIEn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIEn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIEn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIEn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIEn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIEn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIEn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIEn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIEn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIEn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIFn2_start                   : std_logic;
  signal VMSME_L1PHIFn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIFn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIFn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIFn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIFn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIFn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIFn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIFn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIFn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIFn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIFn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIFn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIFn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIFn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIFn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIFn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIFn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIFn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIGn2_start                   : std_logic;
  signal VMSME_L1PHIGn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIGn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIGn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIGn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIGn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIGn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIGn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIGn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIGn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIGn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIGn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIGn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIGn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIGn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIGn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIGn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIGn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIGn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L1PHIHn2_start                   : std_logic;
  signal VMSME_L1PHIHn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L1PHIHn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L1PHIHn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L1PHIHn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L1PHIHn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L1PHIHn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L1PHIHn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L1PHIHn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L1PHIHn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L1PHIHn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L1PHIHn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L1PHIHn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L1PHIHn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIHn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIHn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L1PHIHn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L1PHIHn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L1PHIHn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L2PHIAn2_start                   : std_logic;
  signal VMSME_L2PHIAn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L2PHIAn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L2PHIAn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L2PHIAn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L2PHIAn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L2PHIAn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L2PHIAn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L2PHIAn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L2PHIAn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L2PHIAn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L2PHIAn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L2PHIAn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L2PHIAn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIAn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIAn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L2PHIAn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIAn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIAn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L2PHIBn2_start                   : std_logic;
  signal VMSME_L2PHIBn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L2PHIBn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L2PHIBn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L2PHIBn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L2PHIBn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L2PHIBn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L2PHIBn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L2PHIBn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L2PHIBn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L2PHIBn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L2PHIBn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L2PHIBn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L2PHIBn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIBn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIBn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L2PHIBn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIBn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIBn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L2PHICn2_start                   : std_logic;
  signal VMSME_L2PHICn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L2PHICn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L2PHICn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L2PHICn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L2PHICn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L2PHICn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L2PHICn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L2PHICn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L2PHICn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L2PHICn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L2PHICn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L2PHICn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L2PHICn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHICn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHICn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L2PHICn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHICn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHICn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L2PHIDn2_start                   : std_logic;
  signal VMSME_L2PHIDn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L2PHIDn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L2PHIDn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L2PHIDn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L2PHIDn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L2PHIDn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L2PHIDn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L2PHIDn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L2PHIDn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L2PHIDn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L2PHIDn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L2PHIDn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L2PHIDn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIDn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIDn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L2PHIDn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L2PHIDn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L2PHIDn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L3PHIAn2_start                   : std_logic;
  signal VMSME_L3PHIAn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L3PHIAn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L3PHIAn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L3PHIAn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L3PHIAn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L3PHIAn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L3PHIAn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L3PHIAn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L3PHIAn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L3PHIAn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L3PHIAn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L3PHIAn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L3PHIAn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIAn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIAn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L3PHIAn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIAn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIAn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L3PHIBn2_start                   : std_logic;
  signal VMSME_L3PHIBn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L3PHIBn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L3PHIBn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L3PHIBn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L3PHIBn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L3PHIBn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L3PHIBn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L3PHIBn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L3PHIBn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L3PHIBn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L3PHIBn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L3PHIBn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L3PHIBn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIBn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIBn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L3PHIBn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIBn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIBn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L3PHICn2_start                   : std_logic;
  signal VMSME_L3PHICn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L3PHICn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L3PHICn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L3PHICn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L3PHICn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L3PHICn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L3PHICn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L3PHICn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L3PHICn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L3PHICn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L3PHICn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L3PHICn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L3PHICn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHICn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHICn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L3PHICn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHICn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHICn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L3PHIDn2_start                   : std_logic;
  signal VMSME_L3PHIDn2_wea_delay          : t_VMSME_16_1b;
  signal VMSME_L3PHIDn2_writeaddr_delay   : t_VMSME_16_ADDR;
  signal VMSME_L3PHIDn2_din_delay         : t_VMSME_16_DATA;
  signal VMSME_L3PHIDn2_A_enb         : t_VMSME_16_A1b;
  signal VMSME_L3PHIDn2_AV_readaddr   : t_VMSME_16_AADDR;
  signal VMSME_L3PHIDn2_AV_dout       : t_VMSME_16_ADATA;
  signal VMSME_L3PHIDn2_AV_dout_mask : t_VMSME_16_MASK; -- (#page)(#bin)
  signal VMSME_L3PHIDn2_enb_nent         : t_VMSME_16_1b;
  signal VMSME_L3PHIDn2_V_addr_nent   : t_VMSME_16_NENTADDR;
  signal VMSME_L3PHIDn2_AV_dout_nent : t_VMSME_16_NENT; -- (#page)(#bin)
  signal VMSME_L3PHIDn2_V_datatmp : t_VMSME_16_DATA_4;
  signal VMSME_L3PHIDn2_V_masktmp : t_VMSME_16_MASK_2;
  signal VMSME_L3PHIDn2_V_addr_binmaskA   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIDn2_V_binmaskA   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIDn2_enb_binmaskA   : t_VMSME_16_1b;
  signal VMSME_L3PHIDn2_V_addr_binmaskB   : t_VMSME_16_ADDRBINMASK;
  signal VMSME_L3PHIDn2_V_binmaskB   : t_VMSME_16_BINMASK;
  signal VMSME_L3PHIDn2_enb_binmaskB   : t_VMSME_16_1b;
  signal VMSME_L4PHIAn2_start                   : std_logic;
  signal VMSME_L4PHIAn2_wea_delay          : t_VMSME_17_1b;
  signal VMSME_L4PHIAn2_writeaddr_delay   : t_VMSME_17_ADDR;
  signal VMSME_L4PHIAn2_din_delay         : t_VMSME_17_DATA;
  signal VMSME_L4PHIAn2_A_enb         : t_VMSME_17_A1b;
  signal VMSME_L4PHIAn2_AV_readaddr   : t_VMSME_17_AADDR;
  signal VMSME_L4PHIAn2_AV_dout       : t_VMSME_17_ADATA;
  signal VMSME_L4PHIAn2_AV_dout_mask : t_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_L4PHIAn2_enb_nent         : t_VMSME_17_1b;
  signal VMSME_L4PHIAn2_V_addr_nent   : t_VMSME_17_NENTADDR;
  signal VMSME_L4PHIAn2_AV_dout_nent : t_VMSME_17_NENT; -- (#page)(#bin)
  signal VMSME_L4PHIAn2_V_datatmp : t_VMSME_17_DATA_4;
  signal VMSME_L4PHIAn2_V_masktmp : t_VMSME_17_MASK_2;
  signal VMSME_L4PHIAn2_V_addr_binmaskA   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIAn2_V_binmaskA   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIAn2_enb_binmaskA   : t_VMSME_17_1b;
  signal VMSME_L4PHIAn2_V_addr_binmaskB   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIAn2_V_binmaskB   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIAn2_enb_binmaskB   : t_VMSME_17_1b;
  signal VMSME_L4PHIBn2_start                   : std_logic;
  signal VMSME_L4PHIBn2_wea_delay          : t_VMSME_17_1b;
  signal VMSME_L4PHIBn2_writeaddr_delay   : t_VMSME_17_ADDR;
  signal VMSME_L4PHIBn2_din_delay         : t_VMSME_17_DATA;
  signal VMSME_L4PHIBn2_A_enb         : t_VMSME_17_A1b;
  signal VMSME_L4PHIBn2_AV_readaddr   : t_VMSME_17_AADDR;
  signal VMSME_L4PHIBn2_AV_dout       : t_VMSME_17_ADATA;
  signal VMSME_L4PHIBn2_AV_dout_mask : t_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_L4PHIBn2_enb_nent         : t_VMSME_17_1b;
  signal VMSME_L4PHIBn2_V_addr_nent   : t_VMSME_17_NENTADDR;
  signal VMSME_L4PHIBn2_AV_dout_nent : t_VMSME_17_NENT; -- (#page)(#bin)
  signal VMSME_L4PHIBn2_V_datatmp : t_VMSME_17_DATA_4;
  signal VMSME_L4PHIBn2_V_masktmp : t_VMSME_17_MASK_2;
  signal VMSME_L4PHIBn2_V_addr_binmaskA   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIBn2_V_binmaskA   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIBn2_enb_binmaskA   : t_VMSME_17_1b;
  signal VMSME_L4PHIBn2_V_addr_binmaskB   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIBn2_V_binmaskB   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIBn2_enb_binmaskB   : t_VMSME_17_1b;
  signal VMSME_L4PHICn2_start                   : std_logic;
  signal VMSME_L4PHICn2_wea_delay          : t_VMSME_17_1b;
  signal VMSME_L4PHICn2_writeaddr_delay   : t_VMSME_17_ADDR;
  signal VMSME_L4PHICn2_din_delay         : t_VMSME_17_DATA;
  signal VMSME_L4PHICn2_A_enb         : t_VMSME_17_A1b;
  signal VMSME_L4PHICn2_AV_readaddr   : t_VMSME_17_AADDR;
  signal VMSME_L4PHICn2_AV_dout       : t_VMSME_17_ADATA;
  signal VMSME_L4PHICn2_AV_dout_mask : t_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_L4PHICn2_enb_nent         : t_VMSME_17_1b;
  signal VMSME_L4PHICn2_V_addr_nent   : t_VMSME_17_NENTADDR;
  signal VMSME_L4PHICn2_AV_dout_nent : t_VMSME_17_NENT; -- (#page)(#bin)
  signal VMSME_L4PHICn2_V_datatmp : t_VMSME_17_DATA_4;
  signal VMSME_L4PHICn2_V_masktmp : t_VMSME_17_MASK_2;
  signal VMSME_L4PHICn2_V_addr_binmaskA   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHICn2_V_binmaskA   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHICn2_enb_binmaskA   : t_VMSME_17_1b;
  signal VMSME_L4PHICn2_V_addr_binmaskB   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHICn2_V_binmaskB   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHICn2_enb_binmaskB   : t_VMSME_17_1b;
  signal VMSME_L4PHIDn2_start                   : std_logic;
  signal VMSME_L4PHIDn2_wea_delay          : t_VMSME_17_1b;
  signal VMSME_L4PHIDn2_writeaddr_delay   : t_VMSME_17_ADDR;
  signal VMSME_L4PHIDn2_din_delay         : t_VMSME_17_DATA;
  signal VMSME_L4PHIDn2_A_enb         : t_VMSME_17_A1b;
  signal VMSME_L4PHIDn2_AV_readaddr   : t_VMSME_17_AADDR;
  signal VMSME_L4PHIDn2_AV_dout       : t_VMSME_17_ADATA;
  signal VMSME_L4PHIDn2_AV_dout_mask : t_VMSME_17_MASK; -- (#page)(#bin)
  signal VMSME_L4PHIDn2_enb_nent         : t_VMSME_17_1b;
  signal VMSME_L4PHIDn2_V_addr_nent   : t_VMSME_17_NENTADDR;
  signal VMSME_L4PHIDn2_AV_dout_nent : t_VMSME_17_NENT; -- (#page)(#bin)
  signal VMSME_L4PHIDn2_V_datatmp : t_VMSME_17_DATA_4;
  signal VMSME_L4PHIDn2_V_masktmp : t_VMSME_17_MASK_2;
  signal VMSME_L4PHIDn2_V_addr_binmaskA   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIDn2_V_binmaskA   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIDn2_enb_binmaskA   : t_VMSME_17_1b;
  signal VMSME_L4PHIDn2_V_addr_binmaskB   : t_VMSME_17_ADDRBINMASK;
  signal VMSME_L4PHIDn2_V_binmaskB   : t_VMSME_17_BINMASK;
  signal VMSME_L4PHIDn2_enb_binmaskB   : t_VMSME_17_1b;
  signal MPAR_L5L6ABCDin_start                   : std_logic;
  signal MPAR_L5L6ABCDin_wea_delay          : t_MPAR_73_1b;
  signal MPAR_L5L6ABCDin_writeaddr_delay   : t_MPAR_73_ADDR;
  signal MPAR_L5L6ABCDin_din_delay         : t_MPAR_73_DATA;
  signal MPAR_L5L6ABCDin_enb          : t_MPAR_73_1b := '1';
  signal MPAR_L5L6ABCDin_V_readaddr    : t_MPAR_73_ADDR;
  signal MPAR_L5L6ABCDin_V_dout        : t_MPAR_73_DATA;
  signal MPAR_L5L6ABCDin_V_tpar        : t_MPAR_73_DATA;
  signal MPAR_L5L6ABCDin_valid        : STD_LOGIC;
  signal MPAR_L5L6ABCDin_trackletindex        : STD_LOGIC_VECTOR(8 downto 0);
  signal MPAR_L5L6ABCDin_AV_dout_nent        : t_arr_7b(0 to 31);
  signal MPAR_L5L6ABCDin_AV_dout_mask        : t_arr_4b(0 to 7);
  signal MPAR_L5L6ABCD_start                   : std_logic;
  signal MPAR_L5L6ABCD_wea_delay          : t_MPAR_73_1b;
  signal MPAR_L5L6ABCD_writeaddr_delay   : t_MPAR_73_ADDR;
  signal MPAR_L5L6ABCD_din_delay         : t_MPAR_73_DATA;
  signal MPAR_L5L6ABCD_wea          : t_MPAR_73_1b;
  signal MPAR_L5L6ABCD_writeaddr   : t_MPAR_73_ADDR;
  signal MPAR_L5L6ABCD_din         : t_MPAR_73_DATA;
  signal MPAR_L5L6ABCD_enb          : t_MPAR_73_1b := '1';
  signal MPAR_L5L6ABCD_V_readaddr    : t_MPAR_73_ADDR;
  signal MPAR_L5L6ABCD_V_dout        : t_MPAR_73_DATA;
  signal MPROJ_L5L6ABCD_L1PHIA_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIA_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIA_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIA_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIA_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIA_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIA_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIA_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIB_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIB_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIB_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIB_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIB_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIB_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIB_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIB_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIC_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIC_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIC_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIC_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIC_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIC_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIC_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIC_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHID_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHID_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHID_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHID_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHID_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHID_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHID_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHID_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHID_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIE_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIE_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIE_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIE_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIE_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIE_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIE_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIE_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIF_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIF_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIF_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIF_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIF_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIF_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIF_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIF_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIG_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIG_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIG_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIG_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIG_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIG_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIG_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIG_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L1PHIH_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L1PHIH_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L1PHIH_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIH_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIH_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L1PHIH_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L1PHIH_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L1PHIH_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L2PHIA_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L2PHIA_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L2PHIA_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIA_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIA_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L2PHIA_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIA_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L2PHIA_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L2PHIB_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L2PHIB_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L2PHIB_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIB_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIB_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L2PHIB_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIB_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L2PHIB_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L2PHIC_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L2PHIC_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L2PHIC_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIC_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIC_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L2PHIC_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHIC_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L2PHIC_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L2PHID_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L2PHID_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L2PHID_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHID_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHID_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L2PHID_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L2PHID_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L2PHID_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L2PHID_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L3PHIA_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L3PHIA_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L3PHIA_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIA_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIA_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L3PHIA_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIA_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L3PHIA_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L3PHIB_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L3PHIB_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L3PHIB_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIB_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIB_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L3PHIB_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIB_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L3PHIB_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L3PHIC_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L3PHIC_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L3PHIC_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIC_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIC_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L3PHIC_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHIC_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L3PHIC_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L3PHID_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L3PHID_wea_delay          : t_MPROJ_60_1b;
  signal MPROJ_L5L6ABCD_L3PHID_writeaddr_delay   : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHID_din_delay         : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHID_enb          : t_MPROJ_60_1b := '1';
  signal MPROJ_L5L6ABCD_L3PHID_V_readaddr    : t_MPROJ_60_ADDR;
  signal MPROJ_L5L6ABCD_L3PHID_V_dout        : t_MPROJ_60_DATA;
  signal MPROJ_L5L6ABCD_L3PHID_AV_dout_nent  : t_MPROJ_60_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L3PHID_AV_dout_mask  : t_MPROJ_60_MASK;
  signal MPROJ_L5L6ABCD_L4PHIA_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L4PHIA_wea_delay          : t_MPROJ_58_1b;
  signal MPROJ_L5L6ABCD_L4PHIA_writeaddr_delay   : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIA_din_delay         : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIA_enb          : t_MPROJ_58_1b := '1';
  signal MPROJ_L5L6ABCD_L4PHIA_V_readaddr    : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIA_V_dout        : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent  : t_MPROJ_58_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L4PHIA_AV_dout_mask  : t_MPROJ_58_MASK;
  signal MPROJ_L5L6ABCD_L4PHIB_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L4PHIB_wea_delay          : t_MPROJ_58_1b;
  signal MPROJ_L5L6ABCD_L4PHIB_writeaddr_delay   : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIB_din_delay         : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIB_enb          : t_MPROJ_58_1b := '1';
  signal MPROJ_L5L6ABCD_L4PHIB_V_readaddr    : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIB_V_dout        : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent  : t_MPROJ_58_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L4PHIB_AV_dout_mask  : t_MPROJ_58_MASK;
  signal MPROJ_L5L6ABCD_L4PHIC_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L4PHIC_wea_delay          : t_MPROJ_58_1b;
  signal MPROJ_L5L6ABCD_L4PHIC_writeaddr_delay   : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIC_din_delay         : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIC_enb          : t_MPROJ_58_1b := '1';
  signal MPROJ_L5L6ABCD_L4PHIC_V_readaddr    : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHIC_V_dout        : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent  : t_MPROJ_58_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L4PHIC_AV_dout_mask  : t_MPROJ_58_MASK;
  signal MPROJ_L5L6ABCD_L4PHID_start                   : std_logic;
  signal MPROJ_L5L6ABCD_L4PHID_wea_delay          : t_MPROJ_58_1b;
  signal MPROJ_L5L6ABCD_L4PHID_writeaddr_delay   : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHID_din_delay         : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHID_enb          : t_MPROJ_58_1b := '1';
  signal MPROJ_L5L6ABCD_L4PHID_V_readaddr    : t_MPROJ_58_ADDR;
  signal MPROJ_L5L6ABCD_L4PHID_V_dout        : t_MPROJ_58_DATA;
  signal MPROJ_L5L6ABCD_L4PHID_AV_dout_nent  : t_MPROJ_58_NENT; -- (#page)
  signal MPROJ_L5L6ABCD_L4PHID_AV_dout_mask  : t_MPROJ_58_MASK;
  signal FM_AAAA_L1PHIA_start                   : std_logic;
  signal FM_AAAA_L1PHIA_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIA_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIA_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIA_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIA_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIA_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIA_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIB_start                   : std_logic;
  signal FM_AAAA_L1PHIB_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIB_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIB_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIB_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIB_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIB_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIB_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIC_start                   : std_logic;
  signal FM_AAAA_L1PHIC_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIC_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIC_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIC_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIC_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIC_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIC_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHID_start                   : std_logic;
  signal FM_AAAA_L1PHID_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHID_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHID_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHID_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHID_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHID_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHID_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIE_start                   : std_logic;
  signal FM_AAAA_L1PHIE_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIE_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIE_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIE_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIE_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIE_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIE_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIF_start                   : std_logic;
  signal FM_AAAA_L1PHIF_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIF_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIF_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIF_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIF_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIF_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIF_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIG_start                   : std_logic;
  signal FM_AAAA_L1PHIG_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIG_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIG_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIG_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIG_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIG_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIG_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L1PHIH_start                   : std_logic;
  signal FM_AAAA_L1PHIH_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L1PHIH_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIH_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L1PHIH_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L1PHIH_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L1PHIH_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L1PHIH_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L2PHIA_start                   : std_logic;
  signal FM_AAAA_L2PHIA_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L2PHIA_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIA_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L2PHIA_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L2PHIA_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIA_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L2PHIA_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L2PHIB_start                   : std_logic;
  signal FM_AAAA_L2PHIB_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L2PHIB_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIB_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L2PHIB_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L2PHIB_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIB_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L2PHIB_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L2PHIC_start                   : std_logic;
  signal FM_AAAA_L2PHIC_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L2PHIC_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIC_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L2PHIC_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L2PHIC_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L2PHIC_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L2PHIC_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L2PHID_start                   : std_logic;
  signal FM_AAAA_L2PHID_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L2PHID_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L2PHID_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L2PHID_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L2PHID_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L2PHID_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L2PHID_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L3PHIA_start                   : std_logic;
  signal FM_AAAA_L3PHIA_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L3PHIA_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIA_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L3PHIA_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L3PHIA_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIA_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L3PHIA_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L3PHIB_start                   : std_logic;
  signal FM_AAAA_L3PHIB_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L3PHIB_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIB_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L3PHIB_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L3PHIB_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIB_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L3PHIB_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L3PHIC_start                   : std_logic;
  signal FM_AAAA_L3PHIC_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L3PHIC_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIC_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L3PHIC_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L3PHIC_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L3PHIC_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L3PHIC_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L3PHID_start                   : std_logic;
  signal FM_AAAA_L3PHID_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L3PHID_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L3PHID_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L3PHID_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L3PHID_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L3PHID_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L3PHID_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L4PHIA_start                   : std_logic;
  signal FM_AAAA_L4PHIA_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L4PHIA_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIA_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L4PHIA_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L4PHIA_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIA_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L4PHIA_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L4PHIB_start                   : std_logic;
  signal FM_AAAA_L4PHIB_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L4PHIB_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIB_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L4PHIB_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L4PHIB_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIB_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L4PHIB_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L4PHIC_start                   : std_logic;
  signal FM_AAAA_L4PHIC_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L4PHIC_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIC_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L4PHIC_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L4PHIC_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L4PHIC_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L4PHIC_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal FM_AAAA_L4PHID_start                   : std_logic;
  signal FM_AAAA_L4PHID_wea_delay          : t_FM_52_1b;
  signal FM_AAAA_L4PHID_writeaddr_delay   : t_FM_52_ADDR;
  signal FM_AAAA_L4PHID_din_delay         : t_FM_52_DATA;
  signal FM_AAAA_L4PHID_enb          : t_FM_52_1b := '1';
  signal FM_AAAA_L4PHID_V_readaddr    : t_FM_52_ADDR;
  signal FM_AAAA_L4PHID_V_dout        : t_FM_52_DATA;
  signal FM_AAAA_L4PHID_AV_dout_nent  : t_FM_52_NENT; -- (#page)
  signal VMSMER_L1PHIA_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIA_start : std_logic := '0';
  -- ###### Legacy signal
  -- signal VMSMER_L1PHIA_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIB_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIB_start : std_logic := '0';
  signal VMSMER_L1PHIB_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIC_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIC_start : std_logic := '0';
  signal VMSMER_L1PHIC_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHID_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHID_start : std_logic := '0';
  signal VMSMER_L1PHID_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIE_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIE_start : std_logic := '0';
  signal VMSMER_L1PHIE_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIF_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIF_start : std_logic := '0';
  signal VMSMER_L1PHIF_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIG_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIG_start : std_logic := '0';
  signal VMSMER_L1PHIG_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIH_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L1PHIH_start : std_logic := '0';
  signal VMSMER_L1PHIH_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIA_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIA_start : std_logic := '0';
  signal VMSMER_L2PHIA_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIB_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIB_start : std_logic := '0';
  signal VMSMER_L2PHIB_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIC_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHIC_start : std_logic := '0';
  signal VMSMER_L2PHIC_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHID_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L2PHID_start : std_logic := '0';
  signal VMSMER_L2PHID_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIA_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIA_start : std_logic := '0';
  signal VMSMER_L3PHIA_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIB_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIB_start : std_logic := '0';
  signal VMSMER_L3PHIB_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIC_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHIC_start : std_logic := '0';
  signal VMSMER_L3PHIC_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHID_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L3PHID_start : std_logic := '0';
  signal VMSMER_L3PHID_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIA_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIA_start : std_logic := '0';
  signal VMSMER_L4PHIA_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIB_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIB_start : std_logic := '0';
  signal VMSMER_L4PHIB_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIC_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHIC_start : std_logic := '0';
  signal VMSMER_L4PHIC_bx_in : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHID_bx : std_logic_vector(2 downto 0);
  signal VMSMER_L4PHID_start : std_logic := '0';
  signal VMSMER_L4PHID_bx_in : std_logic_vector(2 downto 0);
  signal PC_L5L6ABCD_bx : std_logic_vector(2 downto 0);
  signal PC_L5L6ABCD_start : std_logic := '0';
  signal PC_L5L6ABCD_bx_in : std_logic_vector(2 downto 0);
  signal MP_L1PHIA_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIA_start : std_logic := '0';
  signal MP_L1PHIB_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIB_start : std_logic := '0';
  signal MP_L1PHIC_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIC_start : std_logic := '0';
  signal MP_L1PHID_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHID_start : std_logic := '0';
  signal MP_L1PHIE_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIE_start : std_logic := '0';
  signal MP_L1PHIF_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIF_start : std_logic := '0';
  signal MP_L1PHIG_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIG_start : std_logic := '0';
  signal MP_L1PHIH_bx : std_logic_vector(2 downto 0);
  signal MP_L1PHIH_start : std_logic := '0';
  signal MP_L2PHIA_bx : std_logic_vector(2 downto 0);
  signal MP_L2PHIA_start : std_logic := '0';
  signal MP_L2PHIB_bx : std_logic_vector(2 downto 0);
  signal MP_L2PHIB_start : std_logic := '0';
  signal MP_L2PHIC_bx : std_logic_vector(2 downto 0);
  signal MP_L2PHIC_start : std_logic := '0';
  signal MP_L2PHID_bx : std_logic_vector(2 downto 0);
  signal MP_L2PHID_start : std_logic := '0';
  signal MP_L3PHIA_bx : std_logic_vector(2 downto 0);
  signal MP_L3PHIA_start : std_logic := '0';
  signal MP_L3PHIB_bx : std_logic_vector(2 downto 0);
  signal MP_L3PHIB_start : std_logic := '0';
  signal MP_L3PHIC_bx : std_logic_vector(2 downto 0);
  signal MP_L3PHIC_start : std_logic := '0';
  signal MP_L3PHID_bx : std_logic_vector(2 downto 0);
  signal MP_L3PHID_start : std_logic := '0';
  signal MP_L4PHIA_bx : std_logic_vector(2 downto 0);
  signal MP_L4PHIA_start : std_logic := '0';
  signal MP_L4PHIB_bx : std_logic_vector(2 downto 0);
  signal MP_L4PHIB_start : std_logic := '0';
  signal MP_L4PHIC_bx : std_logic_vector(2 downto 0);
  signal MP_L4PHIC_start : std_logic := '0';
  signal MP_L4PHID_bx : std_logic_vector(2 downto 0);
  signal MP_L4PHID_start : std_logic := '0';
  signal TB_AAAA_bx : std_logic_vector(2 downto 0);
  signal TB_AAAA_start : std_logic := '0';

begin

-- ####### Legacy connection : port -> delay -> tf_mem 
    -- AS_L1PHIAin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIAin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIAin_wea_delay,
    --     addra     => AS_L1PHIAin_writeaddr_delay,
    --     dina      => AS_L1PHIAin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIAin_V_readaddr,
    --     doutb     => AS_L1PHIAin_V_dout,
    --     sync_nent => AS_L1PHIAin_start,
    --     nent_o    => AS_L1PHIAin_AV_dout_nent
    --   );

    -- AS_L1PHIAin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIAin_wea,
    --     addra     => AS_L1PHIAin_writeaddr,
    --     dina      => AS_L1PHIAin_din,
    --     wea_out       => AS_L1PHIAin_wea_delay,
    --     addra_out     => AS_L1PHIAin_writeaddr_delay,
    --     dina_out      => AS_L1PHIAin_din_delay,  -- data
    --     done       => PC_start,
    --     start      => AS_L1PHIAin_start
    --   );

-- ###### New connection: port -> delay
    -- AS_L1PHIAin_DELAY_FIFO : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     RAM_WIDTH     => 36   -- not sure here, also other generics
    --   )
    --   port map (
    --     clk        => clk240,
    --     reset      => reset,
    --     wea        => AS_L1PHIAin_DELAY_wea_FIFO,  -- establish new signal std_logic := '1' earlier, no wea since no ram
    --     addra      => (others => '0'),   -- there is no addr 
    --     dina       => AS_L1PHIAin_data_FIFO,
    --     wea_out    => AS_L1PHIAin_DELAY_wea_FIFO_delay,  -- my new data
    --     addra_out  => open,
    --     done       => PC_start,  -- copied from Legacy
    --     start      => readAS_L1PHIAin_start_FIFO  -- no tf_mem to provide AS_L1PHIAin_start, use the start from FileReaderFIFO
    --   );

-- ####### Legacy connection : port -> delay -> tf_mem 
    -- AS_L1PHIBin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIBin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIBin_wea_delay,
    --     addra     => AS_L1PHIBin_writeaddr_delay,
    --     dina      => AS_L1PHIBin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIBin_V_readaddr,
    --     doutb     => AS_L1PHIBin_V_dout,
    --     sync_nent => AS_L1PHIBin_start,
    --     nent_o    => AS_L1PHIBin_AV_dout_nent
    --   );

    -- AS_L1PHIBin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIBin_wea,
    --     addra     => AS_L1PHIBin_writeaddr,
    --     dina      => AS_L1PHIBin_din,
    --     wea_out       => AS_L1PHIBin_wea_delay,
    --     addra_out     => AS_L1PHIBin_writeaddr_delay,
    --     dina_out      => AS_L1PHIBin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIBin_start
    --   );

    -- AS_L1PHICin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHICin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHICin_wea_delay,
    --     addra     => AS_L1PHICin_writeaddr_delay,
    --     dina      => AS_L1PHICin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHICin_V_readaddr,
    --     doutb     => AS_L1PHICin_V_dout,
    --     sync_nent => AS_L1PHICin_start,
    --     nent_o    => AS_L1PHICin_AV_dout_nent
    --   );

    -- AS_L1PHICin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHICin_wea,
    --     addra     => AS_L1PHICin_writeaddr,
    --     dina      => AS_L1PHICin_din,
    --     wea_out       => AS_L1PHICin_wea_delay,
    --     addra_out     => AS_L1PHICin_writeaddr_delay,
    --     dina_out      => AS_L1PHICin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHICin_start
    --   );

    -- AS_L1PHIDin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIDin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIDin_wea_delay,
    --     addra     => AS_L1PHIDin_writeaddr_delay,
    --     dina      => AS_L1PHIDin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIDin_V_readaddr,
    --     doutb     => AS_L1PHIDin_V_dout,
    --     sync_nent => AS_L1PHIDin_start,
    --     nent_o    => AS_L1PHIDin_AV_dout_nent
    --   );

    -- AS_L1PHIDin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIDin_wea,
    --     addra     => AS_L1PHIDin_writeaddr,
    --     dina      => AS_L1PHIDin_din,
    --     wea_out       => AS_L1PHIDin_wea_delay,
    --     addra_out     => AS_L1PHIDin_writeaddr_delay,
    --     dina_out      => AS_L1PHIDin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIDin_start
    --   );

    -- AS_L1PHIEin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIEin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIEin_wea_delay,
    --     addra     => AS_L1PHIEin_writeaddr_delay,
    --     dina      => AS_L1PHIEin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIEin_V_readaddr,
    --     doutb     => AS_L1PHIEin_V_dout,
    --     sync_nent => AS_L1PHIEin_start,
    --     nent_o    => AS_L1PHIEin_AV_dout_nent
    --   );

    -- AS_L1PHIEin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIEin_wea,
    --     addra     => AS_L1PHIEin_writeaddr,
    --     dina      => AS_L1PHIEin_din,
    --     wea_out       => AS_L1PHIEin_wea_delay,
    --     addra_out     => AS_L1PHIEin_writeaddr_delay,
    --     dina_out      => AS_L1PHIEin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIEin_start
    --   );

    -- AS_L1PHIFin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIFin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIFin_wea_delay,
    --     addra     => AS_L1PHIFin_writeaddr_delay,
    --     dina      => AS_L1PHIFin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIFin_V_readaddr,
    --     doutb     => AS_L1PHIFin_V_dout,
    --     sync_nent => AS_L1PHIFin_start,
    --     nent_o    => AS_L1PHIFin_AV_dout_nent
    --   );

    -- AS_L1PHIFin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIFin_wea,
    --     addra     => AS_L1PHIFin_writeaddr,
    --     dina      => AS_L1PHIFin_din,
    --     wea_out       => AS_L1PHIFin_wea_delay,
    --     addra_out     => AS_L1PHIFin_writeaddr_delay,
    --     dina_out      => AS_L1PHIFin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIFin_start
    --   );

    -- AS_L1PHIGin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIGin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIGin_wea_delay,
    --     addra     => AS_L1PHIGin_writeaddr_delay,
    --     dina      => AS_L1PHIGin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIGin_V_readaddr,
    --     doutb     => AS_L1PHIGin_V_dout,
    --     sync_nent => AS_L1PHIGin_start,
    --     nent_o    => AS_L1PHIGin_AV_dout_nent
    --   );

    -- AS_L1PHIGin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIGin_wea,
    --     addra     => AS_L1PHIGin_writeaddr,
    --     dina      => AS_L1PHIGin_din,
    --     wea_out       => AS_L1PHIGin_wea_delay,
    --     addra_out     => AS_L1PHIGin_writeaddr_delay,
    --     dina_out      => AS_L1PHIGin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIGin_start
    --   );

    -- AS_L1PHIHin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L1PHIHin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L1PHIHin_wea_delay,
    --     addra     => AS_L1PHIHin_writeaddr_delay,
    --     dina      => AS_L1PHIHin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L1PHIHin_V_readaddr,
    --     doutb     => AS_L1PHIHin_V_dout,
    --     sync_nent => AS_L1PHIHin_start,
    --     nent_o    => AS_L1PHIHin_AV_dout_nent
    --   );

    -- AS_L1PHIHin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L1PHIHin_wea,
    --     addra     => AS_L1PHIHin_writeaddr,
    --     dina      => AS_L1PHIHin_din,
    --     wea_out       => AS_L1PHIHin_wea_delay,
    --     addra_out     => AS_L1PHIHin_writeaddr_delay,
    --     dina_out      => AS_L1PHIHin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L1PHIHin_start
    --   );

    -- AS_L2PHIAin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L2PHIAin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L2PHIAin_wea_delay,
    --     addra     => AS_L2PHIAin_writeaddr_delay,
    --     dina      => AS_L2PHIAin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L2PHIAin_V_readaddr,
    --     doutb     => AS_L2PHIAin_V_dout,
    --     sync_nent => AS_L2PHIAin_start,
    --     nent_o    => AS_L2PHIAin_AV_dout_nent
    --   );

    -- AS_L2PHIAin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L2PHIAin_wea,
    --     addra     => AS_L2PHIAin_writeaddr,
    --     dina      => AS_L2PHIAin_din,
    --     wea_out       => AS_L2PHIAin_wea_delay,
    --     addra_out     => AS_L2PHIAin_writeaddr_delay,
    --     dina_out      => AS_L2PHIAin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L2PHIAin_start
    --   );

    -- AS_L2PHIBin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L2PHIBin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L2PHIBin_wea_delay,
    --     addra     => AS_L2PHIBin_writeaddr_delay,
    --     dina      => AS_L2PHIBin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L2PHIBin_V_readaddr,
    --     doutb     => AS_L2PHIBin_V_dout,
    --     sync_nent => AS_L2PHIBin_start,
    --     nent_o    => AS_L2PHIBin_AV_dout_nent
    --   );

    -- AS_L2PHIBin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L2PHIBin_wea,
    --     addra     => AS_L2PHIBin_writeaddr,
    --     dina      => AS_L2PHIBin_din,
    --     wea_out       => AS_L2PHIBin_wea_delay,
    --     addra_out     => AS_L2PHIBin_writeaddr_delay,
    --     dina_out      => AS_L2PHIBin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L2PHIBin_start
    --   );

    -- AS_L2PHICin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L2PHICin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L2PHICin_wea_delay,
    --     addra     => AS_L2PHICin_writeaddr_delay,
    --     dina      => AS_L2PHICin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L2PHICin_V_readaddr,
    --     doutb     => AS_L2PHICin_V_dout,
    --     sync_nent => AS_L2PHICin_start,
    --     nent_o    => AS_L2PHICin_AV_dout_nent
    --   );

    -- AS_L2PHICin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L2PHICin_wea,
    --     addra     => AS_L2PHICin_writeaddr,
    --     dina      => AS_L2PHICin_din,
    --     wea_out       => AS_L2PHICin_wea_delay,
    --     addra_out     => AS_L2PHICin_writeaddr_delay,
    --     dina_out      => AS_L2PHICin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L2PHICin_start
    --   );

    -- AS_L2PHIDin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L2PHIDin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L2PHIDin_wea_delay,
    --     addra     => AS_L2PHIDin_writeaddr_delay,
    --     dina      => AS_L2PHIDin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L2PHIDin_V_readaddr,
    --     doutb     => AS_L2PHIDin_V_dout,
    --     sync_nent => AS_L2PHIDin_start,
    --     nent_o    => AS_L2PHIDin_AV_dout_nent
    --   );

    -- AS_L2PHIDin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L2PHIDin_wea,
    --     addra     => AS_L2PHIDin_writeaddr,
    --     dina      => AS_L2PHIDin_din,
    --     wea_out       => AS_L2PHIDin_wea_delay,
    --     addra_out     => AS_L2PHIDin_writeaddr_delay,
    --     dina_out      => AS_L2PHIDin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L2PHIDin_start
    --   );

    -- AS_L3PHIAin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L3PHIAin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L3PHIAin_wea_delay,
    --     addra     => AS_L3PHIAin_writeaddr_delay,
    --     dina      => AS_L3PHIAin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L3PHIAin_V_readaddr,
    --     doutb     => AS_L3PHIAin_V_dout,
    --     sync_nent => AS_L3PHIAin_start,
    --     nent_o    => AS_L3PHIAin_AV_dout_nent
    --   );

    -- AS_L3PHIAin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L3PHIAin_wea,
    --     addra     => AS_L3PHIAin_writeaddr,
    --     dina      => AS_L3PHIAin_din,
    --     wea_out       => AS_L3PHIAin_wea_delay,
    --     addra_out     => AS_L3PHIAin_writeaddr_delay,
    --     dina_out      => AS_L3PHIAin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L3PHIAin_start
    --   );

    -- AS_L3PHIBin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L3PHIBin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L3PHIBin_wea_delay,
    --     addra     => AS_L3PHIBin_writeaddr_delay,
    --     dina      => AS_L3PHIBin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L3PHIBin_V_readaddr,
    --     doutb     => AS_L3PHIBin_V_dout,
    --     sync_nent => AS_L3PHIBin_start,
    --     nent_o    => AS_L3PHIBin_AV_dout_nent
    --   );

    -- AS_L3PHIBin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L3PHIBin_wea,
    --     addra     => AS_L3PHIBin_writeaddr,
    --     dina      => AS_L3PHIBin_din,
    --     wea_out       => AS_L3PHIBin_wea_delay,
    --     addra_out     => AS_L3PHIBin_writeaddr_delay,
    --     dina_out      => AS_L3PHIBin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L3PHIBin_start
    --   );

    -- AS_L3PHICin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L3PHICin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L3PHICin_wea_delay,
    --     addra     => AS_L3PHICin_writeaddr_delay,
    --     dina      => AS_L3PHICin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L3PHICin_V_readaddr,
    --     doutb     => AS_L3PHICin_V_dout,
    --     sync_nent => AS_L3PHICin_start,
    --     nent_o    => AS_L3PHICin_AV_dout_nent
    --   );

    -- AS_L3PHICin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L3PHICin_wea,
    --     addra     => AS_L3PHICin_writeaddr,
    --     dina      => AS_L3PHICin_din,
    --     wea_out       => AS_L3PHICin_wea_delay,
    --     addra_out     => AS_L3PHICin_writeaddr_delay,
    --     dina_out      => AS_L3PHICin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L3PHICin_start
    --   );

    -- AS_L3PHIDin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L3PHIDin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L3PHIDin_wea_delay,
    --     addra     => AS_L3PHIDin_writeaddr_delay,
    --     dina      => AS_L3PHIDin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L3PHIDin_V_readaddr,
    --     doutb     => AS_L3PHIDin_V_dout,
    --     sync_nent => AS_L3PHIDin_start,
    --     nent_o    => AS_L3PHIDin_AV_dout_nent
    --   );

    -- AS_L3PHIDin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L3PHIDin_wea,
    --     addra     => AS_L3PHIDin_writeaddr,
    --     dina      => AS_L3PHIDin_din,
    --     wea_out       => AS_L3PHIDin_wea_delay,
    --     addra_out     => AS_L3PHIDin_writeaddr_delay,
    --     dina_out      => AS_L3PHIDin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L3PHIDin_start
    --   );

    -- AS_L4PHIAin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L4PHIAin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L4PHIAin_wea_delay,
    --     addra     => AS_L4PHIAin_writeaddr_delay,
    --     dina      => AS_L4PHIAin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L4PHIAin_V_readaddr,
    --     doutb     => AS_L4PHIAin_V_dout,
    --     sync_nent => AS_L4PHIAin_start,
    --     nent_o    => AS_L4PHIAin_AV_dout_nent
    --   );

    -- AS_L4PHIAin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L4PHIAin_wea,
    --     addra     => AS_L4PHIAin_writeaddr,
    --     dina      => AS_L4PHIAin_din,
    --     wea_out       => AS_L4PHIAin_wea_delay,
    --     addra_out     => AS_L4PHIAin_writeaddr_delay,
    --     dina_out      => AS_L4PHIAin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L4PHIAin_start
    --   );

    -- AS_L4PHIBin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L4PHIBin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L4PHIBin_wea_delay,
    --     addra     => AS_L4PHIBin_writeaddr_delay,
    --     dina      => AS_L4PHIBin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L4PHIBin_V_readaddr,
    --     doutb     => AS_L4PHIBin_V_dout,
    --     sync_nent => AS_L4PHIBin_start,
    --     nent_o    => AS_L4PHIBin_AV_dout_nent
    --   );

    -- AS_L4PHIBin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L4PHIBin_wea,
    --     addra     => AS_L4PHIBin_writeaddr,
    --     dina      => AS_L4PHIBin_din,
    --     wea_out       => AS_L4PHIBin_wea_delay,
    --     addra_out     => AS_L4PHIBin_writeaddr_delay,
    --     dina_out      => AS_L4PHIBin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L4PHIBin_start
    --   );

    -- AS_L4PHICin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L4PHICin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L4PHICin_wea_delay,
    --     addra     => AS_L4PHICin_writeaddr_delay,
    --     dina      => AS_L4PHICin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L4PHICin_V_readaddr,
    --     doutb     => AS_L4PHICin_V_dout,
    --     sync_nent => AS_L4PHICin_start,
    --     nent_o    => AS_L4PHICin_AV_dout_nent
    --   );

    -- AS_L4PHICin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L4PHICin_wea,
    --     addra     => AS_L4PHICin_writeaddr,
    --     dina      => AS_L4PHICin_din,
    --     wea_out       => AS_L4PHICin_wea_delay,
    --     addra_out     => AS_L4PHICin_writeaddr_delay,
    --     dina_out      => AS_L4PHICin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L4PHICin_start
    --   );

    -- AS_L4PHIDin : entity work.tf_mem
    --   generic map (
    --     RAM_WIDTH       => 36,
    --     NUM_PAGES       => 8,
    --     INIT_FILE       => "",
    --     INIT_HEX        => true,
    --     RAM_PERFORMANCE => "HIGH_PERFORMANCE",
    --     NAME            => "AS_L4PHIDin",
    --     FILE_WRITE            => false
    --   )
    --   port map (
    --     clka      => clk240,
    --     wea       => AS_L4PHIDin_wea_delay,
    --     addra     => AS_L4PHIDin_writeaddr_delay,
    --     dina      => AS_L4PHIDin_din_delay,
    --     clkb      => clk240,
    --     rsta      => reset,
    --     rstb      => '0',
    --     enb       => '1',
    --     addrb     => AS_L4PHIDin_V_readaddr,
    --     doutb     => AS_L4PHIDin_V_dout,
    --     sync_nent => AS_L4PHIDin_start,
    --     nent_o    => AS_L4PHIDin_AV_dout_nent
    --   );

    -- AS_L4PHIDin_DELAY : entity work.tf_pipeline_slr_xing
    --   generic map (
    --     NUM_PAGES       => 8,
    --     RAM_WIDTH       => 36
    --   )
    --   port map (
    --     clk      => clk240,
    --     reset    => reset,
    --     wea       => AS_L4PHIDin_wea,
    --     addra     => AS_L4PHIDin_writeaddr,
    --     dina      => AS_L4PHIDin_din,
    --     wea_out       => AS_L4PHIDin_wea_delay,
    --     addra_out     => AS_L4PHIDin_writeaddr_delay,
    --     dina_out      => AS_L4PHIDin_din_delay,
    --     done       => PC_start,
    --     start      => AS_L4PHIDin_start
    --   );

    AS_L1PHIAn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIAn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIAn2_wea_delay,
        addra     => AS_L1PHIAn2_writeaddr_delay,
        dina      => AS_L1PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIAn2_V_readaddr,
        doutb     => AS_L1PHIAn2_V_dout,
        sync_nent => AS_L1PHIAn2_start,
        nent_o    => open
      );

    AS_L1PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIAn2_wea,
        addra     => AS_L1PHIAn2_writeaddr,
        dina      => AS_L1PHIAn2_din,
        wea_out       => AS_L1PHIAn2_wea_delay,
        addra_out     => AS_L1PHIAn2_writeaddr_delay,
        dina_out      => AS_L1PHIAn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIAn2_start
      );

    AS_L1PHIBn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIBn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIBn2_wea_delay,
        addra     => AS_L1PHIBn2_writeaddr_delay,
        dina      => AS_L1PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIBn2_V_readaddr,
        doutb     => AS_L1PHIBn2_V_dout,
        sync_nent => AS_L1PHIBn2_start,
        nent_o    => open
      );

    AS_L1PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIBn2_wea,
        addra     => AS_L1PHIBn2_writeaddr,
        dina      => AS_L1PHIBn2_din,
        wea_out       => AS_L1PHIBn2_wea_delay,
        addra_out     => AS_L1PHIBn2_writeaddr_delay,
        dina_out      => AS_L1PHIBn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIBn2_start
      );

    AS_L1PHICn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHICn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHICn2_wea_delay,
        addra     => AS_L1PHICn2_writeaddr_delay,
        dina      => AS_L1PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHICn2_V_readaddr,
        doutb     => AS_L1PHICn2_V_dout,
        sync_nent => AS_L1PHICn2_start,
        nent_o    => open
      );

    AS_L1PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHICn2_wea,
        addra     => AS_L1PHICn2_writeaddr,
        dina      => AS_L1PHICn2_din,
        wea_out       => AS_L1PHICn2_wea_delay,
        addra_out     => AS_L1PHICn2_writeaddr_delay,
        dina_out      => AS_L1PHICn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHICn2_start
      );

    AS_L1PHIDn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIDn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIDn2_wea_delay,
        addra     => AS_L1PHIDn2_writeaddr_delay,
        dina      => AS_L1PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIDn2_V_readaddr,
        doutb     => AS_L1PHIDn2_V_dout,
        sync_nent => AS_L1PHIDn2_start,
        nent_o    => open
      );

    AS_L1PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIDn2_wea,
        addra     => AS_L1PHIDn2_writeaddr,
        dina      => AS_L1PHIDn2_din,
        wea_out       => AS_L1PHIDn2_wea_delay,
        addra_out     => AS_L1PHIDn2_writeaddr_delay,
        dina_out      => AS_L1PHIDn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIDn2_start
      );

    AS_L1PHIEn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIEn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIEn2_wea_delay,
        addra     => AS_L1PHIEn2_writeaddr_delay,
        dina      => AS_L1PHIEn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIEn2_V_readaddr,
        doutb     => AS_L1PHIEn2_V_dout,
        sync_nent => AS_L1PHIEn2_start,
        nent_o    => open
      );

    AS_L1PHIEn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIEn2_wea,
        addra     => AS_L1PHIEn2_writeaddr,
        dina      => AS_L1PHIEn2_din,
        wea_out       => AS_L1PHIEn2_wea_delay,
        addra_out     => AS_L1PHIEn2_writeaddr_delay,
        dina_out      => AS_L1PHIEn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIEn2_start
      );

    AS_L1PHIFn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIFn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIFn2_wea_delay,
        addra     => AS_L1PHIFn2_writeaddr_delay,
        dina      => AS_L1PHIFn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIFn2_V_readaddr,
        doutb     => AS_L1PHIFn2_V_dout,
        sync_nent => AS_L1PHIFn2_start,
        nent_o    => open
      );

    AS_L1PHIFn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIFn2_wea,
        addra     => AS_L1PHIFn2_writeaddr,
        dina      => AS_L1PHIFn2_din,
        wea_out       => AS_L1PHIFn2_wea_delay,
        addra_out     => AS_L1PHIFn2_writeaddr_delay,
        dina_out      => AS_L1PHIFn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIFn2_start
      );

    AS_L1PHIGn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIGn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIGn2_wea_delay,
        addra     => AS_L1PHIGn2_writeaddr_delay,
        dina      => AS_L1PHIGn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIGn2_V_readaddr,
        doutb     => AS_L1PHIGn2_V_dout,
        sync_nent => AS_L1PHIGn2_start,
        nent_o    => open
      );

    AS_L1PHIGn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIGn2_wea,
        addra     => AS_L1PHIGn2_writeaddr,
        dina      => AS_L1PHIGn2_din,
        wea_out       => AS_L1PHIGn2_wea_delay,
        addra_out     => AS_L1PHIGn2_writeaddr_delay,
        dina_out      => AS_L1PHIGn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIGn2_start
      );

    AS_L1PHIHn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L1PHIHn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L1PHIHn2_wea_delay,
        addra     => AS_L1PHIHn2_writeaddr_delay,
        dina      => AS_L1PHIHn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L1PHIHn2_V_readaddr,
        doutb     => AS_L1PHIHn2_V_dout,
        sync_nent => AS_L1PHIHn2_start,
        nent_o    => open
      );

    AS_L1PHIHn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L1PHIHn2_wea,
        addra     => AS_L1PHIHn2_writeaddr,
        dina      => AS_L1PHIHn2_din,
        wea_out       => AS_L1PHIHn2_wea_delay,
        addra_out     => AS_L1PHIHn2_writeaddr_delay,
        dina_out      => AS_L1PHIHn2_din_delay,
        done       => PC_done,
        start      => AS_L1PHIHn2_start
      );

    AS_L2PHIAn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L2PHIAn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L2PHIAn2_wea_delay,
        addra     => AS_L2PHIAn2_writeaddr_delay,
        dina      => AS_L2PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L2PHIAn2_V_readaddr,
        doutb     => AS_L2PHIAn2_V_dout,
        sync_nent => AS_L2PHIAn2_start,
        nent_o    => open
      );

    AS_L2PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L2PHIAn2_wea,
        addra     => AS_L2PHIAn2_writeaddr,
        dina      => AS_L2PHIAn2_din,
        wea_out       => AS_L2PHIAn2_wea_delay,
        addra_out     => AS_L2PHIAn2_writeaddr_delay,
        dina_out      => AS_L2PHIAn2_din_delay,
        done       => PC_done,
        start      => AS_L2PHIAn2_start
      );

    AS_L2PHIBn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L2PHIBn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L2PHIBn2_wea_delay,
        addra     => AS_L2PHIBn2_writeaddr_delay,
        dina      => AS_L2PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L2PHIBn2_V_readaddr,
        doutb     => AS_L2PHIBn2_V_dout,
        sync_nent => AS_L2PHIBn2_start,
        nent_o    => open
      );

    AS_L2PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L2PHIBn2_wea,
        addra     => AS_L2PHIBn2_writeaddr,
        dina      => AS_L2PHIBn2_din,
        wea_out       => AS_L2PHIBn2_wea_delay,
        addra_out     => AS_L2PHIBn2_writeaddr_delay,
        dina_out      => AS_L2PHIBn2_din_delay,
        done       => PC_done,
        start      => AS_L2PHIBn2_start
      );

    AS_L2PHICn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L2PHICn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L2PHICn2_wea_delay,
        addra     => AS_L2PHICn2_writeaddr_delay,
        dina      => AS_L2PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L2PHICn2_V_readaddr,
        doutb     => AS_L2PHICn2_V_dout,
        sync_nent => AS_L2PHICn2_start,
        nent_o    => open
      );

    AS_L2PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L2PHICn2_wea,
        addra     => AS_L2PHICn2_writeaddr,
        dina      => AS_L2PHICn2_din,
        wea_out       => AS_L2PHICn2_wea_delay,
        addra_out     => AS_L2PHICn2_writeaddr_delay,
        dina_out      => AS_L2PHICn2_din_delay,
        done       => PC_done,
        start      => AS_L2PHICn2_start
      );

    AS_L2PHIDn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L2PHIDn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L2PHIDn2_wea_delay,
        addra     => AS_L2PHIDn2_writeaddr_delay,
        dina      => AS_L2PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L2PHIDn2_V_readaddr,
        doutb     => AS_L2PHIDn2_V_dout,
        sync_nent => AS_L2PHIDn2_start,
        nent_o    => open
      );

    AS_L2PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L2PHIDn2_wea,
        addra     => AS_L2PHIDn2_writeaddr,
        dina      => AS_L2PHIDn2_din,
        wea_out       => AS_L2PHIDn2_wea_delay,
        addra_out     => AS_L2PHIDn2_writeaddr_delay,
        dina_out      => AS_L2PHIDn2_din_delay,
        done       => PC_done,
        start      => AS_L2PHIDn2_start
      );

    AS_L3PHIAn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L3PHIAn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L3PHIAn2_wea_delay,
        addra     => AS_L3PHIAn2_writeaddr_delay,
        dina      => AS_L3PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L3PHIAn2_V_readaddr,
        doutb     => AS_L3PHIAn2_V_dout,
        sync_nent => AS_L3PHIAn2_start,
        nent_o    => open
      );

    AS_L3PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L3PHIAn2_wea,
        addra     => AS_L3PHIAn2_writeaddr,
        dina      => AS_L3PHIAn2_din,
        wea_out       => AS_L3PHIAn2_wea_delay,
        addra_out     => AS_L3PHIAn2_writeaddr_delay,
        dina_out      => AS_L3PHIAn2_din_delay,
        done       => PC_done,
        start      => AS_L3PHIAn2_start
      );

    AS_L3PHIBn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L3PHIBn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L3PHIBn2_wea_delay,
        addra     => AS_L3PHIBn2_writeaddr_delay,
        dina      => AS_L3PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L3PHIBn2_V_readaddr,
        doutb     => AS_L3PHIBn2_V_dout,
        sync_nent => AS_L3PHIBn2_start,
        nent_o    => open
      );

    AS_L3PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L3PHIBn2_wea,
        addra     => AS_L3PHIBn2_writeaddr,
        dina      => AS_L3PHIBn2_din,
        wea_out       => AS_L3PHIBn2_wea_delay,
        addra_out     => AS_L3PHIBn2_writeaddr_delay,
        dina_out      => AS_L3PHIBn2_din_delay,
        done       => PC_done,
        start      => AS_L3PHIBn2_start
      );

    AS_L3PHICn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L3PHICn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L3PHICn2_wea_delay,
        addra     => AS_L3PHICn2_writeaddr_delay,
        dina      => AS_L3PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L3PHICn2_V_readaddr,
        doutb     => AS_L3PHICn2_V_dout,
        sync_nent => AS_L3PHICn2_start,
        nent_o    => open
      );

    AS_L3PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L3PHICn2_wea,
        addra     => AS_L3PHICn2_writeaddr,
        dina      => AS_L3PHICn2_din,
        wea_out       => AS_L3PHICn2_wea_delay,
        addra_out     => AS_L3PHICn2_writeaddr_delay,
        dina_out      => AS_L3PHICn2_din_delay,
        done       => PC_done,
        start      => AS_L3PHICn2_start
      );

    AS_L3PHIDn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L3PHIDn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L3PHIDn2_wea_delay,
        addra     => AS_L3PHIDn2_writeaddr_delay,
        dina      => AS_L3PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L3PHIDn2_V_readaddr,
        doutb     => AS_L3PHIDn2_V_dout,
        sync_nent => AS_L3PHIDn2_start,
        nent_o    => open
      );

    AS_L3PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L3PHIDn2_wea,
        addra     => AS_L3PHIDn2_writeaddr,
        dina      => AS_L3PHIDn2_din,
        wea_out       => AS_L3PHIDn2_wea_delay,
        addra_out     => AS_L3PHIDn2_writeaddr_delay,
        dina_out      => AS_L3PHIDn2_din_delay,
        done       => PC_done,
        start      => AS_L3PHIDn2_start
      );

    AS_L4PHIAn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L4PHIAn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L4PHIAn2_wea_delay,
        addra     => AS_L4PHIAn2_writeaddr_delay,
        dina      => AS_L4PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L4PHIAn2_V_readaddr,
        doutb     => AS_L4PHIAn2_V_dout,
        sync_nent => AS_L4PHIAn2_start,
        nent_o    => open
      );

    AS_L4PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L4PHIAn2_wea,
        addra     => AS_L4PHIAn2_writeaddr,
        dina      => AS_L4PHIAn2_din,
        wea_out       => AS_L4PHIAn2_wea_delay,
        addra_out     => AS_L4PHIAn2_writeaddr_delay,
        dina_out      => AS_L4PHIAn2_din_delay,
        done       => PC_done,
        start      => AS_L4PHIAn2_start
      );

    AS_L4PHIBn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L4PHIBn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L4PHIBn2_wea_delay,
        addra     => AS_L4PHIBn2_writeaddr_delay,
        dina      => AS_L4PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L4PHIBn2_V_readaddr,
        doutb     => AS_L4PHIBn2_V_dout,
        sync_nent => AS_L4PHIBn2_start,
        nent_o    => open
      );

    AS_L4PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L4PHIBn2_wea,
        addra     => AS_L4PHIBn2_writeaddr,
        dina      => AS_L4PHIBn2_din,
        wea_out       => AS_L4PHIBn2_wea_delay,
        addra_out     => AS_L4PHIBn2_writeaddr_delay,
        dina_out      => AS_L4PHIBn2_din_delay,
        done       => PC_done,
        start      => AS_L4PHIBn2_start
      );

    AS_L4PHICn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L4PHICn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L4PHICn2_wea_delay,
        addra     => AS_L4PHICn2_writeaddr_delay,
        dina      => AS_L4PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L4PHICn2_V_readaddr,
        doutb     => AS_L4PHICn2_V_dout,
        sync_nent => AS_L4PHICn2_start,
        nent_o    => open
      );

    AS_L4PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L4PHICn2_wea,
        addra     => AS_L4PHICn2_writeaddr,
        dina      => AS_L4PHICn2_din,
        wea_out       => AS_L4PHICn2_wea_delay,
        addra_out     => AS_L4PHICn2_writeaddr_delay,
        dina_out      => AS_L4PHICn2_din_delay,
        done       => PC_done,
        start      => AS_L4PHICn2_start
      );

    AS_L4PHIDn2 : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 36,
        NUM_PAGES       => 8,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "AS_L4PHIDn2",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => AS_L4PHIDn2_wea_delay,
        addra     => AS_L4PHIDn2_writeaddr_delay,
        dina      => AS_L4PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => AS_L4PHIDn2_V_readaddr,
        doutb     => AS_L4PHIDn2_V_dout,
        sync_nent => AS_L4PHIDn2_start,
        nent_o    => open
      );

    AS_L4PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 8,
        RAM_WIDTH       => 36
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => AS_L4PHIDn2_wea,
        addra     => AS_L4PHIDn2_writeaddr,
        dina      => AS_L4PHIDn2_din,
        wea_out       => AS_L4PHIDn2_wea_delay,
        addra_out     => AS_L4PHIDn2_writeaddr_delay,
        dina_out      => AS_L4PHIDn2_din_delay,
        done       => PC_done,
        start      => AS_L4PHIDn2_start
      );

    VMSME_L1PHIAn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIAn2_V_datatmp,
        dataout0 => VMSME_L1PHIAn2_AV_dout(0),
        dataout1 => VMSME_L1PHIAn2_AV_dout(1),
        dataout2 => VMSME_L1PHIAn2_AV_dout(2),
        dataout3 => VMSME_L1PHIAn2_AV_dout(3)
      );

    VMSME_L1PHIAn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIAn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIAn2_wea_delay,
        addra     => VMSME_L1PHIAn2_writeaddr_delay,
        dina      => VMSME_L1PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIAn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIAn2_AV_readaddr(3),VMSME_L1PHIAn2_AV_readaddr(2),VMSME_L1PHIAn2_AV_readaddr(1),VMSME_L1PHIAn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIAn2_V_datatmp,
        enb_nent  => VMSME_L1PHIAn2_enb_nent,
        addr_nent  => VMSME_L1PHIAn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIAn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIAn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIAn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIAn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIAn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIAn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIAn2_V_binmaskb
      );

    VMSME_L1PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIAn2_wea,
        addra     => VMSME_L1PHIAn2_writeaddr,
        dina      => VMSME_L1PHIAn2_din,
        wea_out       => VMSME_L1PHIAn2_wea_delay,
        addra_out     => VMSME_L1PHIAn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIAn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIAn2_start
      );

    VMSME_L1PHIBn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIBn2_V_datatmp,
        dataout0 => VMSME_L1PHIBn2_AV_dout(0),
        dataout1 => VMSME_L1PHIBn2_AV_dout(1),
        dataout2 => VMSME_L1PHIBn2_AV_dout(2),
        dataout3 => VMSME_L1PHIBn2_AV_dout(3)
      );

    VMSME_L1PHIBn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIBn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIBn2_wea_delay,
        addra     => VMSME_L1PHIBn2_writeaddr_delay,
        dina      => VMSME_L1PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIBn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIBn2_AV_readaddr(3),VMSME_L1PHIBn2_AV_readaddr(2),VMSME_L1PHIBn2_AV_readaddr(1),VMSME_L1PHIBn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIBn2_V_datatmp,
        enb_nent  => VMSME_L1PHIBn2_enb_nent,
        addr_nent  => VMSME_L1PHIBn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIBn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIBn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIBn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIBn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIBn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIBn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIBn2_V_binmaskb
      );

    VMSME_L1PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIBn2_wea,
        addra     => VMSME_L1PHIBn2_writeaddr,
        dina      => VMSME_L1PHIBn2_din,
        wea_out       => VMSME_L1PHIBn2_wea_delay,
        addra_out     => VMSME_L1PHIBn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIBn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIBn2_start
      );

    VMSME_L1PHICn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHICn2_V_datatmp,
        dataout0 => VMSME_L1PHICn2_AV_dout(0),
        dataout1 => VMSME_L1PHICn2_AV_dout(1),
        dataout2 => VMSME_L1PHICn2_AV_dout(2),
        dataout3 => VMSME_L1PHICn2_AV_dout(3)
      );

    VMSME_L1PHICn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHICn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHICn2_wea_delay,
        addra     => VMSME_L1PHICn2_writeaddr_delay,
        dina      => VMSME_L1PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHICn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHICn2_AV_readaddr(3),VMSME_L1PHICn2_AV_readaddr(2),VMSME_L1PHICn2_AV_readaddr(1),VMSME_L1PHICn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHICn2_V_datatmp,
        enb_nent  => VMSME_L1PHICn2_enb_nent,
        addr_nent  => VMSME_L1PHICn2_V_addr_nent,
        dout_nent  => VMSME_L1PHICn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHICn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHICn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHICn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHICn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHICn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHICn2_V_binmaskb
      );

    VMSME_L1PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHICn2_wea,
        addra     => VMSME_L1PHICn2_writeaddr,
        dina      => VMSME_L1PHICn2_din,
        wea_out       => VMSME_L1PHICn2_wea_delay,
        addra_out     => VMSME_L1PHICn2_writeaddr_delay,
        dina_out      => VMSME_L1PHICn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHICn2_start
      );

    VMSME_L1PHIDn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIDn2_V_datatmp,
        dataout0 => VMSME_L1PHIDn2_AV_dout(0),
        dataout1 => VMSME_L1PHIDn2_AV_dout(1),
        dataout2 => VMSME_L1PHIDn2_AV_dout(2),
        dataout3 => VMSME_L1PHIDn2_AV_dout(3)
      );

    VMSME_L1PHIDn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIDn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIDn2_wea_delay,
        addra     => VMSME_L1PHIDn2_writeaddr_delay,
        dina      => VMSME_L1PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIDn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIDn2_AV_readaddr(3),VMSME_L1PHIDn2_AV_readaddr(2),VMSME_L1PHIDn2_AV_readaddr(1),VMSME_L1PHIDn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIDn2_V_datatmp,
        enb_nent  => VMSME_L1PHIDn2_enb_nent,
        addr_nent  => VMSME_L1PHIDn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIDn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIDn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIDn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIDn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIDn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIDn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIDn2_V_binmaskb
      );

    VMSME_L1PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIDn2_wea,
        addra     => VMSME_L1PHIDn2_writeaddr,
        dina      => VMSME_L1PHIDn2_din,
        wea_out       => VMSME_L1PHIDn2_wea_delay,
        addra_out     => VMSME_L1PHIDn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIDn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIDn2_start
      );

    VMSME_L1PHIEn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIEn2_V_datatmp,
        dataout0 => VMSME_L1PHIEn2_AV_dout(0),
        dataout1 => VMSME_L1PHIEn2_AV_dout(1),
        dataout2 => VMSME_L1PHIEn2_AV_dout(2),
        dataout3 => VMSME_L1PHIEn2_AV_dout(3)
      );

    VMSME_L1PHIEn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIEn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIEn2_wea_delay,
        addra     => VMSME_L1PHIEn2_writeaddr_delay,
        dina      => VMSME_L1PHIEn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIEn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIEn2_AV_readaddr(3),VMSME_L1PHIEn2_AV_readaddr(2),VMSME_L1PHIEn2_AV_readaddr(1),VMSME_L1PHIEn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIEn2_V_datatmp,
        enb_nent  => VMSME_L1PHIEn2_enb_nent,
        addr_nent  => VMSME_L1PHIEn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIEn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIEn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIEn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIEn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIEn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIEn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIEn2_V_binmaskb
      );

    VMSME_L1PHIEn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIEn2_wea,
        addra     => VMSME_L1PHIEn2_writeaddr,
        dina      => VMSME_L1PHIEn2_din,
        wea_out       => VMSME_L1PHIEn2_wea_delay,
        addra_out     => VMSME_L1PHIEn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIEn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIEn2_start
      );

    VMSME_L1PHIFn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIFn2_V_datatmp,
        dataout0 => VMSME_L1PHIFn2_AV_dout(0),
        dataout1 => VMSME_L1PHIFn2_AV_dout(1),
        dataout2 => VMSME_L1PHIFn2_AV_dout(2),
        dataout3 => VMSME_L1PHIFn2_AV_dout(3)
      );

    VMSME_L1PHIFn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIFn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIFn2_wea_delay,
        addra     => VMSME_L1PHIFn2_writeaddr_delay,
        dina      => VMSME_L1PHIFn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIFn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIFn2_AV_readaddr(3),VMSME_L1PHIFn2_AV_readaddr(2),VMSME_L1PHIFn2_AV_readaddr(1),VMSME_L1PHIFn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIFn2_V_datatmp,
        enb_nent  => VMSME_L1PHIFn2_enb_nent,
        addr_nent  => VMSME_L1PHIFn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIFn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIFn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIFn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIFn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIFn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIFn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIFn2_V_binmaskb
      );

    VMSME_L1PHIFn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIFn2_wea,
        addra     => VMSME_L1PHIFn2_writeaddr,
        dina      => VMSME_L1PHIFn2_din,
        wea_out       => VMSME_L1PHIFn2_wea_delay,
        addra_out     => VMSME_L1PHIFn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIFn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIFn2_start
      );

    VMSME_L1PHIGn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIGn2_V_datatmp,
        dataout0 => VMSME_L1PHIGn2_AV_dout(0),
        dataout1 => VMSME_L1PHIGn2_AV_dout(1),
        dataout2 => VMSME_L1PHIGn2_AV_dout(2),
        dataout3 => VMSME_L1PHIGn2_AV_dout(3)
      );

    VMSME_L1PHIGn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIGn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIGn2_wea_delay,
        addra     => VMSME_L1PHIGn2_writeaddr_delay,
        dina      => VMSME_L1PHIGn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIGn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIGn2_AV_readaddr(3),VMSME_L1PHIGn2_AV_readaddr(2),VMSME_L1PHIGn2_AV_readaddr(1),VMSME_L1PHIGn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIGn2_V_datatmp,
        enb_nent  => VMSME_L1PHIGn2_enb_nent,
        addr_nent  => VMSME_L1PHIGn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIGn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIGn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIGn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIGn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIGn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIGn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIGn2_V_binmaskb
      );

    VMSME_L1PHIGn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIGn2_wea,
        addra     => VMSME_L1PHIGn2_writeaddr,
        dina      => VMSME_L1PHIGn2_din,
        wea_out       => VMSME_L1PHIGn2_wea_delay,
        addra_out     => VMSME_L1PHIGn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIGn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIGn2_start
      );

    VMSME_L1PHIHn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L1PHIHn2_V_datatmp,
        dataout0 => VMSME_L1PHIHn2_AV_dout(0),
        dataout1 => VMSME_L1PHIHn2_AV_dout(1),
        dataout2 => VMSME_L1PHIHn2_AV_dout(2),
        dataout3 => VMSME_L1PHIHn2_AV_dout(3)
      );

    VMSME_L1PHIHn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L1PHIHn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L1PHIHn2_wea_delay,
        addra     => VMSME_L1PHIHn2_writeaddr_delay,
        dina      => VMSME_L1PHIHn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L1PHIHn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L1PHIHn2_AV_readaddr(3),VMSME_L1PHIHn2_AV_readaddr(2),VMSME_L1PHIHn2_AV_readaddr(1),VMSME_L1PHIHn2_AV_readaddr(0)),
        doutb     => VMSME_L1PHIHn2_V_datatmp,
        enb_nent  => VMSME_L1PHIHn2_enb_nent,
        addr_nent  => VMSME_L1PHIHn2_V_addr_nent,
        dout_nent  => VMSME_L1PHIHn2_AV_dout_nent,
        enb_binmaska  => VMSME_L1PHIHn2_enb_binmaska,
        addr_binmaska  => VMSME_L1PHIHn2_V_addr_binmaska,
        binmaska_o  => VMSME_L1PHIHn2_V_binmaska,
        enb_binmaskb  => VMSME_L1PHIHn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L1PHIHn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L1PHIHn2_V_binmaskb
      );

    VMSME_L1PHIHn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L1PHIHn2_wea,
        addra     => VMSME_L1PHIHn2_writeaddr,
        dina      => VMSME_L1PHIHn2_din,
        wea_out       => VMSME_L1PHIHn2_wea_delay,
        addra_out     => VMSME_L1PHIHn2_writeaddr_delay,
        dina_out      => VMSME_L1PHIHn2_din_delay,
        done       => PC_done,
        start      => VMSME_L1PHIHn2_start
      );

    VMSME_L2PHIAn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L2PHIAn2_V_datatmp,
        dataout0 => VMSME_L2PHIAn2_AV_dout(0),
        dataout1 => VMSME_L2PHIAn2_AV_dout(1),
        dataout2 => VMSME_L2PHIAn2_AV_dout(2),
        dataout3 => VMSME_L2PHIAn2_AV_dout(3)
      );

    VMSME_L2PHIAn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L2PHIAn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L2PHIAn2_wea_delay,
        addra     => VMSME_L2PHIAn2_writeaddr_delay,
        dina      => VMSME_L2PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L2PHIAn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L2PHIAn2_AV_readaddr(3),VMSME_L2PHIAn2_AV_readaddr(2),VMSME_L2PHIAn2_AV_readaddr(1),VMSME_L2PHIAn2_AV_readaddr(0)),
        doutb     => VMSME_L2PHIAn2_V_datatmp,
        enb_nent  => VMSME_L2PHIAn2_enb_nent,
        addr_nent  => VMSME_L2PHIAn2_V_addr_nent,
        dout_nent  => VMSME_L2PHIAn2_AV_dout_nent,
        enb_binmaska  => VMSME_L2PHIAn2_enb_binmaska,
        addr_binmaska  => VMSME_L2PHIAn2_V_addr_binmaska,
        binmaska_o  => VMSME_L2PHIAn2_V_binmaska,
        enb_binmaskb  => VMSME_L2PHIAn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L2PHIAn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L2PHIAn2_V_binmaskb
      );

    VMSME_L2PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L2PHIAn2_wea,
        addra     => VMSME_L2PHIAn2_writeaddr,
        dina      => VMSME_L2PHIAn2_din,
        wea_out       => VMSME_L2PHIAn2_wea_delay,
        addra_out     => VMSME_L2PHIAn2_writeaddr_delay,
        dina_out      => VMSME_L2PHIAn2_din_delay,
        done       => PC_done,
        start      => VMSME_L2PHIAn2_start
      );

    VMSME_L2PHIBn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L2PHIBn2_V_datatmp,
        dataout0 => VMSME_L2PHIBn2_AV_dout(0),
        dataout1 => VMSME_L2PHIBn2_AV_dout(1),
        dataout2 => VMSME_L2PHIBn2_AV_dout(2),
        dataout3 => VMSME_L2PHIBn2_AV_dout(3)
      );

    VMSME_L2PHIBn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L2PHIBn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L2PHIBn2_wea_delay,
        addra     => VMSME_L2PHIBn2_writeaddr_delay,
        dina      => VMSME_L2PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L2PHIBn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L2PHIBn2_AV_readaddr(3),VMSME_L2PHIBn2_AV_readaddr(2),VMSME_L2PHIBn2_AV_readaddr(1),VMSME_L2PHIBn2_AV_readaddr(0)),
        doutb     => VMSME_L2PHIBn2_V_datatmp,
        enb_nent  => VMSME_L2PHIBn2_enb_nent,
        addr_nent  => VMSME_L2PHIBn2_V_addr_nent,
        dout_nent  => VMSME_L2PHIBn2_AV_dout_nent,
        enb_binmaska  => VMSME_L2PHIBn2_enb_binmaska,
        addr_binmaska  => VMSME_L2PHIBn2_V_addr_binmaska,
        binmaska_o  => VMSME_L2PHIBn2_V_binmaska,
        enb_binmaskb  => VMSME_L2PHIBn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L2PHIBn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L2PHIBn2_V_binmaskb
      );

    VMSME_L2PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L2PHIBn2_wea,
        addra     => VMSME_L2PHIBn2_writeaddr,
        dina      => VMSME_L2PHIBn2_din,
        wea_out       => VMSME_L2PHIBn2_wea_delay,
        addra_out     => VMSME_L2PHIBn2_writeaddr_delay,
        dina_out      => VMSME_L2PHIBn2_din_delay,
        done       => PC_done,
        start      => VMSME_L2PHIBn2_start
      );

    VMSME_L2PHICn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L2PHICn2_V_datatmp,
        dataout0 => VMSME_L2PHICn2_AV_dout(0),
        dataout1 => VMSME_L2PHICn2_AV_dout(1),
        dataout2 => VMSME_L2PHICn2_AV_dout(2),
        dataout3 => VMSME_L2PHICn2_AV_dout(3)
      );

    VMSME_L2PHICn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L2PHICn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L2PHICn2_wea_delay,
        addra     => VMSME_L2PHICn2_writeaddr_delay,
        dina      => VMSME_L2PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L2PHICn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L2PHICn2_AV_readaddr(3),VMSME_L2PHICn2_AV_readaddr(2),VMSME_L2PHICn2_AV_readaddr(1),VMSME_L2PHICn2_AV_readaddr(0)),
        doutb     => VMSME_L2PHICn2_V_datatmp,
        enb_nent  => VMSME_L2PHICn2_enb_nent,
        addr_nent  => VMSME_L2PHICn2_V_addr_nent,
        dout_nent  => VMSME_L2PHICn2_AV_dout_nent,
        enb_binmaska  => VMSME_L2PHICn2_enb_binmaska,
        addr_binmaska  => VMSME_L2PHICn2_V_addr_binmaska,
        binmaska_o  => VMSME_L2PHICn2_V_binmaska,
        enb_binmaskb  => VMSME_L2PHICn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L2PHICn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L2PHICn2_V_binmaskb
      );

    VMSME_L2PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L2PHICn2_wea,
        addra     => VMSME_L2PHICn2_writeaddr,
        dina      => VMSME_L2PHICn2_din,
        wea_out       => VMSME_L2PHICn2_wea_delay,
        addra_out     => VMSME_L2PHICn2_writeaddr_delay,
        dina_out      => VMSME_L2PHICn2_din_delay,
        done       => PC_done,
        start      => VMSME_L2PHICn2_start
      );

    VMSME_L2PHIDn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L2PHIDn2_V_datatmp,
        dataout0 => VMSME_L2PHIDn2_AV_dout(0),
        dataout1 => VMSME_L2PHIDn2_AV_dout(1),
        dataout2 => VMSME_L2PHIDn2_AV_dout(2),
        dataout3 => VMSME_L2PHIDn2_AV_dout(3)
      );

    VMSME_L2PHIDn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L2PHIDn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L2PHIDn2_wea_delay,
        addra     => VMSME_L2PHIDn2_writeaddr_delay,
        dina      => VMSME_L2PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L2PHIDn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L2PHIDn2_AV_readaddr(3),VMSME_L2PHIDn2_AV_readaddr(2),VMSME_L2PHIDn2_AV_readaddr(1),VMSME_L2PHIDn2_AV_readaddr(0)),
        doutb     => VMSME_L2PHIDn2_V_datatmp,
        enb_nent  => VMSME_L2PHIDn2_enb_nent,
        addr_nent  => VMSME_L2PHIDn2_V_addr_nent,
        dout_nent  => VMSME_L2PHIDn2_AV_dout_nent,
        enb_binmaska  => VMSME_L2PHIDn2_enb_binmaska,
        addr_binmaska  => VMSME_L2PHIDn2_V_addr_binmaska,
        binmaska_o  => VMSME_L2PHIDn2_V_binmaska,
        enb_binmaskb  => VMSME_L2PHIDn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L2PHIDn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L2PHIDn2_V_binmaskb
      );

    VMSME_L2PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L2PHIDn2_wea,
        addra     => VMSME_L2PHIDn2_writeaddr,
        dina      => VMSME_L2PHIDn2_din,
        wea_out       => VMSME_L2PHIDn2_wea_delay,
        addra_out     => VMSME_L2PHIDn2_writeaddr_delay,
        dina_out      => VMSME_L2PHIDn2_din_delay,
        done       => PC_done,
        start      => VMSME_L2PHIDn2_start
      );

    VMSME_L3PHIAn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L3PHIAn2_V_datatmp,
        dataout0 => VMSME_L3PHIAn2_AV_dout(0),
        dataout1 => VMSME_L3PHIAn2_AV_dout(1),
        dataout2 => VMSME_L3PHIAn2_AV_dout(2),
        dataout3 => VMSME_L3PHIAn2_AV_dout(3)
      );

    VMSME_L3PHIAn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L3PHIAn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L3PHIAn2_wea_delay,
        addra     => VMSME_L3PHIAn2_writeaddr_delay,
        dina      => VMSME_L3PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L3PHIAn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L3PHIAn2_AV_readaddr(3),VMSME_L3PHIAn2_AV_readaddr(2),VMSME_L3PHIAn2_AV_readaddr(1),VMSME_L3PHIAn2_AV_readaddr(0)),
        doutb     => VMSME_L3PHIAn2_V_datatmp,
        enb_nent  => VMSME_L3PHIAn2_enb_nent,
        addr_nent  => VMSME_L3PHIAn2_V_addr_nent,
        dout_nent  => VMSME_L3PHIAn2_AV_dout_nent,
        enb_binmaska  => VMSME_L3PHIAn2_enb_binmaska,
        addr_binmaska  => VMSME_L3PHIAn2_V_addr_binmaska,
        binmaska_o  => VMSME_L3PHIAn2_V_binmaska,
        enb_binmaskb  => VMSME_L3PHIAn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L3PHIAn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L3PHIAn2_V_binmaskb
      );

    VMSME_L3PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L3PHIAn2_wea,
        addra     => VMSME_L3PHIAn2_writeaddr,
        dina      => VMSME_L3PHIAn2_din,
        wea_out       => VMSME_L3PHIAn2_wea_delay,
        addra_out     => VMSME_L3PHIAn2_writeaddr_delay,
        dina_out      => VMSME_L3PHIAn2_din_delay,
        done       => PC_done,
        start      => VMSME_L3PHIAn2_start
      );

    VMSME_L3PHIBn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L3PHIBn2_V_datatmp,
        dataout0 => VMSME_L3PHIBn2_AV_dout(0),
        dataout1 => VMSME_L3PHIBn2_AV_dout(1),
        dataout2 => VMSME_L3PHIBn2_AV_dout(2),
        dataout3 => VMSME_L3PHIBn2_AV_dout(3)
      );

    VMSME_L3PHIBn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L3PHIBn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L3PHIBn2_wea_delay,
        addra     => VMSME_L3PHIBn2_writeaddr_delay,
        dina      => VMSME_L3PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L3PHIBn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L3PHIBn2_AV_readaddr(3),VMSME_L3PHIBn2_AV_readaddr(2),VMSME_L3PHIBn2_AV_readaddr(1),VMSME_L3PHIBn2_AV_readaddr(0)),
        doutb     => VMSME_L3PHIBn2_V_datatmp,
        enb_nent  => VMSME_L3PHIBn2_enb_nent,
        addr_nent  => VMSME_L3PHIBn2_V_addr_nent,
        dout_nent  => VMSME_L3PHIBn2_AV_dout_nent,
        enb_binmaska  => VMSME_L3PHIBn2_enb_binmaska,
        addr_binmaska  => VMSME_L3PHIBn2_V_addr_binmaska,
        binmaska_o  => VMSME_L3PHIBn2_V_binmaska,
        enb_binmaskb  => VMSME_L3PHIBn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L3PHIBn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L3PHIBn2_V_binmaskb
      );

    VMSME_L3PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L3PHIBn2_wea,
        addra     => VMSME_L3PHIBn2_writeaddr,
        dina      => VMSME_L3PHIBn2_din,
        wea_out       => VMSME_L3PHIBn2_wea_delay,
        addra_out     => VMSME_L3PHIBn2_writeaddr_delay,
        dina_out      => VMSME_L3PHIBn2_din_delay,
        done       => PC_done,
        start      => VMSME_L3PHIBn2_start
      );

    VMSME_L3PHICn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L3PHICn2_V_datatmp,
        dataout0 => VMSME_L3PHICn2_AV_dout(0),
        dataout1 => VMSME_L3PHICn2_AV_dout(1),
        dataout2 => VMSME_L3PHICn2_AV_dout(2),
        dataout3 => VMSME_L3PHICn2_AV_dout(3)
      );

    VMSME_L3PHICn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L3PHICn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L3PHICn2_wea_delay,
        addra     => VMSME_L3PHICn2_writeaddr_delay,
        dina      => VMSME_L3PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L3PHICn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L3PHICn2_AV_readaddr(3),VMSME_L3PHICn2_AV_readaddr(2),VMSME_L3PHICn2_AV_readaddr(1),VMSME_L3PHICn2_AV_readaddr(0)),
        doutb     => VMSME_L3PHICn2_V_datatmp,
        enb_nent  => VMSME_L3PHICn2_enb_nent,
        addr_nent  => VMSME_L3PHICn2_V_addr_nent,
        dout_nent  => VMSME_L3PHICn2_AV_dout_nent,
        enb_binmaska  => VMSME_L3PHICn2_enb_binmaska,
        addr_binmaska  => VMSME_L3PHICn2_V_addr_binmaska,
        binmaska_o  => VMSME_L3PHICn2_V_binmaska,
        enb_binmaskb  => VMSME_L3PHICn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L3PHICn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L3PHICn2_V_binmaskb
      );

    VMSME_L3PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L3PHICn2_wea,
        addra     => VMSME_L3PHICn2_writeaddr,
        dina      => VMSME_L3PHICn2_din,
        wea_out       => VMSME_L3PHICn2_wea_delay,
        addra_out     => VMSME_L3PHICn2_writeaddr_delay,
        dina_out      => VMSME_L3PHICn2_din_delay,
        done       => PC_done,
        start      => VMSME_L3PHICn2_start
      );

    VMSME_L3PHIDn2_dataformat : entity work.vmstub16dout4
      port map (
        datain => VMSME_L3PHIDn2_V_datatmp,
        dataout0 => VMSME_L3PHIDn2_AV_dout(0),
        dataout1 => VMSME_L3PHIDn2_AV_dout(1),
        dataout2 => VMSME_L3PHIDn2_AV_dout(2),
        dataout3 => VMSME_L3PHIDn2_AV_dout(3)
      );

    VMSME_L3PHIDn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 16,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L3PHIDn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L3PHIDn2_wea_delay,
        addra     => VMSME_L3PHIDn2_writeaddr_delay,
        dina      => VMSME_L3PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L3PHIDn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L3PHIDn2_AV_readaddr(3),VMSME_L3PHIDn2_AV_readaddr(2),VMSME_L3PHIDn2_AV_readaddr(1),VMSME_L3PHIDn2_AV_readaddr(0)),
        doutb     => VMSME_L3PHIDn2_V_datatmp,
        enb_nent  => VMSME_L3PHIDn2_enb_nent,
        addr_nent  => VMSME_L3PHIDn2_V_addr_nent,
        dout_nent  => VMSME_L3PHIDn2_AV_dout_nent,
        enb_binmaska  => VMSME_L3PHIDn2_enb_binmaska,
        addr_binmaska  => VMSME_L3PHIDn2_V_addr_binmaska,
        binmaska_o  => VMSME_L3PHIDn2_V_binmaska,
        enb_binmaskb  => VMSME_L3PHIDn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L3PHIDn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L3PHIDn2_V_binmaskb
      );

    VMSME_L3PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 16
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L3PHIDn2_wea,
        addra     => VMSME_L3PHIDn2_writeaddr,
        dina      => VMSME_L3PHIDn2_din,
        wea_out       => VMSME_L3PHIDn2_wea_delay,
        addra_out     => VMSME_L3PHIDn2_writeaddr_delay,
        dina_out      => VMSME_L3PHIDn2_din_delay,
        done       => PC_done,
        start      => VMSME_L3PHIDn2_start
      );

    VMSME_L4PHIAn2_dataformat : entity work.vmstub17dout4
      port map (
        datain => VMSME_L4PHIAn2_V_datatmp,
        dataout0 => VMSME_L4PHIAn2_AV_dout(0),
        dataout1 => VMSME_L4PHIAn2_AV_dout(1),
        dataout2 => VMSME_L4PHIAn2_AV_dout(2),
        dataout3 => VMSME_L4PHIAn2_AV_dout(3)
      );

    VMSME_L4PHIAn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L4PHIAn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L4PHIAn2_wea_delay,
        addra     => VMSME_L4PHIAn2_writeaddr_delay,
        dina      => VMSME_L4PHIAn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L4PHIAn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L4PHIAn2_AV_readaddr(3),VMSME_L4PHIAn2_AV_readaddr(2),VMSME_L4PHIAn2_AV_readaddr(1),VMSME_L4PHIAn2_AV_readaddr(0)),
        doutb     => VMSME_L4PHIAn2_V_datatmp,
        enb_nent  => VMSME_L4PHIAn2_enb_nent,
        addr_nent  => VMSME_L4PHIAn2_V_addr_nent,
        dout_nent  => VMSME_L4PHIAn2_AV_dout_nent,
        enb_binmaska  => VMSME_L4PHIAn2_enb_binmaska,
        addr_binmaska  => VMSME_L4PHIAn2_V_addr_binmaska,
        binmaska_o  => VMSME_L4PHIAn2_V_binmaska,
        enb_binmaskb  => VMSME_L4PHIAn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L4PHIAn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L4PHIAn2_V_binmaskb
      );

    VMSME_L4PHIAn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 17
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L4PHIAn2_wea,
        addra     => VMSME_L4PHIAn2_writeaddr,
        dina      => VMSME_L4PHIAn2_din,
        wea_out       => VMSME_L4PHIAn2_wea_delay,
        addra_out     => VMSME_L4PHIAn2_writeaddr_delay,
        dina_out      => VMSME_L4PHIAn2_din_delay,
        done       => PC_done,
        start      => VMSME_L4PHIAn2_start
      );

    VMSME_L4PHIBn2_dataformat : entity work.vmstub17dout4
      port map (
        datain => VMSME_L4PHIBn2_V_datatmp,
        dataout0 => VMSME_L4PHIBn2_AV_dout(0),
        dataout1 => VMSME_L4PHIBn2_AV_dout(1),
        dataout2 => VMSME_L4PHIBn2_AV_dout(2),
        dataout3 => VMSME_L4PHIBn2_AV_dout(3)
      );

    VMSME_L4PHIBn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L4PHIBn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L4PHIBn2_wea_delay,
        addra     => VMSME_L4PHIBn2_writeaddr_delay,
        dina      => VMSME_L4PHIBn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L4PHIBn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L4PHIBn2_AV_readaddr(3),VMSME_L4PHIBn2_AV_readaddr(2),VMSME_L4PHIBn2_AV_readaddr(1),VMSME_L4PHIBn2_AV_readaddr(0)),
        doutb     => VMSME_L4PHIBn2_V_datatmp,
        enb_nent  => VMSME_L4PHIBn2_enb_nent,
        addr_nent  => VMSME_L4PHIBn2_V_addr_nent,
        dout_nent  => VMSME_L4PHIBn2_AV_dout_nent,
        enb_binmaska  => VMSME_L4PHIBn2_enb_binmaska,
        addr_binmaska  => VMSME_L4PHIBn2_V_addr_binmaska,
        binmaska_o  => VMSME_L4PHIBn2_V_binmaska,
        enb_binmaskb  => VMSME_L4PHIBn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L4PHIBn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L4PHIBn2_V_binmaskb
      );

    VMSME_L4PHIBn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 17
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L4PHIBn2_wea,
        addra     => VMSME_L4PHIBn2_writeaddr,
        dina      => VMSME_L4PHIBn2_din,
        wea_out       => VMSME_L4PHIBn2_wea_delay,
        addra_out     => VMSME_L4PHIBn2_writeaddr_delay,
        dina_out      => VMSME_L4PHIBn2_din_delay,
        done       => PC_done,
        start      => VMSME_L4PHIBn2_start
      );

    VMSME_L4PHICn2_dataformat : entity work.vmstub17dout4
      port map (
        datain => VMSME_L4PHICn2_V_datatmp,
        dataout0 => VMSME_L4PHICn2_AV_dout(0),
        dataout1 => VMSME_L4PHICn2_AV_dout(1),
        dataout2 => VMSME_L4PHICn2_AV_dout(2),
        dataout3 => VMSME_L4PHICn2_AV_dout(3)
      );

    VMSME_L4PHICn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L4PHICn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L4PHICn2_wea_delay,
        addra     => VMSME_L4PHICn2_writeaddr_delay,
        dina      => VMSME_L4PHICn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L4PHICn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L4PHICn2_AV_readaddr(3),VMSME_L4PHICn2_AV_readaddr(2),VMSME_L4PHICn2_AV_readaddr(1),VMSME_L4PHICn2_AV_readaddr(0)),
        doutb     => VMSME_L4PHICn2_V_datatmp,
        enb_nent  => VMSME_L4PHICn2_enb_nent,
        addr_nent  => VMSME_L4PHICn2_V_addr_nent,
        dout_nent  => VMSME_L4PHICn2_AV_dout_nent,
        enb_binmaska  => VMSME_L4PHICn2_enb_binmaska,
        addr_binmaska  => VMSME_L4PHICn2_V_addr_binmaska,
        binmaska_o  => VMSME_L4PHICn2_V_binmaska,
        enb_binmaskb  => VMSME_L4PHICn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L4PHICn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L4PHICn2_V_binmaskb
      );

    VMSME_L4PHICn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 17
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L4PHICn2_wea,
        addra     => VMSME_L4PHICn2_writeaddr,
        dina      => VMSME_L4PHICn2_din,
        wea_out       => VMSME_L4PHICn2_wea_delay,
        addra_out     => VMSME_L4PHICn2_writeaddr_delay,
        dina_out      => VMSME_L4PHICn2_din_delay,
        done       => PC_done,
        start      => VMSME_L4PHICn2_start
      );

    VMSME_L4PHIDn2_dataformat : entity work.vmstub17dout4
      port map (
        datain => VMSME_L4PHIDn2_V_datatmp,
        dataout0 => VMSME_L4PHIDn2_AV_dout(0),
        dataout1 => VMSME_L4PHIDn2_AV_dout(1),
        dataout2 => VMSME_L4PHIDn2_AV_dout(2),
        dataout3 => VMSME_L4PHIDn2_AV_dout(3)
      );

    VMSME_L4PHIDn2 : entity work.tf_mem_bin
      generic map (
        RAM_WIDTH       => 17,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "VMSME_L4PHIDn2",
        FILE_WRITE            => true,
        ADDR_WIDTH      => 4,
        NUM_PHI_BINS    => 8,
        NUM_RZ_BINS     => 8,
        NUM_COPY        => 4
      )
      port map (
        clka      => clk240,
        wea       => VMSME_L4PHIDn2_wea_delay,
        addra     => VMSME_L4PHIDn2_writeaddr_delay,
        dina      => VMSME_L4PHIDn2_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        sync_nent => VMSME_L4PHIDn2_start,
        enb       => (others => '1'),
        addrb     => (VMSME_L4PHIDn2_AV_readaddr(3),VMSME_L4PHIDn2_AV_readaddr(2),VMSME_L4PHIDn2_AV_readaddr(1),VMSME_L4PHIDn2_AV_readaddr(0)),
        doutb     => VMSME_L4PHIDn2_V_datatmp,
        enb_nent  => VMSME_L4PHIDn2_enb_nent,
        addr_nent  => VMSME_L4PHIDn2_V_addr_nent,
        dout_nent  => VMSME_L4PHIDn2_AV_dout_nent,
        enb_binmaska  => VMSME_L4PHIDn2_enb_binmaska,
        addr_binmaska  => VMSME_L4PHIDn2_V_addr_binmaska,
        binmaska_o  => VMSME_L4PHIDn2_V_binmaska,
        enb_binmaskb  => VMSME_L4PHIDn2_enb_binmaskb,
        addr_binmaskb  => VMSME_L4PHIDn2_V_addr_binmaskb,
        binmaskb_o  => VMSME_L4PHIDn2_V_binmaskb
      );

    VMSME_L4PHIDn2_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_DEPTH       => 2*PAGE_LENGTH_CM,
        RAM_WIDTH       => 17
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => VMSME_L4PHIDn2_wea,
        addra     => VMSME_L4PHIDn2_writeaddr,
        dina      => VMSME_L4PHIDn2_din,
        wea_out       => VMSME_L4PHIDn2_wea_delay,
        addra_out     => VMSME_L4PHIDn2_writeaddr_delay,
        dina_out      => VMSME_L4PHIDn2_din_delay,
        done       => PC_done,
        start      => VMSME_L4PHIDn2_start
      );

    MPAR_L5L6ABCDin : entity work.tf_mem_tpar -- do we still want this ???? 
      generic map (
        RAM_WIDTH       => 73,
        NUM_PAGES       => 8,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPAR_L5L6ABCDin",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => MPAR_L5L6ABCDin_wea_delay,
        addra     => MPAR_L5L6ABCDin_writeaddr_delay,
        dina      => MPAR_L5L6ABCDin_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPAR_L5L6ABCDin_V_readaddr,
        doutb     => MPAR_L5L6ABCDin_V_dout,
        sync_nent => MPAR_L5L6ABCDin_start,
        nent_o    => MPAR_L5L6ABCDin_AV_dout_nent,
        mask_o    => MPAR_L5L6ABCDin_AV_dout_mask
      );

    MPAR_L5L6ABCDin_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 32,
        RAM_WIDTH       => 73
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPAR_L5L6ABCDin_wea,
        addra     => MPAR_L5L6ABCDin_writeaddr,
        dina      => MPAR_L5L6ABCDin_din,
        wea_out       => MPAR_L5L6ABCDin_wea_delay,
        addra_out     => MPAR_L5L6ABCDin_writeaddr_delay,
        dina_out      => MPAR_L5L6ABCDin_din_delay,
        done       => PC_start,
        start      => MPAR_L5L6ABCDin_start
      );

    MPAR_L5L6ABCD : entity work.tf_mem_tpar
      generic map (
        RAM_WIDTH       => 73,
        NUM_PAGES       => 8,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPAR_L5L6ABCD",
        FILE_WRITE            => false
      )
      port map (
        clka      => clk240,
        wea       => MPAR_L5L6ABCD_wea_delay,
        addra     => MPAR_L5L6ABCD_writeaddr_delay,
        dina      => MPAR_L5L6ABCD_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPAR_L5L6ABCD_V_readaddr,
        doutb     => MPAR_L5L6ABCD_V_dout,
        sync_nent => MPAR_L5L6ABCD_start,
        nent_o    => open
      );

    MPAR_L5L6ABCD_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 32,
        RAM_WIDTH       => 73
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPAR_L5L6ABCD_wea,
        addra     => MPAR_L5L6ABCD_writeaddr,
        dina      => MPAR_L5L6ABCD_din,
        wea_out       => MPAR_L5L6ABCD_wea_delay,
        addra_out     => MPAR_L5L6ABCD_writeaddr_delay,
        dina_out      => MPAR_L5L6ABCD_din_delay,
        done       => PC_done,
        start      => MPAR_L5L6ABCD_start
      );

    MPROJ_L5L6ABCD_L1PHIA : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIA_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIA_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIA_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIA_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIA_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIA_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIA_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIA_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIA_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIA_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIA_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIA_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIA_start
      );

    MPROJ_L5L6ABCD_L1PHIB : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIB_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIB_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIB_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIB_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIB_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIB_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIB_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIB_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIB_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIB_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIB_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIB_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIB_start
      );

    MPROJ_L5L6ABCD_L1PHIC : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIC_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIC_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIC_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIC_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIC_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIC_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIC_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIC_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIC_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIC_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIC_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIC_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIC_start
      );

    MPROJ_L5L6ABCD_L1PHID : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHID_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHID_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHID_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHID_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHID_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHID_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHID_wea,
        addra     => MPROJ_L5L6ABCD_L1PHID_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHID_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHID_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHID_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHID_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHID_start
      );

    MPROJ_L5L6ABCD_L1PHIE : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIE",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIE_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIE_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIE_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIE_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIE_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIE_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIE_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIE_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIE_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIE_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIE_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIE_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIE_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIE_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIE_start
      );

    MPROJ_L5L6ABCD_L1PHIF : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIF",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIF_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIF_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIF_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIF_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIF_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIF_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIF_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIF_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIF_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIF_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIF_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIF_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIF_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIF_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIF_start
      );

    MPROJ_L5L6ABCD_L1PHIG : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIG",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIG_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIG_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIG_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIG_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIG_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIG_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIG_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIG_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIG_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIG_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIG_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIG_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIG_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIG_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIG_start
      );

    MPROJ_L5L6ABCD_L1PHIH : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L1PHIH",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L1PHIH_wea_delay,
        addra     => MPROJ_L5L6ABCD_L1PHIH_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L1PHIH_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L1PHIH_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L1PHIH_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L1PHIH_start,
        nent_o    => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L1PHIH_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L1PHIH_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L1PHIH_wea,
        addra     => MPROJ_L5L6ABCD_L1PHIH_writeaddr,
        dina      => MPROJ_L5L6ABCD_L1PHIH_din,
        wea_out       => MPROJ_L5L6ABCD_L1PHIH_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L1PHIH_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L1PHIH_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L1PHIH_start
      );

    MPROJ_L5L6ABCD_L2PHIA : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L2PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L2PHIA_wea_delay,
        addra     => MPROJ_L5L6ABCD_L2PHIA_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L2PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L2PHIA_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L2PHIA_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L2PHIA_start,
        nent_o    => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L2PHIA_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L2PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L2PHIA_wea,
        addra     => MPROJ_L5L6ABCD_L2PHIA_writeaddr,
        dina      => MPROJ_L5L6ABCD_L2PHIA_din,
        wea_out       => MPROJ_L5L6ABCD_L2PHIA_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L2PHIA_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L2PHIA_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L2PHIA_start
      );

    MPROJ_L5L6ABCD_L2PHIB : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L2PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L2PHIB_wea_delay,
        addra     => MPROJ_L5L6ABCD_L2PHIB_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L2PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L2PHIB_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L2PHIB_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L2PHIB_start,
        nent_o    => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L2PHIB_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L2PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L2PHIB_wea,
        addra     => MPROJ_L5L6ABCD_L2PHIB_writeaddr,
        dina      => MPROJ_L5L6ABCD_L2PHIB_din,
        wea_out       => MPROJ_L5L6ABCD_L2PHIB_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L2PHIB_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L2PHIB_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L2PHIB_start
      );

    MPROJ_L5L6ABCD_L2PHIC : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L2PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L2PHIC_wea_delay,
        addra     => MPROJ_L5L6ABCD_L2PHIC_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L2PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L2PHIC_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L2PHIC_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L2PHIC_start,
        nent_o    => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L2PHIC_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L2PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L2PHIC_wea,
        addra     => MPROJ_L5L6ABCD_L2PHIC_writeaddr,
        dina      => MPROJ_L5L6ABCD_L2PHIC_din,
        wea_out       => MPROJ_L5L6ABCD_L2PHIC_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L2PHIC_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L2PHIC_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L2PHIC_start
      );

    MPROJ_L5L6ABCD_L2PHID : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L2PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L2PHID_wea_delay,
        addra     => MPROJ_L5L6ABCD_L2PHID_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L2PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L2PHID_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L2PHID_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L2PHID_start,
        nent_o    => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L2PHID_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L2PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L2PHID_wea,
        addra     => MPROJ_L5L6ABCD_L2PHID_writeaddr,
        dina      => MPROJ_L5L6ABCD_L2PHID_din,
        wea_out       => MPROJ_L5L6ABCD_L2PHID_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L2PHID_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L2PHID_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L2PHID_start
      );

    MPROJ_L5L6ABCD_L3PHIA : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L3PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L3PHIA_wea_delay,
        addra     => MPROJ_L5L6ABCD_L3PHIA_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L3PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L3PHIA_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L3PHIA_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L3PHIA_start,
        nent_o    => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L3PHIA_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L3PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L3PHIA_wea,
        addra     => MPROJ_L5L6ABCD_L3PHIA_writeaddr,
        dina      => MPROJ_L5L6ABCD_L3PHIA_din,
        wea_out       => MPROJ_L5L6ABCD_L3PHIA_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L3PHIA_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L3PHIA_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L3PHIA_start
      );

    MPROJ_L5L6ABCD_L3PHIB : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L3PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L3PHIB_wea_delay,
        addra     => MPROJ_L5L6ABCD_L3PHIB_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L3PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L3PHIB_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L3PHIB_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L3PHIB_start,
        nent_o    => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L3PHIB_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L3PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L3PHIB_wea,
        addra     => MPROJ_L5L6ABCD_L3PHIB_writeaddr,
        dina      => MPROJ_L5L6ABCD_L3PHIB_din,
        wea_out       => MPROJ_L5L6ABCD_L3PHIB_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L3PHIB_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L3PHIB_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L3PHIB_start
      );

    MPROJ_L5L6ABCD_L3PHIC : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L3PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L3PHIC_wea_delay,
        addra     => MPROJ_L5L6ABCD_L3PHIC_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L3PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L3PHIC_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L3PHIC_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L3PHIC_start,
        nent_o    => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L3PHIC_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L3PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L3PHIC_wea,
        addra     => MPROJ_L5L6ABCD_L3PHIC_writeaddr,
        dina      => MPROJ_L5L6ABCD_L3PHIC_din,
        wea_out       => MPROJ_L5L6ABCD_L3PHIC_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L3PHIC_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L3PHIC_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L3PHIC_start
      );

    MPROJ_L5L6ABCD_L3PHID : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 60,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L3PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L3PHID_wea_delay,
        addra     => MPROJ_L5L6ABCD_L3PHID_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L3PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L3PHID_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L3PHID_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L3PHID_start,
        nent_o    => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L3PHID_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L3PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 60
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L3PHID_wea,
        addra     => MPROJ_L5L6ABCD_L3PHID_writeaddr,
        dina      => MPROJ_L5L6ABCD_L3PHID_din,
        wea_out       => MPROJ_L5L6ABCD_L3PHID_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L3PHID_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L3PHID_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L3PHID_start
      );

    MPROJ_L5L6ABCD_L4PHIA : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L4PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L4PHIA_wea_delay,
        addra     => MPROJ_L5L6ABCD_L4PHIA_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L4PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L4PHIA_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L4PHIA_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L4PHIA_start,
        nent_o    => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L4PHIA_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L4PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 58
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L4PHIA_wea,
        addra     => MPROJ_L5L6ABCD_L4PHIA_writeaddr,
        dina      => MPROJ_L5L6ABCD_L4PHIA_din,
        wea_out       => MPROJ_L5L6ABCD_L4PHIA_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L4PHIA_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L4PHIA_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L4PHIA_start
      );

    MPROJ_L5L6ABCD_L4PHIB : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L4PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L4PHIB_wea_delay,
        addra     => MPROJ_L5L6ABCD_L4PHIB_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L4PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L4PHIB_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L4PHIB_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L4PHIB_start,
        nent_o    => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L4PHIB_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L4PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 58
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L4PHIB_wea,
        addra     => MPROJ_L5L6ABCD_L4PHIB_writeaddr,
        dina      => MPROJ_L5L6ABCD_L4PHIB_din,
        wea_out       => MPROJ_L5L6ABCD_L4PHIB_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L4PHIB_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L4PHIB_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L4PHIB_start
      );

    MPROJ_L5L6ABCD_L4PHIC : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L4PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L4PHIC_wea_delay,
        addra     => MPROJ_L5L6ABCD_L4PHIC_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L4PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L4PHIC_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L4PHIC_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L4PHIC_start,
        nent_o    => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L4PHIC_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L4PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 58
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L4PHIC_wea,
        addra     => MPROJ_L5L6ABCD_L4PHIC_writeaddr,
        dina      => MPROJ_L5L6ABCD_L4PHIC_din,
        wea_out       => MPROJ_L5L6ABCD_L4PHIC_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L4PHIC_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L4PHIC_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L4PHIC_start
      );

    MPROJ_L5L6ABCD_L4PHID : entity work.tf_mem_tproj
      generic map (
        RAM_WIDTH       => 58,
        NUM_PAGES       => 2,
        PAGE_LENGTH       => 64,
        NUM_TPAGES       => 4,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "MPROJ_L5L6ABCD_L4PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => MPROJ_L5L6ABCD_L4PHID_wea_delay,
        addra     => MPROJ_L5L6ABCD_L4PHID_writeaddr_delay,
        dina      => MPROJ_L5L6ABCD_L4PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => MPROJ_L5L6ABCD_L4PHID_V_readaddr,
        doutb     => MPROJ_L5L6ABCD_L4PHID_V_dout,
        sync_nent => MPROJ_L5L6ABCD_L4PHID_start,
        nent_o    => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent,
        mask_o    => MPROJ_L5L6ABCD_L4PHID_AV_dout_mask
      );

    MPROJ_L5L6ABCD_L4PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        PAGE_LENGTH       => 64,
        NUM_PAGES       => 8,
        RAM_WIDTH       => 58
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => MPROJ_L5L6ABCD_L4PHID_wea,
        addra     => MPROJ_L5L6ABCD_L4PHID_writeaddr,
        dina      => MPROJ_L5L6ABCD_L4PHID_din,
        wea_out       => MPROJ_L5L6ABCD_L4PHID_wea_delay,
        addra_out     => MPROJ_L5L6ABCD_L4PHID_writeaddr_delay,
        dina_out      => MPROJ_L5L6ABCD_L4PHID_din_delay,
        done       => PC_done,
        start      => MPROJ_L5L6ABCD_L4PHID_start
      );

    FM_AAAA_L1PHIA : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIA_wea_delay,
        addra     => FM_AAAA_L1PHIA_writeaddr_delay,
        dina      => FM_AAAA_L1PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIA_V_readaddr,
        doutb     => FM_AAAA_L1PHIA_V_dout,
        sync_nent => FM_AAAA_L1PHIA_start,
        nent_o    => FM_AAAA_L1PHIA_AV_dout_nent
      );

    FM_AAAA_L1PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIA_wea,
        addra     => FM_AAAA_L1PHIA_writeaddr,
        dina      => FM_AAAA_L1PHIA_din,
        wea_out       => FM_AAAA_L1PHIA_wea_delay,
        addra_out     => FM_AAAA_L1PHIA_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIA_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIA_start
      );

    FM_AAAA_L1PHIB : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIB_wea_delay,
        addra     => FM_AAAA_L1PHIB_writeaddr_delay,
        dina      => FM_AAAA_L1PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIB_V_readaddr,
        doutb     => FM_AAAA_L1PHIB_V_dout,
        sync_nent => FM_AAAA_L1PHIB_start,
        nent_o    => FM_AAAA_L1PHIB_AV_dout_nent
      );

    FM_AAAA_L1PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIB_wea,
        addra     => FM_AAAA_L1PHIB_writeaddr,
        dina      => FM_AAAA_L1PHIB_din,
        wea_out       => FM_AAAA_L1PHIB_wea_delay,
        addra_out     => FM_AAAA_L1PHIB_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIB_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIB_start
      );

    FM_AAAA_L1PHIC : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIC_wea_delay,
        addra     => FM_AAAA_L1PHIC_writeaddr_delay,
        dina      => FM_AAAA_L1PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIC_V_readaddr,
        doutb     => FM_AAAA_L1PHIC_V_dout,
        sync_nent => FM_AAAA_L1PHIC_start,
        nent_o    => FM_AAAA_L1PHIC_AV_dout_nent
      );

    FM_AAAA_L1PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIC_wea,
        addra     => FM_AAAA_L1PHIC_writeaddr,
        dina      => FM_AAAA_L1PHIC_din,
        wea_out       => FM_AAAA_L1PHIC_wea_delay,
        addra_out     => FM_AAAA_L1PHIC_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIC_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIC_start
      );

    FM_AAAA_L1PHID : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHID_wea_delay,
        addra     => FM_AAAA_L1PHID_writeaddr_delay,
        dina      => FM_AAAA_L1PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHID_V_readaddr,
        doutb     => FM_AAAA_L1PHID_V_dout,
        sync_nent => FM_AAAA_L1PHID_start,
        nent_o    => FM_AAAA_L1PHID_AV_dout_nent
      );

    FM_AAAA_L1PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHID_wea,
        addra     => FM_AAAA_L1PHID_writeaddr,
        dina      => FM_AAAA_L1PHID_din,
        wea_out       => FM_AAAA_L1PHID_wea_delay,
        addra_out     => FM_AAAA_L1PHID_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHID_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHID_start
      );

    FM_AAAA_L1PHIE : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIE",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIE_wea_delay,
        addra     => FM_AAAA_L1PHIE_writeaddr_delay,
        dina      => FM_AAAA_L1PHIE_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIE_V_readaddr,
        doutb     => FM_AAAA_L1PHIE_V_dout,
        sync_nent => FM_AAAA_L1PHIE_start,
        nent_o    => FM_AAAA_L1PHIE_AV_dout_nent
      );

    FM_AAAA_L1PHIE_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIE_wea,
        addra     => FM_AAAA_L1PHIE_writeaddr,
        dina      => FM_AAAA_L1PHIE_din,
        wea_out       => FM_AAAA_L1PHIE_wea_delay,
        addra_out     => FM_AAAA_L1PHIE_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIE_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIE_start
      );

    FM_AAAA_L1PHIF : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIF",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIF_wea_delay,
        addra     => FM_AAAA_L1PHIF_writeaddr_delay,
        dina      => FM_AAAA_L1PHIF_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIF_V_readaddr,
        doutb     => FM_AAAA_L1PHIF_V_dout,
        sync_nent => FM_AAAA_L1PHIF_start,
        nent_o    => FM_AAAA_L1PHIF_AV_dout_nent
      );

    FM_AAAA_L1PHIF_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIF_wea,
        addra     => FM_AAAA_L1PHIF_writeaddr,
        dina      => FM_AAAA_L1PHIF_din,
        wea_out       => FM_AAAA_L1PHIF_wea_delay,
        addra_out     => FM_AAAA_L1PHIF_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIF_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIF_start
      );

    FM_AAAA_L1PHIG : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIG",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIG_wea_delay,
        addra     => FM_AAAA_L1PHIG_writeaddr_delay,
        dina      => FM_AAAA_L1PHIG_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIG_V_readaddr,
        doutb     => FM_AAAA_L1PHIG_V_dout,
        sync_nent => FM_AAAA_L1PHIG_start,
        nent_o    => FM_AAAA_L1PHIG_AV_dout_nent
      );

    FM_AAAA_L1PHIG_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIG_wea,
        addra     => FM_AAAA_L1PHIG_writeaddr,
        dina      => FM_AAAA_L1PHIG_din,
        wea_out       => FM_AAAA_L1PHIG_wea_delay,
        addra_out     => FM_AAAA_L1PHIG_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIG_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIG_start
      );

    FM_AAAA_L1PHIH : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L1PHIH",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L1PHIH_wea_delay,
        addra     => FM_AAAA_L1PHIH_writeaddr_delay,
        dina      => FM_AAAA_L1PHIH_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L1PHIH_V_readaddr,
        doutb     => FM_AAAA_L1PHIH_V_dout,
        sync_nent => FM_AAAA_L1PHIH_start,
        nent_o    => FM_AAAA_L1PHIH_AV_dout_nent
      );

    FM_AAAA_L1PHIH_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L1PHIH_wea,
        addra     => FM_AAAA_L1PHIH_writeaddr,
        dina      => FM_AAAA_L1PHIH_din,
        wea_out       => FM_AAAA_L1PHIH_wea_delay,
        addra_out     => FM_AAAA_L1PHIH_writeaddr_delay,
        dina_out      => FM_AAAA_L1PHIH_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L1PHIH_start
      );

    FM_AAAA_L2PHIA : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L2PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L2PHIA_wea_delay,
        addra     => FM_AAAA_L2PHIA_writeaddr_delay,
        dina      => FM_AAAA_L2PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L2PHIA_V_readaddr,
        doutb     => FM_AAAA_L2PHIA_V_dout,
        sync_nent => FM_AAAA_L2PHIA_start,
        nent_o    => FM_AAAA_L2PHIA_AV_dout_nent
      );

    FM_AAAA_L2PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L2PHIA_wea,
        addra     => FM_AAAA_L2PHIA_writeaddr,
        dina      => FM_AAAA_L2PHIA_din,
        wea_out       => FM_AAAA_L2PHIA_wea_delay,
        addra_out     => FM_AAAA_L2PHIA_writeaddr_delay,
        dina_out      => FM_AAAA_L2PHIA_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L2PHIA_start
      );

    FM_AAAA_L2PHIB : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L2PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L2PHIB_wea_delay,
        addra     => FM_AAAA_L2PHIB_writeaddr_delay,
        dina      => FM_AAAA_L2PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L2PHIB_V_readaddr,
        doutb     => FM_AAAA_L2PHIB_V_dout,
        sync_nent => FM_AAAA_L2PHIB_start,
        nent_o    => FM_AAAA_L2PHIB_AV_dout_nent
      );

    FM_AAAA_L2PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L2PHIB_wea,
        addra     => FM_AAAA_L2PHIB_writeaddr,
        dina      => FM_AAAA_L2PHIB_din,
        wea_out       => FM_AAAA_L2PHIB_wea_delay,
        addra_out     => FM_AAAA_L2PHIB_writeaddr_delay,
        dina_out      => FM_AAAA_L2PHIB_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L2PHIB_start
      );

    FM_AAAA_L2PHIC : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L2PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L2PHIC_wea_delay,
        addra     => FM_AAAA_L2PHIC_writeaddr_delay,
        dina      => FM_AAAA_L2PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L2PHIC_V_readaddr,
        doutb     => FM_AAAA_L2PHIC_V_dout,
        sync_nent => FM_AAAA_L2PHIC_start,
        nent_o    => FM_AAAA_L2PHIC_AV_dout_nent
      );

    FM_AAAA_L2PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L2PHIC_wea,
        addra     => FM_AAAA_L2PHIC_writeaddr,
        dina      => FM_AAAA_L2PHIC_din,
        wea_out       => FM_AAAA_L2PHIC_wea_delay,
        addra_out     => FM_AAAA_L2PHIC_writeaddr_delay,
        dina_out      => FM_AAAA_L2PHIC_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L2PHIC_start
      );

    FM_AAAA_L2PHID : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L2PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L2PHID_wea_delay,
        addra     => FM_AAAA_L2PHID_writeaddr_delay,
        dina      => FM_AAAA_L2PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L2PHID_V_readaddr,
        doutb     => FM_AAAA_L2PHID_V_dout,
        sync_nent => FM_AAAA_L2PHID_start,
        nent_o    => FM_AAAA_L2PHID_AV_dout_nent
      );

    FM_AAAA_L2PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L2PHID_wea,
        addra     => FM_AAAA_L2PHID_writeaddr,
        dina      => FM_AAAA_L2PHID_din,
        wea_out       => FM_AAAA_L2PHID_wea_delay,
        addra_out     => FM_AAAA_L2PHID_writeaddr_delay,
        dina_out      => FM_AAAA_L2PHID_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L2PHID_start
      );

    FM_AAAA_L3PHIA : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L3PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L3PHIA_wea_delay,
        addra     => FM_AAAA_L3PHIA_writeaddr_delay,
        dina      => FM_AAAA_L3PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L3PHIA_V_readaddr,
        doutb     => FM_AAAA_L3PHIA_V_dout,
        sync_nent => FM_AAAA_L3PHIA_start,
        nent_o    => FM_AAAA_L3PHIA_AV_dout_nent
      );

    FM_AAAA_L3PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L3PHIA_wea,
        addra     => FM_AAAA_L3PHIA_writeaddr,
        dina      => FM_AAAA_L3PHIA_din,
        wea_out       => FM_AAAA_L3PHIA_wea_delay,
        addra_out     => FM_AAAA_L3PHIA_writeaddr_delay,
        dina_out      => FM_AAAA_L3PHIA_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L3PHIA_start
      );

    FM_AAAA_L3PHIB : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L3PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L3PHIB_wea_delay,
        addra     => FM_AAAA_L3PHIB_writeaddr_delay,
        dina      => FM_AAAA_L3PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L3PHIB_V_readaddr,
        doutb     => FM_AAAA_L3PHIB_V_dout,
        sync_nent => FM_AAAA_L3PHIB_start,
        nent_o    => FM_AAAA_L3PHIB_AV_dout_nent
      );

    FM_AAAA_L3PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L3PHIB_wea,
        addra     => FM_AAAA_L3PHIB_writeaddr,
        dina      => FM_AAAA_L3PHIB_din,
        wea_out       => FM_AAAA_L3PHIB_wea_delay,
        addra_out     => FM_AAAA_L3PHIB_writeaddr_delay,
        dina_out      => FM_AAAA_L3PHIB_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L3PHIB_start
      );

    FM_AAAA_L3PHIC : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L3PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L3PHIC_wea_delay,
        addra     => FM_AAAA_L3PHIC_writeaddr_delay,
        dina      => FM_AAAA_L3PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L3PHIC_V_readaddr,
        doutb     => FM_AAAA_L3PHIC_V_dout,
        sync_nent => FM_AAAA_L3PHIC_start,
        nent_o    => FM_AAAA_L3PHIC_AV_dout_nent
      );

    FM_AAAA_L3PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L3PHIC_wea,
        addra     => FM_AAAA_L3PHIC_writeaddr,
        dina      => FM_AAAA_L3PHIC_din,
        wea_out       => FM_AAAA_L3PHIC_wea_delay,
        addra_out     => FM_AAAA_L3PHIC_writeaddr_delay,
        dina_out      => FM_AAAA_L3PHIC_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L3PHIC_start
      );

    FM_AAAA_L3PHID : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L3PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L3PHID_wea_delay,
        addra     => FM_AAAA_L3PHID_writeaddr_delay,
        dina      => FM_AAAA_L3PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L3PHID_V_readaddr,
        doutb     => FM_AAAA_L3PHID_V_dout,
        sync_nent => FM_AAAA_L3PHID_start,
        nent_o    => FM_AAAA_L3PHID_AV_dout_nent
      );

    FM_AAAA_L3PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L3PHID_wea,
        addra     => FM_AAAA_L3PHID_writeaddr,
        dina      => FM_AAAA_L3PHID_din,
        wea_out       => FM_AAAA_L3PHID_wea_delay,
        addra_out     => FM_AAAA_L3PHID_writeaddr_delay,
        dina_out      => FM_AAAA_L3PHID_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L3PHID_start
      );

    FM_AAAA_L4PHIA : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L4PHIA",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L4PHIA_wea_delay,
        addra     => FM_AAAA_L4PHIA_writeaddr_delay,
        dina      => FM_AAAA_L4PHIA_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L4PHIA_V_readaddr,
        doutb     => FM_AAAA_L4PHIA_V_dout,
        sync_nent => FM_AAAA_L4PHIA_start,
        nent_o    => FM_AAAA_L4PHIA_AV_dout_nent
      );

    FM_AAAA_L4PHIA_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L4PHIA_wea,
        addra     => FM_AAAA_L4PHIA_writeaddr,
        dina      => FM_AAAA_L4PHIA_din,
        wea_out       => FM_AAAA_L4PHIA_wea_delay,
        addra_out     => FM_AAAA_L4PHIA_writeaddr_delay,
        dina_out      => FM_AAAA_L4PHIA_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L4PHIA_start
      );

    FM_AAAA_L4PHIB : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L4PHIB",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L4PHIB_wea_delay,
        addra     => FM_AAAA_L4PHIB_writeaddr_delay,
        dina      => FM_AAAA_L4PHIB_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L4PHIB_V_readaddr,
        doutb     => FM_AAAA_L4PHIB_V_dout,
        sync_nent => FM_AAAA_L4PHIB_start,
        nent_o    => FM_AAAA_L4PHIB_AV_dout_nent
      );

    FM_AAAA_L4PHIB_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L4PHIB_wea,
        addra     => FM_AAAA_L4PHIB_writeaddr,
        dina      => FM_AAAA_L4PHIB_din,
        wea_out       => FM_AAAA_L4PHIB_wea_delay,
        addra_out     => FM_AAAA_L4PHIB_writeaddr_delay,
        dina_out      => FM_AAAA_L4PHIB_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L4PHIB_start
      );

    FM_AAAA_L4PHIC : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L4PHIC",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L4PHIC_wea_delay,
        addra     => FM_AAAA_L4PHIC_writeaddr_delay,
        dina      => FM_AAAA_L4PHIC_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L4PHIC_V_readaddr,
        doutb     => FM_AAAA_L4PHIC_V_dout,
        sync_nent => FM_AAAA_L4PHIC_start,
        nent_o    => FM_AAAA_L4PHIC_AV_dout_nent
      );

    FM_AAAA_L4PHIC_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L4PHIC_wea,
        addra     => FM_AAAA_L4PHIC_writeaddr,
        dina      => FM_AAAA_L4PHIC_din,
        wea_out       => FM_AAAA_L4PHIC_wea_delay,
        addra_out     => FM_AAAA_L4PHIC_writeaddr_delay,
        dina_out      => FM_AAAA_L4PHIC_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L4PHIC_start
      );

    FM_AAAA_L4PHID : entity work.tf_mem
      generic map (
        RAM_WIDTH       => 52,
        NUM_PAGES       => 2,
        INIT_FILE       => "",
        INIT_HEX        => true,
        RAM_PERFORMANCE => "HIGH_PERFORMANCE",
        NAME            => "FM_AAAA_L4PHID",
        FILE_WRITE            => true
      )
      port map (
        clka      => clk240,
        wea       => FM_AAAA_L4PHID_wea_delay,
        addra     => FM_AAAA_L4PHID_writeaddr_delay,
        dina      => FM_AAAA_L4PHID_din_delay,
        clkb      => clk240,
        rsta      => reset,
        rstb      => '0',
        enb       => '1',
        addrb     => FM_AAAA_L4PHID_V_readaddr,
        doutb     => FM_AAAA_L4PHID_V_dout,
        sync_nent => FM_AAAA_L4PHID_start,
        nent_o    => FM_AAAA_L4PHID_AV_dout_nent
      );

    FM_AAAA_L4PHID_DELAY : entity work.tf_pipeline_slr_xing
      generic map (
        NUM_PAGES       => 2,
        RAM_WIDTH       => 52
      )
      port map (
        clk      => clk240,
        reset    => reset,
        wea       => FM_AAAA_L4PHID_wea,
        addra     => FM_AAAA_L4PHID_writeaddr,
        dina      => FM_AAAA_L4PHID_din,
        wea_out       => FM_AAAA_L4PHID_wea_delay,
        addra_out     => FM_AAAA_L4PHID_writeaddr_delay,
        dina_out      => FM_AAAA_L4PHID_din_delay,
        done       => MP_done,
        start      => FM_AAAA_L4PHID_start
      );

  -- ######## Legacy mem_reader
  -- VMSMER_L1PHIA_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIA_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIA_bx_in,
  --     start => VMSMER_L1PHIA_start,
  --     enb   => AS_L1PHIAin_enb,
  --     addra => AS_L1PHIAin_V_readaddr,
  --     din   => AS_L1PHIAin_V_dout,
  --     dout  => AS_L1PHIAin_V_as,
  --     valid  => AS_L1PHIAin_valid,
  --     index  => AS_L1PHIAin_index(6 downto 0),
  --     nent  => AS_L1PHIAin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIA: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIA_bx_in,
  --     start => VMSMER_L1PHIA_start
  -- );

  LATCH_VMSMER_L1PHIA_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,  -- in port
      bx => VMSMER_L1PHIA_bx  -- needed later, so keep
  );

-- ####### Legacy VMSMER_L1PHIA ######

  -- VMSMER_L1PHIA : entity work.VMSMER_L1PHIA
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIA_bx,
  --     valid        => AS_L1PHIAin_valid,
  --     index        => AS_L1PHIAin_index,
  --     allStub_data_V        => AS_L1PHIAin_V_as,  -- legacy data
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIAn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIAn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIAn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIAn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIAn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIAn2_din
  -- );

-- ####### New VMSMER_L1PHIA #######
  VMSMER_L1PHIA_FIFO : entity work.VMSMER_L1PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIA_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIAin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIAin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIAn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIAn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIAn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIAn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIAn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIAn2_din   -- same as legacy, used later
  );



-- ####### Legacy VMSMER_L1PHIB ######
  -- VMSMER_L1PHIB_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIB_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIB_bx_in,
  --     start => VMSMER_L1PHIB_start,
  --     enb   => AS_L1PHIBin_enb,
  --     addra => AS_L1PHIBin_V_readaddr,
  --     din   => AS_L1PHIBin_V_dout,
  --     dout  => AS_L1PHIBin_V_as,
  --     valid  => AS_L1PHIBin_valid,
  --     index  => AS_L1PHIBin_index(6 downto 0),
  --     nent  => AS_L1PHIBin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIB: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIB_bx_in,
  --     start => VMSMER_L1PHIB_start
  -- );

  LATCH_VMSMER_L1PHIB_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIB_bx
  );

  -- VMSMER_L1PHIB : entity work.VMSMER_L1PHIB
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIB_bx,
  --     valid        => AS_L1PHIBin_valid,
  --     index        => AS_L1PHIBin_index,
  --     allStub_data_V        => AS_L1PHIBin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIBn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIBn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIBn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIBn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIBn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIBn2_din
  -- );

  -- ####### New VMSMER #######
  VMSMER_L1PHIB_FIFO : entity work.VMSMER_L1PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIB_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIBin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIBin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIBn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIBn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIBn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIBn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIBn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIBn2_din   -- same as legacy, used later
  );

  -- ######## Legacy mem_reader
  -- VMSMER_L1PHIC_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIC_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIC_bx_in,
  --     start => VMSMER_L1PHIC_start,
  --     enb   => AS_L1PHICin_enb,
  --     addra => AS_L1PHICin_V_readaddr,
  --     din   => AS_L1PHICin_V_dout,
  --     dout  => AS_L1PHICin_V_as,
  --     valid  => AS_L1PHICin_valid,
  --     index  => AS_L1PHICin_index(6 downto 0),
  --     nent  => AS_L1PHICin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIC: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIC_bx_in,
  --     start => VMSMER_L1PHIC_start
  -- );

  LATCH_VMSMER_L1PHIC_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIC_bx
  );

  -- VMSMER_L1PHIC : entity work.VMSMER_L1PHIC
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIC_bx,
  --     valid        => AS_L1PHICin_valid,
  --     index        => AS_L1PHICin_index,
  --     allStub_data_V        => AS_L1PHICin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHICn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHICn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHICn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHICn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHICn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHICn2_din
  -- );

  -- ####### New VMSMER #######
  VMSMER_L1PHIC_FIFO : entity work.VMSMER_L1PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIC_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHICin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHICin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHICn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHICn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHICn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHICn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHICn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHICn2_din   -- same as legacy, used later
  );

  -- ######## Legacy mem_reader
  -- VMSMER_L1PHID_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHID_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHID_bx_in,
  --     start => VMSMER_L1PHID_start,
  --     enb   => AS_L1PHIDin_enb,
  --     addra => AS_L1PHIDin_V_readaddr,
  --     din   => AS_L1PHIDin_V_dout,
  --     dout  => AS_L1PHIDin_V_as,
  --     valid  => AS_L1PHIDin_valid,
  --     index  => AS_L1PHIDin_index(6 downto 0),
  --     nent  => AS_L1PHIDin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHID: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHID_bx_in,
  --     start => VMSMER_L1PHID_start
  -- );

  LATCH_VMSMER_L1PHID_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHID_bx
  );

  -- VMSMER_L1PHID : entity work.VMSMER_L1PHID
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHID_bx,
  --     valid        => AS_L1PHIDin_valid,
  --     index        => AS_L1PHIDin_index,
  --     allStub_data_V        => AS_L1PHIDin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIDn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIDn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIDn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIDn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIDn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIDn2_din
  -- );


-- ####### New VMSMER #######
  VMSMER_L1PHID_FIFO : entity work.VMSMER_L1PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHID_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIDin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIDin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIDn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIDn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIDn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIDn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIDn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIDn2_din   -- same as legacy, used later
  );

  -- VMSMER_L1PHIE_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIE_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIE_bx_in,
  --     start => VMSMER_L1PHIE_start,
  --     enb   => AS_L1PHIEin_enb,
  --     addra => AS_L1PHIEin_V_readaddr,
  --     din   => AS_L1PHIEin_V_dout,
  --     dout  => AS_L1PHIEin_V_as,
  --     valid  => AS_L1PHIEin_valid,
  --     index  => AS_L1PHIEin_index(6 downto 0),
  --     nent  => AS_L1PHIEin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIE: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIE_bx_in,
  --     start => VMSMER_L1PHIE_start
  -- );

  LATCH_VMSMER_L1PHIE_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIE_bx
  );

  -- VMSMER_L1PHIE : entity work.VMSMER_L1PHIE
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIE_bx,
  --     valid        => AS_L1PHIEin_valid,
  --     index        => AS_L1PHIEin_index,
  --     allStub_data_V        => AS_L1PHIEin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIEn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIEn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIEn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIEn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIEn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIEn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L1PHIE_FIFO : entity work.VMSMER_L1PHIE
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIE_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIEin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIEin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIEn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIEn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIEn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIEn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIEn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIEn2_din   -- same as legacy, used later
  );


  -- VMSMER_L1PHIF_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIF_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIF_bx_in,
  --     start => VMSMER_L1PHIF_start,
  --     enb   => AS_L1PHIFin_enb,
  --     addra => AS_L1PHIFin_V_readaddr,
  --     din   => AS_L1PHIFin_V_dout,
  --     dout  => AS_L1PHIFin_V_as,
  --     valid  => AS_L1PHIFin_valid,
  --     index  => AS_L1PHIFin_index(6 downto 0),
  --     nent  => AS_L1PHIFin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIF: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIF_bx_in,
  --     start => VMSMER_L1PHIF_start
  -- );

  LATCH_VMSMER_L1PHIF_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIF_bx
  );

  -- VMSMER_L1PHIF : entity work.VMSMER_L1PHIF
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIF_bx,
  --     valid        => AS_L1PHIFin_valid,
  --     index        => AS_L1PHIFin_index,
  --     allStub_data_V        => AS_L1PHIFin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIFn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIFn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIFn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIFn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIFn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIFn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L1PHIF_FIFO : entity work.VMSMER_L1PHIF
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIF_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIFin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIFin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIFn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIFn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIFn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIFn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIFn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIFn2_din   -- same as legacy, used later
  );

  -- VMSMER_L1PHIG_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIG_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIG_bx_in,
  --     start => VMSMER_L1PHIG_start,
  --     enb   => AS_L1PHIGin_enb,
  --     addra => AS_L1PHIGin_V_readaddr,
  --     din   => AS_L1PHIGin_V_dout,
  --     dout  => AS_L1PHIGin_V_as,
  --     valid  => AS_L1PHIGin_valid,
  --     index  => AS_L1PHIGin_index(6 downto 0),
  --     nent  => AS_L1PHIGin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIG: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIG_bx_in,
  --     start => VMSMER_L1PHIG_start
  -- );

  LATCH_VMSMER_L1PHIG_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIG_bx
  );

  -- VMSMER_L1PHIG : entity work.VMSMER_L1PHIG
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIG_bx,
  --     valid        => AS_L1PHIGin_valid,
  --     index        => AS_L1PHIGin_index,
  --     allStub_data_V        => AS_L1PHIGin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIGn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIGn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIGn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIGn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIGn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIGn2_din
  -- );

  -- ####### New VMSMER #######
  VMSMER_L1PHIG_FIFO : entity work.VMSMER_L1PHIG
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIG_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIGin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIGin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIGn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIGn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIGn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIGn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIGn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIGn2_din   -- same as legacy, used later
  );

  -- VMSMER_L1PHIH_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L1PHIH_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L1PHIH_bx_in,
  --     start => VMSMER_L1PHIH_start,
  --     enb   => AS_L1PHIHin_enb,
  --     addra => AS_L1PHIHin_V_readaddr,
  --     din   => AS_L1PHIHin_V_dout,
  --     dout  => AS_L1PHIHin_V_as,
  --     valid  => AS_L1PHIHin_valid,
  --     index  => AS_L1PHIHin_index(6 downto 0),
  --     nent  => AS_L1PHIHin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L1PHIH: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L1PHIH_bx_in,
  --     start => VMSMER_L1PHIH_start
  -- );

  LATCH_VMSMER_L1PHIH_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L1PHIH_bx
  );

  -- VMSMER_L1PHIH : entity work.VMSMER_L1PHIH
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L1PHIH_bx,
  --     valid        => AS_L1PHIHin_valid,
  --     index        => AS_L1PHIHin_index,
  --     allStub_data_V        => AS_L1PHIHin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIHn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIHn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIHn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIHn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIHn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIHn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L1PHIH_FIFO : entity work.VMSMER_L1PHIH
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L1PHIH_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L1PHIHin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L1PHIHin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L1PHIHn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L1PHIHn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L1PHIHn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L1PHIHn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L1PHIHn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L1PHIHn2_din   -- same as legacy, used later
  );

  -- VMSMER_L2PHIA_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L2PHIA_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L2PHIA_bx_in,
  --     start => VMSMER_L2PHIA_start,
  --     enb   => AS_L2PHIAin_enb,
  --     addra => AS_L2PHIAin_V_readaddr,
  --     din   => AS_L2PHIAin_V_dout,
  --     dout  => AS_L2PHIAin_V_as,
  --     valid  => AS_L2PHIAin_valid,
  --     index  => AS_L2PHIAin_index(6 downto 0),
  --     nent  => AS_L2PHIAin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L2PHIA: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L2PHIA_bx_in,
  --     start => VMSMER_L2PHIA_start
  -- );

  LATCH_VMSMER_L2PHIA_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L2PHIA_bx
  );

  -- VMSMER_L2PHIA : entity work.VMSMER_L2PHIA
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L2PHIA_bx,
  --     valid        => AS_L2PHIAin_valid,
  --     index        => AS_L2PHIAin_index,
  --     allStub_data_V        => AS_L2PHIAin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIAn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIAn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIAn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIAn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIAn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIAn2_din
  -- );


-- ####### New VMSMER #######
  VMSMER_L2PHIA_FIFO : entity work.VMSMER_L2PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L2PHIA_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L2PHIAin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L2PHIAin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIAn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIAn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIAn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIAn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIAn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIAn2_din   -- same as legacy, used later
  );

  -- VMSMER_L2PHIB_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L2PHIB_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L2PHIB_bx_in,
  --     start => VMSMER_L2PHIB_start,
  --     enb   => AS_L2PHIBin_enb,
  --     addra => AS_L2PHIBin_V_readaddr,
  --     din   => AS_L2PHIBin_V_dout,
  --     dout  => AS_L2PHIBin_V_as,
  --     valid  => AS_L2PHIBin_valid,
  --     index  => AS_L2PHIBin_index(6 downto 0),
  --     nent  => AS_L2PHIBin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L2PHIB: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L2PHIB_bx_in,
  --     start => VMSMER_L2PHIB_start
  -- );

  LATCH_VMSMER_L2PHIB_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L2PHIB_bx
  );

  -- VMSMER_L2PHIB : entity work.VMSMER_L2PHIB
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L2PHIB_bx,
  --     valid        => AS_L2PHIBin_valid,
  --     index        => AS_L2PHIBin_index,
  --     allStub_data_V        => AS_L2PHIBin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIBn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIBn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIBn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIBn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIBn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIBn2_din
  -- );


-- ####### New VMSMER #######
  VMSMER_L2PHIB_FIFO : entity work.VMSMER_L2PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L2PHIB_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L2PHIBin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L2PHIBin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIBn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIBn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIBn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIBn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIBn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIBn2_din   -- same as legacy, used later
  );


  -- VMSMER_L2PHIC_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L2PHIC_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L2PHIC_bx_in,
  --     start => VMSMER_L2PHIC_start,
  --     enb   => AS_L2PHICin_enb,
  --     addra => AS_L2PHICin_V_readaddr,
  --     din   => AS_L2PHICin_V_dout,
  --     dout  => AS_L2PHICin_V_as,
  --     valid  => AS_L2PHICin_valid,
  --     index  => AS_L2PHICin_index(6 downto 0),
  --     nent  => AS_L2PHICin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L2PHIC: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L2PHIC_bx_in,
  --     start => VMSMER_L2PHIC_start
  -- );

  LATCH_VMSMER_L2PHIC_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L2PHIC_bx
  );

  -- VMSMER_L2PHIC : entity work.VMSMER_L2PHIC
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L2PHIC_bx,
  --     valid        => AS_L2PHICin_valid,
  --     index        => AS_L2PHICin_index,
  --     allStub_data_V        => AS_L2PHICin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHICn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHICn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHICn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L2PHICn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L2PHICn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L2PHICn2_din
  -- );

  -- ####### New VMSMER #######
  VMSMER_L2PHIC_FIFO : entity work.VMSMER_L2PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L2PHIC_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L2PHICin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L2PHICin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHICn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHICn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHICn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L2PHICn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L2PHICn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L2PHICn2_din   -- same as legacy, used later
  );

  -- VMSMER_L2PHID_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L2PHID_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L2PHID_bx_in,
  --     start => VMSMER_L2PHID_start,
  --     enb   => AS_L2PHIDin_enb,
  --     addra => AS_L2PHIDin_V_readaddr,
  --     din   => AS_L2PHIDin_V_dout,
  --     dout  => AS_L2PHIDin_V_as,
  --     valid  => AS_L2PHIDin_valid,
  --     index  => AS_L2PHIDin_index(6 downto 0),
  --     nent  => AS_L2PHIDin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L2PHID: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L2PHID_bx_in,
  --     start => VMSMER_L2PHID_start
  -- );

  LATCH_VMSMER_L2PHID_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L2PHID_bx
  );

  -- VMSMER_L2PHID : entity work.VMSMER_L2PHID
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L2PHID_bx,
  --     valid        => AS_L2PHIDin_valid,
  --     index        => AS_L2PHIDin_index,
  --     allStub_data_V        => AS_L2PHIDin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIDn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIDn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIDn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIDn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIDn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIDn2_din
  -- );


-- ####### New VMSMER #######
  VMSMER_L2PHID_FIFO : entity work.VMSMER_L2PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L2PHID_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L2PHIDin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L2PHIDin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L2PHIDn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L2PHIDn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L2PHIdn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L2PHIDn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L2PHIDn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L2PHIDn2_din   -- same as legacy, used later
  );


  -- VMSMER_L3PHIA_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L3PHIA_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L3PHIA_bx_in,
  --     start => VMSMER_L3PHIA_start,
  --     enb   => AS_L3PHIAin_enb,
  --     addra => AS_L3PHIAin_V_readaddr,
  --     din   => AS_L3PHIAin_V_dout,
  --     dout  => AS_L3PHIAin_V_as,
  --     valid  => AS_L3PHIAin_valid,
  --     index  => AS_L3PHIAin_index(6 downto 0),
  --     nent  => AS_L3PHIAin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L3PHIA: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L3PHIA_bx_in,
  --     start => VMSMER_L3PHIA_start
  -- );

  LATCH_VMSMER_L3PHIA_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L3PHIA_bx
  );

  -- VMSMER_L3PHIA : entity work.VMSMER_L3PHIA
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L3PHIA_bx,
  --     valid        => AS_L3PHIAin_valid,
  --     index        => AS_L3PHIAin_index,
  --     allStub_data_V        => AS_L3PHIAin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIAn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIAn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIAn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIAn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIAn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIAn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L3PHIA_FIFO : entity work.VMSMER_L3PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L3PHIA_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L3PHIAin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L3PHIAin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIAn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIAn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIAn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIAn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIAn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIAn2_din   -- same as legacy, used later
  );

  -- VMSMER_L3PHIB_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L3PHIB_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L3PHIB_bx_in,
  --     start => VMSMER_L3PHIB_start,
  --     enb   => AS_L3PHIBin_enb,
  --     addra => AS_L3PHIBin_V_readaddr,
  --     din   => AS_L3PHIBin_V_dout,
  --     dout  => AS_L3PHIBin_V_as,
  --     valid  => AS_L3PHIBin_valid,
  --     index  => AS_L3PHIBin_index(6 downto 0),
  --     nent  => AS_L3PHIBin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L3PHIB: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L3PHIB_bx_in,
  --     start => VMSMER_L3PHIB_start
  -- );

  LATCH_VMSMER_L3PHIB_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L3PHIB_bx
  );

  -- VMSMER_L3PHIB : entity work.VMSMER_L3PHIB
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L3PHIB_bx,
  --     valid        => AS_L3PHIBin_valid,
  --     index        => AS_L3PHIBin_index,
  --     allStub_data_V        => AS_L3PHIBin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIBn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIBn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIBn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIBn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIBn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIBn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L3PHIB_FIFO : entity work.VMSMER_L3PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L3PHIB_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L3PHIBin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L3PHIBin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIBn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIBn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIBn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIBn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIBn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIBn2_din   -- same as legacy, used later
  );
  


  -- VMSMER_L3PHIC_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L3PHIC_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L3PHIC_bx_in,
  --     start => VMSMER_L3PHIC_start,
  --     enb   => AS_L3PHICin_enb,
  --     addra => AS_L3PHICin_V_readaddr,
  --     din   => AS_L3PHICin_V_dout,
  --     dout  => AS_L3PHICin_V_as,
  --     valid  => AS_L3PHICin_valid,
  --     index  => AS_L3PHICin_index(6 downto 0),
  --     nent  => AS_L3PHICin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L3PHIC: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L3PHIC_bx_in,
  --     start => VMSMER_L3PHIC_start
  -- );

  LATCH_VMSMER_L3PHIC_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L3PHIC_bx
  );

  -- VMSMER_L3PHIC : entity work.VMSMER_L3PHIC
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L3PHIC_bx,
  --     valid        => AS_L3PHICin_valid,
  --     index        => AS_L3PHICin_index,
  --     allStub_data_V        => AS_L3PHICin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHICn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHICn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHICn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L3PHICn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L3PHICn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L3PHICn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L3PHIC_FIFO : entity work.VMSMER_L3PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L3PHIC_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L3PHICin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L3PHICin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHICn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHICn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHICn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L3PHICn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L3PHICn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L3PHICn2_din   -- same as legacy, used later
  );
  


  -- VMSMER_L3PHID_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L3PHID_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L3PHID_bx_in,
  --     start => VMSMER_L3PHID_start,
  --     enb   => AS_L3PHIDin_enb,
  --     addra => AS_L3PHIDin_V_readaddr,
  --     din   => AS_L3PHIDin_V_dout,
  --     dout  => AS_L3PHIDin_V_as,
  --     valid  => AS_L3PHIDin_valid,
  --     index  => AS_L3PHIDin_index(6 downto 0),
  --     nent  => AS_L3PHIDin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L3PHID: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L3PHID_bx_in,
  --     start => VMSMER_L3PHID_start
  -- );

  LATCH_VMSMER_L3PHID_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L3PHID_bx
  );

  -- VMSMER_L3PHID : entity work.VMSMER_L3PHID
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L3PHID_bx,
  --     valid        => AS_L3PHIDin_valid,
  --     index        => AS_L3PHIDin_index,
  --     allStub_data_V        => AS_L3PHIDin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIDn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIDn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIDn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIDn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIDn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIDn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L3PHID_FIFO : entity work.VMSMER_L3PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L3PHID_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L3PHIDin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L3PHIDin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L3PHIDn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L3PHIDn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L3PHIDn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L3PHIDn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L3PHIDn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L3PHIDn2_din   -- same as legacy, used later
  );
  


  -- VMSMER_L4PHIA_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L4PHIA_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L4PHIA_bx_in,
  --     start => VMSMER_L4PHIA_start,
  --     enb   => AS_L4PHIAin_enb,
  --     addra => AS_L4PHIAin_V_readaddr,
  --     din   => AS_L4PHIAin_V_dout,
  --     dout  => AS_L4PHIAin_V_as,
  --     valid  => AS_L4PHIAin_valid,
  --     index  => AS_L4PHIAin_index(6 downto 0),
  --     nent  => AS_L4PHIAin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L4PHIA: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L4PHIA_bx_in,
  --     start => VMSMER_L4PHIA_start
  -- );

  LATCH_VMSMER_L4PHIA_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L4PHIA_bx
  );

  -- VMSMER_L4PHIA : entity work.VMSMER_L4PHIA
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L4PHIA_bx,
  --     valid        => AS_L4PHIAin_valid,
  --     index        => AS_L4PHIAin_index,
  --     allStub_data_V        => AS_L4PHIAin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIAn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIAn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIAn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIAn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIAn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIAn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L4PHIA_FIFO : entity work.VMSMER_L4PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L4PHIA_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L4PHIAin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L4PHIAin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIAn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIAn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIAn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIAn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIAn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIAn2_din   -- same as legacy, used later
  );
  

  -- VMSMER_L4PHIB_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L4PHIB_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L4PHIB_bx_in,
  --     start => VMSMER_L4PHIB_start,
  --     enb   => AS_L4PHIBin_enb,
  --     addra => AS_L4PHIBin_V_readaddr,
  --     din   => AS_L4PHIBin_V_dout,
  --     dout  => AS_L4PHIBin_V_as,
  --     valid  => AS_L4PHIBin_valid,
  --     index  => AS_L4PHIBin_index(6 downto 0),
  --     nent  => AS_L4PHIBin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L4PHIB: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L4PHIB_bx_in,
  --     start => VMSMER_L4PHIB_start
  -- );

  LATCH_VMSMER_L4PHIB_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L4PHIB_bx
  );

  -- VMSMER_L4PHIB : entity work.VMSMER_L4PHIB
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L4PHIB_bx,
  --     valid        => AS_L4PHIBin_valid,
  --     index        => AS_L4PHIBin_index,
  --     allStub_data_V        => AS_L4PHIBin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIBn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIBn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIBn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIBn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIBn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIBn2_din
  -- );


-- ####### New VMSMER #######
  VMSMER_L4PHIB_FIFO : entity work.VMSMER_L4PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L4PHIB_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L4PHIBin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L4PHIBin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIBn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIBn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIBn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIBn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIBn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIBn2_din   -- same as legacy, used later
  );
  
  -- VMSMER_L4PHIC_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L4PHIC_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L4PHIC_bx_in,
  --     start => VMSMER_L4PHIC_start,
  --     enb   => AS_L4PHICin_enb,
  --     addra => AS_L4PHICin_V_readaddr,
  --     din   => AS_L4PHICin_V_dout,
  --     dout  => AS_L4PHICin_V_as,
  --     valid  => AS_L4PHICin_valid,
  --     index  => AS_L4PHICin_index(6 downto 0),
  --     nent  => AS_L4PHICin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L4PHIC: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L4PHIC_bx_in,
  --     start => VMSMER_L4PHIC_start
  -- );

  LATCH_VMSMER_L4PHIC_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L4PHIC_bx
  );

  -- VMSMER_L4PHIC : entity work.VMSMER_L4PHIC
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L4PHIC_bx,
  --     valid        => AS_L4PHICin_valid,
  --     index        => AS_L4PHICin_index,
  --     allStub_data_V        => AS_L4PHICin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHICn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHICn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHICn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L4PHICn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L4PHICn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L4PHICn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L4PHIC_FIFO : entity work.VMSMER_L4PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L4PHIC_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L4PHICin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L4PHICin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHICn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHICn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHICn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L4PHICn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L4PHICn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L4PHICn2_din   -- same as legacy, used later
  );
  
  -- VMSMER_L4PHID_mem_reader : entity work.mem_reader
  --   generic map (
  --     RAM_WIDTH    => 36,
  --     NAME    => "VMSMER_L4PHID_mem_reader"
  --   )
  --   port map (
  --     clk    => clk240,
  --     bx    => VMSMER_L4PHID_bx_in,
  --     start => VMSMER_L4PHID_start,
  --     enb   => AS_L4PHIDin_enb,
  --     addra => AS_L4PHIDin_V_readaddr,
  --     din   => AS_L4PHIDin_V_dout,
  --     dout  => AS_L4PHIDin_V_as,
  --     valid  => AS_L4PHIDin_valid,
  --     index  => AS_L4PHIDin_index(6 downto 0),
  --     nent  => AS_L4PHIDin_AV_dout_nent,
  --     mask  => (others => (others => '1'))
  --   );

  -- LATCH_VMSMER_L4PHID: entity work.tf_pipeline_slr_xing
  --   port map (
  --     clk   => clk240,
  --     reset => reset,
  --     done  => PC_start,
  --     bx_out => PC_bx_in,
  --     bx => VMSMER_L4PHID_bx_in,
  --     start => VMSMER_L4PHID_start
  -- );

  LATCH_VMSMER_L4PHID_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => VMSMER_L4PHID_bx
  );

  -- VMSMER_L4PHID : entity work.VMSMER_L4PHID
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     bx_V          => VMSMER_L4PHID_bx,
  --     valid        => AS_L4PHIDin_valid,
  --     index        => AS_L4PHIDin_index,
  --     allStub_data_V        => AS_L4PHIDin_V_as,
  --     memoryME_0_dataarray_0_data_V_ce0       => open,
  --     memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIDn2_wea,
  --     memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIDn2_writeaddr,
  --     memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIDn2_din,
  --     memoriesAS_0_dataarray_data_V_ce0       => open,
  --     memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIDn2_wea,
  --     memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIDn2_writeaddr,
  --     memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIDn2_din
  -- );

-- ####### New VMSMER #######
  VMSMER_L4PHID_FIFO : entity work.VMSMER_L4PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      bx_V         => VMSMER_L4PHID_bx,  -- Same as legacy, in port
      valid        =>     or(AS_L4PHIDin_data_FIFO),
      -- index        =>     (others => '0'),  
      allStub_data_V    => AS_L4PHIDin_data_FIFO,  -- my new data, no delay
      memoryME_0_dataarray_0_data_V_ce0       => open,  -- same as legacy
      memoryME_0_dataarray_0_data_V_we0       => VMSME_L4PHIDn2_wea,  -- same as legacy, since out port anyway, remove legacy block to avoid conflict
      memoryME_0_dataarray_0_data_V_address0  => VMSME_L4PHIDn2_writeaddr,  -- out port
      memoryME_0_dataarray_0_data_V_d0        => VMSME_L4PHIDn2_din,  -- out port
      memoriesAS_0_dataarray_data_V_ce0       => open,  -- same as legacy
      memoriesAS_0_dataarray_data_V_we0       => AS_L4PHIDn2_wea,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_address0  => AS_L4PHIDn2_writeaddr,  -- same as legacy, used later
      memoriesAS_0_dataarray_data_V_d0        => AS_L4PHIDn2_din   -- same as legacy, used later
  );
  
  PC_L5L6ABCD_mem_reader : entity work.mem_reader
    generic map (
      RAM_WIDTH    => 73,
      NUM_TPAGES    => 4,
      NAME    => "PC_L5L6ABCD_mem_reader"
    )
    port map (
      clk    => clk240,
      bx    => PC_L5L6ABCD_bx_in,
      start => PC_L5L6ABCD_start,
      enb   => MPAR_L5L6ABCDin_enb,
      addra => MPAR_L5L6ABCDin_V_readaddr,
      din   => MPAR_L5L6ABCDin_V_dout,
      dout  => MPAR_L5L6ABCDin_V_tpar,
      valid  => MPAR_L5L6ABCDin_valid,
      index  => MPAR_L5L6ABCDin_trackletindex,
      nent  => MPAR_L5L6ABCDin_AV_dout_nent,
      mask  => MPAR_L5L6ABCDin_AV_dout_mask
    );

  LATCH_PC_VMSMER: entity work.tf_pipeline_slr_xing
      generic map (
        NUM_SLR       => 3,
        DELAY         => (2, 124, 2),
        USE_SRL       => (false, true, false)
      )
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_start,
      bx_out => PC_bx_in,
      bx => PC_bx_out,
      start => PC_done
  );

  LATCH_PC_L5L6ABCD: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_start,
      bx_out => PC_bx_in,
      bx => PC_L5L6ABCD_bx_in,
      start => PC_L5L6ABCD_start
  );

  LATCH_PC_L5L6ABCD_BX_GEN: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      bx_out => PC_bx_in,
      bx => PC_L5L6ABCD_bx
  );

  -- ######## legacy pc ########
  -- PC_L5L6ABCD : entity work.PC_L5L6ABCD
  --   port map (
  --     ap_clk   => clk240,
  --     ap_rst   => reset,
  --     ap_start => '1',
  --     bx_V          => PC_L5L6ABCD_bx,
  --     valid        => MPAR_L5L6ABCDin_valid,
  --     trackletindex_V        => MPAR_L5L6ABCDin_trackletindex,
  --     tpar_data_V        => MPAR_L5L6ABCDin_V_tpar,
  --     tparout_dataarray_data_V_ce0       => open,
  --     tparout_dataarray_data_V_we0       => MPAR_L5L6ABCD_wea,
  --     tparout_dataarray_data_V_address0  => MPAR_L5L6ABCD_writeaddr,
  --     tparout_dataarray_data_V_d0        => MPAR_L5L6ABCD_din,
  --     projout_barrel_ps_0_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_0_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIA_wea,
  --     projout_barrel_ps_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIA_writeaddr,
  --     projout_barrel_ps_0_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIA_din,
  --     projout_barrel_ps_1_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_1_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIB_wea,
  --     projout_barrel_ps_1_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIB_writeaddr,
  --     projout_barrel_ps_1_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIB_din,
  --     projout_barrel_ps_2_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_2_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIC_wea,
  --     projout_barrel_ps_2_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIC_writeaddr,
  --     projout_barrel_ps_2_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIC_din,
  --     projout_barrel_ps_3_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_3_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHID_wea,
  --     projout_barrel_ps_3_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHID_writeaddr,
  --     projout_barrel_ps_3_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHID_din,
  --     projout_barrel_ps_4_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_4_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIE_wea,
  --     projout_barrel_ps_4_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIE_writeaddr,
  --     projout_barrel_ps_4_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIE_din,
  --     projout_barrel_ps_5_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_5_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIF_wea,
  --     projout_barrel_ps_5_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIF_writeaddr,
  --     projout_barrel_ps_5_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIF_din,
  --     projout_barrel_ps_6_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_6_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIG_wea,
  --     projout_barrel_ps_6_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIG_writeaddr,
  --     projout_barrel_ps_6_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIG_din,
  --     projout_barrel_ps_7_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_7_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIH_wea,
  --     projout_barrel_ps_7_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIH_writeaddr,
  --     projout_barrel_ps_7_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIH_din,
  --     projout_barrel_ps_8_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_8_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIA_wea,
  --     projout_barrel_ps_8_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIA_writeaddr,
  --     projout_barrel_ps_8_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIA_din,
  --     projout_barrel_ps_9_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_9_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIB_wea,
  --     projout_barrel_ps_9_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIB_writeaddr,
  --     projout_barrel_ps_9_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIB_din,
  --     projout_barrel_ps_10_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_10_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIC_wea,
  --     projout_barrel_ps_10_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIC_writeaddr,
  --     projout_barrel_ps_10_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIC_din,
  --     projout_barrel_ps_11_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_11_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHID_wea,
  --     projout_barrel_ps_11_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHID_writeaddr,
  --     projout_barrel_ps_11_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHID_din,
  --     projout_barrel_ps_12_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_12_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIA_wea,
  --     projout_barrel_ps_12_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIA_writeaddr,
  --     projout_barrel_ps_12_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIA_din,
  --     projout_barrel_ps_13_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_13_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIB_wea,
  --     projout_barrel_ps_13_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIB_writeaddr,
  --     projout_barrel_ps_13_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIB_din,
  --     projout_barrel_ps_14_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_14_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIC_wea,
  --     projout_barrel_ps_14_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIC_writeaddr,
  --     projout_barrel_ps_14_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIC_din,
  --     projout_barrel_ps_15_dataarray_data_V_ce0       => open,
  --     projout_barrel_ps_15_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHID_wea,
  --     projout_barrel_ps_15_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHID_writeaddr,
  --     projout_barrel_ps_15_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHID_din,
  --     projout_barrel_2s_0_dataarray_data_V_ce0       => open,
  --     projout_barrel_2s_0_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIA_wea,
  --     projout_barrel_2s_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIA_writeaddr,
  --     projout_barrel_2s_0_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIA_din,
  --     projout_barrel_2s_1_dataarray_data_V_ce0       => open,
  --     projout_barrel_2s_1_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIB_wea,
  --     projout_barrel_2s_1_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIB_writeaddr,
  --     projout_barrel_2s_1_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIB_din,
  --     projout_barrel_2s_2_dataarray_data_V_ce0       => open,
  --     projout_barrel_2s_2_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIC_wea,
  --     projout_barrel_2s_2_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIC_writeaddr,
  --     projout_barrel_2s_2_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIC_din,
  --     projout_barrel_2s_3_dataarray_data_V_ce0       => open,
  --     projout_barrel_2s_3_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHID_wea,
  --     projout_barrel_2s_3_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHID_writeaddr,
  --     projout_barrel_2s_3_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHID_din
  -- );


    -- ######## new pc ########
  PC_L5L6ABCD_FIFO : entity work.PC_L5L6ABCD
    port map (
      ap_clk   => clk240,  -- same
      ap_rst   => reset,  --same
      ap_start => '1',  -- same
      bx_V          => PC_L5L6ABCD_bx,  -- from a delay and earlier from the in port of the SectorProcessor
      valid        => MPAR_L5L6ABCDin_valid,
      trackletindex_V        => MPAR_L5L6ABCDin_trackletindex,  -- need to change in the ProjectionCalculator.h
      tpar_data_V        => MPAR_L5L6ABCDin_din,  -- changed, directly from the in port
      tparout_dataarray_data_V_ce0       => open,
      tparout_dataarray_data_V_we0       => MPAR_L5L6ABCD_wea,
      tparout_dataarray_data_V_address0  => MPAR_L5L6ABCD_writeaddr,
      tparout_dataarray_data_V_d0        => MPAR_L5L6ABCD_din,
      projout_barrel_ps_0_dataarray_data_V_ce0       => open,
      projout_barrel_ps_0_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIA_wea,
      projout_barrel_ps_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIA_writeaddr,
      projout_barrel_ps_0_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIA_din,
      projout_barrel_ps_1_dataarray_data_V_ce0       => open,
      projout_barrel_ps_1_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIB_wea,
      projout_barrel_ps_1_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIB_writeaddr,
      projout_barrel_ps_1_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIB_din,
      projout_barrel_ps_2_dataarray_data_V_ce0       => open,
      projout_barrel_ps_2_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIC_wea,
      projout_barrel_ps_2_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIC_writeaddr,
      projout_barrel_ps_2_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIC_din,
      projout_barrel_ps_3_dataarray_data_V_ce0       => open,
      projout_barrel_ps_3_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHID_wea,
      projout_barrel_ps_3_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHID_writeaddr,
      projout_barrel_ps_3_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHID_din,
      projout_barrel_ps_4_dataarray_data_V_ce0       => open,
      projout_barrel_ps_4_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIE_wea,
      projout_barrel_ps_4_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIE_writeaddr,
      projout_barrel_ps_4_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIE_din,
      projout_barrel_ps_5_dataarray_data_V_ce0       => open,
      projout_barrel_ps_5_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIF_wea,
      projout_barrel_ps_5_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIF_writeaddr,
      projout_barrel_ps_5_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIF_din,
      projout_barrel_ps_6_dataarray_data_V_ce0       => open,
      projout_barrel_ps_6_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIG_wea,
      projout_barrel_ps_6_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIG_writeaddr,
      projout_barrel_ps_6_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIG_din,
      projout_barrel_ps_7_dataarray_data_V_ce0       => open,
      projout_barrel_ps_7_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L1PHIH_wea,
      projout_barrel_ps_7_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIH_writeaddr,
      projout_barrel_ps_7_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L1PHIH_din,
      projout_barrel_ps_8_dataarray_data_V_ce0       => open,
      projout_barrel_ps_8_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIA_wea,
      projout_barrel_ps_8_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIA_writeaddr,
      projout_barrel_ps_8_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIA_din,
      projout_barrel_ps_9_dataarray_data_V_ce0       => open,
      projout_barrel_ps_9_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIB_wea,
      projout_barrel_ps_9_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIB_writeaddr,
      projout_barrel_ps_9_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIB_din,
      projout_barrel_ps_10_dataarray_data_V_ce0       => open,
      projout_barrel_ps_10_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHIC_wea,
      projout_barrel_ps_10_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIC_writeaddr,
      projout_barrel_ps_10_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHIC_din,
      projout_barrel_ps_11_dataarray_data_V_ce0       => open,
      projout_barrel_ps_11_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L2PHID_wea,
      projout_barrel_ps_11_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHID_writeaddr,
      projout_barrel_ps_11_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L2PHID_din,
      projout_barrel_ps_12_dataarray_data_V_ce0       => open,
      projout_barrel_ps_12_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIA_wea,
      projout_barrel_ps_12_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIA_writeaddr,
      projout_barrel_ps_12_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIA_din,
      projout_barrel_ps_13_dataarray_data_V_ce0       => open,
      projout_barrel_ps_13_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIB_wea,
      projout_barrel_ps_13_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIB_writeaddr,
      projout_barrel_ps_13_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIB_din,
      projout_barrel_ps_14_dataarray_data_V_ce0       => open,
      projout_barrel_ps_14_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHIC_wea,
      projout_barrel_ps_14_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIC_writeaddr,
      projout_barrel_ps_14_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHIC_din,
      projout_barrel_ps_15_dataarray_data_V_ce0       => open,
      projout_barrel_ps_15_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L3PHID_wea,
      projout_barrel_ps_15_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHID_writeaddr,
      projout_barrel_ps_15_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L3PHID_din,
      projout_barrel_2s_0_dataarray_data_V_ce0       => open,
      projout_barrel_2s_0_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIA_wea,
      projout_barrel_2s_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIA_writeaddr,
      projout_barrel_2s_0_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIA_din,
      projout_barrel_2s_1_dataarray_data_V_ce0       => open,
      projout_barrel_2s_1_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIB_wea,
      projout_barrel_2s_1_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIB_writeaddr,
      projout_barrel_2s_1_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIB_din,
      projout_barrel_2s_2_dataarray_data_V_ce0       => open,
      projout_barrel_2s_2_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHIC_wea,
      projout_barrel_2s_2_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIC_writeaddr,
      projout_barrel_2s_2_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHIC_din,
      projout_barrel_2s_3_dataarray_data_V_ce0       => open,
      projout_barrel_2s_3_dataarray_data_V_we0       => MPROJ_L5L6ABCD_L4PHID_wea,
      projout_barrel_2s_3_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHID_writeaddr,
      projout_barrel_2s_3_dataarray_data_V_d0        => MPROJ_L5L6ABCD_L4PHID_din
  );

  LATCH_MP_L1PHIA: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIA_bx,
      start => MP_L1PHIA_start
  );

  MP_L1PHIA : entity work.MP_L1PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIA_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => MP_done,
      bx_V          => MP_L1PHIA_bx,
      bx_o_V        => MP_bx_out,
      bx_o_V_ap_vld => open,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIA_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIA_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIA_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIA_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIA_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIA_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIAn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIAn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIAn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIAn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIAn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIAn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIAn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIAn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIAn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIAn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIAn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIAn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIAn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIAn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIAn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIAn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIAn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIAn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIAn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIAn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIAn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIAn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIAn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIAn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIA_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIA_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIA_din
  );

  LATCH_MP_L1PHIB: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIB_bx,
      start => MP_L1PHIB_start
  );

  MP_L1PHIB : entity work.MP_L1PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIB_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIB_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIB_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIB_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIB_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIB_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIB_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIB_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIBn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIBn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIBn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIBn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIBn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIBn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIBn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIBn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIBn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIBn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIBn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIBn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIBn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIBn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIBn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIBn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIBn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIBn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIBn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIBn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIBn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIBn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIBn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIBn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIB_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIB_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIB_din
  );

  LATCH_MP_L1PHIC: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIC_bx,
      start => MP_L1PHIC_start
  );

  MP_L1PHIC : entity work.MP_L1PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIC_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIC_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIC_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIC_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIC_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIC_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIC_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHICn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHICn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHICn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHICn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHICn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHICn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHICn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHICn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHICn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHICn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHICn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHICn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHICn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHICn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHICn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHICn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHICn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHICn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHICn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHICn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHICn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHICn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHICn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHICn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIC_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIC_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIC_din
  );

  LATCH_MP_L1PHID: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHID_bx,
      start => MP_L1PHID_start
  );

  MP_L1PHID : entity work.MP_L1PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHID_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHID_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHID_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHID_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHID_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHID_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHID_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHID_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIDn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIDn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIDn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIDn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIDn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIDn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIDn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIDn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIDn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIDn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIDn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIDn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIDn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIDn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIDn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIDn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIDn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIDn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIDn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIDn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIDn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIDn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIDn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIDn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHID_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHID_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHID_din
  );

  LATCH_MP_L1PHIE: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIE_bx,
      start => MP_L1PHIE_start
  );

  MP_L1PHIE : entity work.MP_L1PHIE
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIE_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIE_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIE_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIE_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIE_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIE_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIE_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIE_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIEn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIEn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIEn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIEn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIEn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIEn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIEn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIEn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIEn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIEn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIEn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIEn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIEn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIEn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIEn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIEn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIEn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIEn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIEn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIEn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIEn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIEn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIEn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIEn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIE_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIE_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIE_din
  );

  LATCH_MP_L1PHIF: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIF_bx,
      start => MP_L1PHIF_start
  );

  MP_L1PHIF : entity work.MP_L1PHIF
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIF_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIF_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIF_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIF_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIF_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIF_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIF_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIF_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIFn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIFn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIFn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIFn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIFn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIFn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIFn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIFn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIFn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIFn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIFn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIFn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIFn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIFn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIFn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIFn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIFn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIFn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIFn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIFn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIFn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIFn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIFn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIFn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIF_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIF_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIF_din
  );

  LATCH_MP_L1PHIG: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIG_bx,
      start => MP_L1PHIG_start
  );

  MP_L1PHIG : entity work.MP_L1PHIG
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIG_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIG_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIG_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIG_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIG_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIG_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIG_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIG_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIGn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIGn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIGn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIGn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIGn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIGn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIGn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIGn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIGn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIGn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIGn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIGn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIGn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIGn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIGn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIGn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIGn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIGn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIGn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIGn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIGn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIGn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIGn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIGn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIG_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIG_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIG_din
  );

  LATCH_MP_L1PHIH: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L1PHIH_bx,
      start => MP_L1PHIH_start
  );

  MP_L1PHIH : entity work.MP_L1PHIH
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L1PHIH_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L1PHIH_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L1PHIH_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L1PHIH_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L1PHIH_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L1PHIH_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L1PHIH_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L1PHIH_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L1PHIHn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L1PHIHn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L1PHIHn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L1PHIHn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L1PHIHn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L1PHIHn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L1PHIHn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L1PHIHn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L1PHIHn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L1PHIHn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L1PHIHn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L1PHIHn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L1PHIHn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L1PHIHn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L1PHIHn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L1PHIHn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L1PHIHn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L1PHIHn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L1PHIHn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L1PHIHn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L1PHIHn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L1PHIHn2_enb,
      allstub_dataarray_data_V_address0  => AS_L1PHIHn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L1PHIHn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L1PHIH_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L1PHIH_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L1PHIH_din
  );

  LATCH_MP_L2PHIA: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L2PHIA_bx,
      start => MP_L2PHIA_start
  );

  MP_L2PHIA : entity work.MP_L2PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L2PHIA_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L2PHIA_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L2PHIA_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIA_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L2PHIA_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L2PHIA_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L2PHIA_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L2PHIA_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L2PHIAn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L2PHIAn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L2PHIAn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L2PHIAn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L2PHIAn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L2PHIAn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L2PHIAn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L2PHIAn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L2PHIAn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L2PHIAn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L2PHIAn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L2PHIAn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L2PHIAn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L2PHIAn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L2PHIAn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L2PHIAn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L2PHIAn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L2PHIAn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L2PHIAn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L2PHIAn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L2PHIAn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L2PHIAn2_enb,
      allstub_dataarray_data_V_address0  => AS_L2PHIAn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L2PHIAn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L2PHIA_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L2PHIA_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L2PHIA_din
  );

  LATCH_MP_L2PHIB: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L2PHIB_bx,
      start => MP_L2PHIB_start
  );

  MP_L2PHIB : entity work.MP_L2PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L2PHIB_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L2PHIB_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L2PHIB_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIB_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L2PHIB_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L2PHIB_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L2PHIB_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L2PHIB_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L2PHIBn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L2PHIBn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L2PHIBn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L2PHIBn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L2PHIBn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L2PHIBn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L2PHIBn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L2PHIBn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L2PHIBn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L2PHIBn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L2PHIBn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L2PHIBn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L2PHIBn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L2PHIBn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L2PHIBn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L2PHIBn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L2PHIBn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L2PHIBn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L2PHIBn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L2PHIBn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L2PHIBn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L2PHIBn2_enb,
      allstub_dataarray_data_V_address0  => AS_L2PHIBn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L2PHIBn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L2PHIB_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L2PHIB_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L2PHIB_din
  );

  LATCH_MP_L2PHIC: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L2PHIC_bx,
      start => MP_L2PHIC_start
  );

  MP_L2PHIC : entity work.MP_L2PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L2PHIC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L2PHIC_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L2PHIC_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHIC_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L2PHIC_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L2PHIC_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L2PHIC_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L2PHIC_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L2PHICn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L2PHICn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L2PHICn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L2PHICn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L2PHICn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L2PHICn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L2PHICn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L2PHICn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L2PHICn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L2PHICn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L2PHICn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L2PHICn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L2PHICn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L2PHICn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L2PHICn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L2PHICn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L2PHICn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L2PHICn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L2PHICn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L2PHICn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L2PHICn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L2PHICn2_enb,
      allstub_dataarray_data_V_address0  => AS_L2PHICn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L2PHICn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L2PHIC_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L2PHIC_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L2PHIC_din
  );

  LATCH_MP_L2PHID: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L2PHID_bx,
      start => MP_L2PHID_start
  );

  MP_L2PHID : entity work.MP_L2PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L2PHID_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L2PHID_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L2PHID_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L2PHID_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L2PHID_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L2PHID_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L2PHID_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L2PHID_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L2PHIDn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L2PHIDn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L2PHIDn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L2PHIDn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L2PHIDn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L2PHIDn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L2PHIDn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L2PHIDn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L2PHIDn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L2PHIDn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L2PHIDn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L2PHIDn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L2PHIDn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L2PHIDn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L2PHIDn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L2PHIDn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L2PHIDn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L2PHIDn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L2PHIDn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L2PHIDn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L2PHIDn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L2PHIDn2_enb,
      allstub_dataarray_data_V_address0  => AS_L2PHIDn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L2PHIDn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L2PHID_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L2PHID_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L2PHID_din
  );

  LATCH_MP_L3PHIA: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L3PHIA_bx,
      start => MP_L3PHIA_start
  );

  MP_L3PHIA : entity work.MP_L3PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L3PHIA_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L3PHIA_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L3PHIA_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIA_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L3PHIA_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L3PHIA_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L3PHIA_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L3PHIA_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L3PHIAn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L3PHIAn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L3PHIAn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L3PHIAn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L3PHIAn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L3PHIAn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L3PHIAn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L3PHIAn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L3PHIAn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L3PHIAn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L3PHIAn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L3PHIAn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L3PHIAn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L3PHIAn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L3PHIAn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L3PHIAn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L3PHIAn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L3PHIAn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L3PHIAn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L3PHIAn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L3PHIAn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L3PHIAn2_enb,
      allstub_dataarray_data_V_address0  => AS_L3PHIAn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L3PHIAn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L3PHIA_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L3PHIA_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L3PHIA_din
  );

  LATCH_MP_L3PHIB: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L3PHIB_bx,
      start => MP_L3PHIB_start
  );

  MP_L3PHIB : entity work.MP_L3PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L3PHIB_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L3PHIB_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L3PHIB_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIB_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L3PHIB_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L3PHIB_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L3PHIB_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L3PHIB_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L3PHIBn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L3PHIBn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L3PHIBn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L3PHIBn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L3PHIBn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L3PHIBn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L3PHIBn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L3PHIBn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L3PHIBn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L3PHIBn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L3PHIBn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L3PHIBn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L3PHIBn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L3PHIBn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L3PHIBn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L3PHIBn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L3PHIBn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L3PHIBn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L3PHIBn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L3PHIBn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L3PHIBn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L3PHIBn2_enb,
      allstub_dataarray_data_V_address0  => AS_L3PHIBn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L3PHIBn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L3PHIB_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L3PHIB_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L3PHIB_din
  );

  LATCH_MP_L3PHIC: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L3PHIC_bx,
      start => MP_L3PHIC_start
  );

  MP_L3PHIC : entity work.MP_L3PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L3PHIC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L3PHIC_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L3PHIC_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHIC_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L3PHIC_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L3PHIC_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L3PHIC_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L3PHIC_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L3PHICn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L3PHICn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L3PHICn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L3PHICn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L3PHICn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L3PHICn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L3PHICn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L3PHICn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L3PHICn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L3PHICn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L3PHICn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L3PHICn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L3PHICn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L3PHICn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L3PHICn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L3PHICn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L3PHICn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L3PHICn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L3PHICn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L3PHICn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L3PHICn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L3PHICn2_enb,
      allstub_dataarray_data_V_address0  => AS_L3PHICn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L3PHICn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L3PHIC_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L3PHIC_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L3PHIC_din
  );

  LATCH_MP_L3PHID: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L3PHID_bx,
      start => MP_L3PHID_start
  );

  MP_L3PHID : entity work.MP_L3PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L3PHID_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L3PHID_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L3PHID_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L3PHID_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L3PHID_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L3PHID_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L3PHID_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L3PHID_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L3PHIDn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L3PHIDn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L3PHIDn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L3PHIDn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L3PHIDn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L3PHIDn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L3PHIDn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L3PHIDn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L3PHIDn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L3PHIDn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L3PHIDn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L3PHIDn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L3PHIDn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L3PHIDn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L3PHIDn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L3PHIDn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L3PHIDn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L3PHIDn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L3PHIDn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L3PHIDn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L3PHIDn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L3PHIDn2_enb,
      allstub_dataarray_data_V_address0  => AS_L3PHIDn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L3PHIDn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L3PHID_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L3PHID_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L3PHID_din
  );

  LATCH_MP_L4PHIA: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L4PHIA_bx,
      start => MP_L4PHIA_start
  );

  MP_L4PHIA : entity work.MP_L4PHIA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L4PHIA_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L4PHIA_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L4PHIA_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIA_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L4PHIA_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L4PHIA_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L4PHIA_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L4PHIA_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L4PHIAn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L4PHIAn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L4PHIAn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L4PHIAn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L4PHIAn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L4PHIAn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L4PHIAn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L4PHIAn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L4PHIAn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L4PHIAn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L4PHIAn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L4PHIAn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L4PHIAn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L4PHIAn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L4PHIAn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L4PHIAn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L4PHIAn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L4PHIAn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L4PHIAn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L4PHIAn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L4PHIAn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L4PHIAn2_enb,
      allstub_dataarray_data_V_address0  => AS_L4PHIAn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L4PHIAn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L4PHIA_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L4PHIA_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L4PHIA_din
  );

  LATCH_MP_L4PHIB: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L4PHIB_bx,
      start => MP_L4PHIB_start
  );

  MP_L4PHIB : entity work.MP_L4PHIB
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L4PHIB_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L4PHIB_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L4PHIB_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIB_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L4PHIB_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L4PHIB_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L4PHIB_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L4PHIB_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L4PHIBn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L4PHIBn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L4PHIBn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L4PHIBn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L4PHIBn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L4PHIBn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L4PHIBn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L4PHIBn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L4PHIBn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L4PHIBn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L4PHIBn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L4PHIBn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L4PHIBn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L4PHIBn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L4PHIBn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L4PHIBn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L4PHIBn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L4PHIBn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L4PHIBn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L4PHIBn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L4PHIBn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L4PHIBn2_enb,
      allstub_dataarray_data_V_address0  => AS_L4PHIBn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L4PHIBn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L4PHIB_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L4PHIB_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L4PHIB_din
  );

  LATCH_MP_L4PHIC: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L4PHIC_bx,
      start => MP_L4PHIC_start
  );

  MP_L4PHIC : entity work.MP_L4PHIC
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L4PHIC_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L4PHIC_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L4PHIC_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHIC_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L4PHIC_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L4PHIC_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L4PHIC_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L4PHIC_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L4PHICn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L4PHICn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L4PHICn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L4PHICn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L4PHICn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L4PHICn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L4PHICn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L4PHICn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L4PHICn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L4PHICn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L4PHICn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L4PHICn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L4PHICn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L4PHICn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L4PHICn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L4PHICn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L4PHICn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L4PHICn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L4PHICn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L4PHICn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L4PHICn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L4PHICn2_enb,
      allstub_dataarray_data_V_address0  => AS_L4PHICn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L4PHICn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L4PHIC_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L4PHIC_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L4PHIC_din
  );

  LATCH_MP_L4PHID: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => PC_done,
      bx_out => PC_bx_out,
      bx => MP_L4PHID_bx,
      start => MP_L4PHID_start
  );

  MP_L4PHID : entity work.MP_L4PHID
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => MP_L4PHID_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => open,
      bx_V          => MP_L4PHID_bx,
      projin_0_dataarray_data_V_ce0       => MPROJ_L5L6ABCD_L4PHID_enb,
      projin_0_dataarray_data_V_address0  => MPROJ_L5L6ABCD_L4PHID_V_readaddr,
      projin_0_dataarray_data_V_q0        => MPROJ_L5L6ABCD_L4PHID_V_dout,
      projin_0_mask_0_V                   => MPROJ_L5L6ABCD_L4PHID_AV_dout_mask(0),
      projin_0_mask_1_V                   => MPROJ_L5L6ABCD_L4PHID_AV_dout_mask(1),
      projin_0_nentries_0_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(0),
      projin_0_nentries_1_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(1),
      projin_0_nentries_2_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(2),
      projin_0_nentries_3_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(3),
      projin_0_nentries_4_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(4),
      projin_0_nentries_5_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(5),
      projin_0_nentries_6_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(6),
      projin_0_nentries_7_V               => MPROJ_L5L6ABCD_L4PHID_AV_dout_nent(7),
      instubdata_dataarray_0_data_V_ce0       => VMSME_L4PHIDn2_A_enb(0),
      instubdata_dataarray_0_data_V_address0  => VMSME_L4PHIDn2_AV_readaddr(0),
      instubdata_dataarray_0_data_V_q0        => VMSME_L4PHIDn2_AV_dout(0),
      instubdata_dataarray_1_data_V_ce0       => VMSME_L4PHIDn2_A_enb(1),
      instubdata_dataarray_1_data_V_address0  => VMSME_L4PHIDn2_AV_readaddr(1),
      instubdata_dataarray_1_data_V_q0        => VMSME_L4PHIDn2_AV_dout(1),
      instubdata_dataarray_2_data_V_ce0       => VMSME_L4PHIDn2_A_enb(2),
      instubdata_dataarray_2_data_V_address0  => VMSME_L4PHIDn2_AV_readaddr(2),
      instubdata_dataarray_2_data_V_q0        => VMSME_L4PHIDn2_AV_dout(2),
      instubdata_dataarray_3_data_V_ce0       => VMSME_L4PHIDn2_A_enb(3),
      instubdata_dataarray_3_data_V_address0  => VMSME_L4PHIDn2_AV_readaddr(3),
      instubdata_dataarray_3_data_V_q0        => VMSME_L4PHIDn2_AV_dout(3),
      instubdata_nentries_V_ce0 => VMSME_L4PHIDn2_enb_nent,
      instubdata_nentries_V_address0 => VMSME_L4PHIDn2_V_addr_nent,
      instubdata_nentries_V_q0 => VMSME_L4PHIDn2_AV_dout_nent,
      instubdata_binmaskA_V_address0 => VMSME_L4PHIDn2_V_addr_binmaskA,
      instubdata_binmaskA_V_ce0 => VMSME_L4PHIDn2_enb_binmaskA,
      instubdata_binmaskA_V_q0 => VMSME_L4PHIDn2_V_binmaskA,
      instubdata_binmaskB_V_address0 => VMSME_L4PHIDn2_V_addr_binmaskB,
      instubdata_binmaskB_V_ce0 => VMSME_L4PHIDn2_enb_binmaskB,
      instubdata_binmaskB_V_q0 => VMSME_L4PHIDn2_V_binmaskB,
      allstub_dataarray_data_V_ce0       => AS_L4PHIDn2_enb,
      allstub_dataarray_data_V_address0  => AS_L4PHIDn2_V_readaddr,
      allstub_dataarray_data_V_q0        => AS_L4PHIDn2_V_dout,
      fullmatch_0_dataarray_data_V_ce0       => open,
      fullmatch_0_dataarray_data_V_we0       => FM_AAAA_L4PHID_wea,
      fullmatch_0_dataarray_data_V_address0  => FM_AAAA_L4PHID_writeaddr,
      fullmatch_0_dataarray_data_V_d0        => FM_AAAA_L4PHID_din
  );

  LATCH_TB_AAAA: entity work.tf_pipeline_slr_xing
    port map (
      clk   => clk240,
      reset => reset,
      done  => MP_done,
      bx_out => MP_bx_out,
      bx => TB_AAAA_bx,
      start => TB_AAAA_start
  );

  TB_AAAA : entity work.TB_AAAA
    port map (
      ap_clk   => clk240,
      ap_rst   => reset,
      ap_start => TB_AAAA_start,
      ap_idle  => open,
      ap_ready => open,
      ap_done  => TB_done,
      bx_V          => TB_AAAA_bx,
      bx_o_V        => TB_bx_out,
      bx_o_V_ap_vld => TB_bx_out_vld,
      trackletParameters4_0_dataarray_data_V_ce0       => MPAR_L5L6ABCD_enb,
      trackletParameters4_0_dataarray_data_V_address0  => MPAR_L5L6ABCD_V_readaddr,
      trackletParameters4_0_dataarray_data_V_q0        => MPAR_L5L6ABCD_V_dout,
      barrelFullMatches_0_dataarray_data_V_ce0       => FM_AAAA_L1PHIA_enb,
      barrelFullMatches_0_dataarray_data_V_address0  => FM_AAAA_L1PHIA_V_readaddr,
      barrelFullMatches_0_dataarray_data_V_q0        => FM_AAAA_L1PHIA_V_dout,
      barrelFullMatches_0_nentries_0_V               => FM_AAAA_L1PHIA_AV_dout_nent(0),
      barrelFullMatches_0_nentries_1_V               => FM_AAAA_L1PHIA_AV_dout_nent(1),
      barrelFullMatches_1_dataarray_data_V_ce0       => FM_AAAA_L1PHIB_enb,
      barrelFullMatches_1_dataarray_data_V_address0  => FM_AAAA_L1PHIB_V_readaddr,
      barrelFullMatches_1_dataarray_data_V_q0        => FM_AAAA_L1PHIB_V_dout,
      barrelFullMatches_1_nentries_0_V               => FM_AAAA_L1PHIB_AV_dout_nent(0),
      barrelFullMatches_1_nentries_1_V               => FM_AAAA_L1PHIB_AV_dout_nent(1),
      barrelFullMatches_2_dataarray_data_V_ce0       => FM_AAAA_L1PHIC_enb,
      barrelFullMatches_2_dataarray_data_V_address0  => FM_AAAA_L1PHIC_V_readaddr,
      barrelFullMatches_2_dataarray_data_V_q0        => FM_AAAA_L1PHIC_V_dout,
      barrelFullMatches_2_nentries_0_V               => FM_AAAA_L1PHIC_AV_dout_nent(0),
      barrelFullMatches_2_nentries_1_V               => FM_AAAA_L1PHIC_AV_dout_nent(1),
      barrelFullMatches_3_dataarray_data_V_ce0       => FM_AAAA_L1PHID_enb,
      barrelFullMatches_3_dataarray_data_V_address0  => FM_AAAA_L1PHID_V_readaddr,
      barrelFullMatches_3_dataarray_data_V_q0        => FM_AAAA_L1PHID_V_dout,
      barrelFullMatches_3_nentries_0_V               => FM_AAAA_L1PHID_AV_dout_nent(0),
      barrelFullMatches_3_nentries_1_V               => FM_AAAA_L1PHID_AV_dout_nent(1),
      barrelFullMatches_4_dataarray_data_V_ce0       => FM_AAAA_L1PHIE_enb,
      barrelFullMatches_4_dataarray_data_V_address0  => FM_AAAA_L1PHIE_V_readaddr,
      barrelFullMatches_4_dataarray_data_V_q0        => FM_AAAA_L1PHIE_V_dout,
      barrelFullMatches_4_nentries_0_V               => FM_AAAA_L1PHIE_AV_dout_nent(0),
      barrelFullMatches_4_nentries_1_V               => FM_AAAA_L1PHIE_AV_dout_nent(1),
      barrelFullMatches_5_dataarray_data_V_ce0       => FM_AAAA_L1PHIF_enb,
      barrelFullMatches_5_dataarray_data_V_address0  => FM_AAAA_L1PHIF_V_readaddr,
      barrelFullMatches_5_dataarray_data_V_q0        => FM_AAAA_L1PHIF_V_dout,
      barrelFullMatches_5_nentries_0_V               => FM_AAAA_L1PHIF_AV_dout_nent(0),
      barrelFullMatches_5_nentries_1_V               => FM_AAAA_L1PHIF_AV_dout_nent(1),
      barrelFullMatches_6_dataarray_data_V_ce0       => FM_AAAA_L1PHIG_enb,
      barrelFullMatches_6_dataarray_data_V_address0  => FM_AAAA_L1PHIG_V_readaddr,
      barrelFullMatches_6_dataarray_data_V_q0        => FM_AAAA_L1PHIG_V_dout,
      barrelFullMatches_6_nentries_0_V               => FM_AAAA_L1PHIG_AV_dout_nent(0),
      barrelFullMatches_6_nentries_1_V               => FM_AAAA_L1PHIG_AV_dout_nent(1),
      barrelFullMatches_7_dataarray_data_V_ce0       => FM_AAAA_L1PHIH_enb,
      barrelFullMatches_7_dataarray_data_V_address0  => FM_AAAA_L1PHIH_V_readaddr,
      barrelFullMatches_7_dataarray_data_V_q0        => FM_AAAA_L1PHIH_V_dout,
      barrelFullMatches_7_nentries_0_V               => FM_AAAA_L1PHIH_AV_dout_nent(0),
      barrelFullMatches_7_nentries_1_V               => FM_AAAA_L1PHIH_AV_dout_nent(1),
      barrelFullMatches_8_dataarray_data_V_ce0       => FM_AAAA_L2PHIA_enb,
      barrelFullMatches_8_dataarray_data_V_address0  => FM_AAAA_L2PHIA_V_readaddr,
      barrelFullMatches_8_dataarray_data_V_q0        => FM_AAAA_L2PHIA_V_dout,
      barrelFullMatches_8_nentries_0_V               => FM_AAAA_L2PHIA_AV_dout_nent(0),
      barrelFullMatches_8_nentries_1_V               => FM_AAAA_L2PHIA_AV_dout_nent(1),
      barrelFullMatches_9_dataarray_data_V_ce0       => FM_AAAA_L2PHIB_enb,
      barrelFullMatches_9_dataarray_data_V_address0  => FM_AAAA_L2PHIB_V_readaddr,
      barrelFullMatches_9_dataarray_data_V_q0        => FM_AAAA_L2PHIB_V_dout,
      barrelFullMatches_9_nentries_0_V               => FM_AAAA_L2PHIB_AV_dout_nent(0),
      barrelFullMatches_9_nentries_1_V               => FM_AAAA_L2PHIB_AV_dout_nent(1),
      barrelFullMatches_10_dataarray_data_V_ce0       => FM_AAAA_L2PHIC_enb,
      barrelFullMatches_10_dataarray_data_V_address0  => FM_AAAA_L2PHIC_V_readaddr,
      barrelFullMatches_10_dataarray_data_V_q0        => FM_AAAA_L2PHIC_V_dout,
      barrelFullMatches_10_nentries_0_V               => FM_AAAA_L2PHIC_AV_dout_nent(0),
      barrelFullMatches_10_nentries_1_V               => FM_AAAA_L2PHIC_AV_dout_nent(1),
      barrelFullMatches_11_dataarray_data_V_ce0       => FM_AAAA_L2PHID_enb,
      barrelFullMatches_11_dataarray_data_V_address0  => FM_AAAA_L2PHID_V_readaddr,
      barrelFullMatches_11_dataarray_data_V_q0        => FM_AAAA_L2PHID_V_dout,
      barrelFullMatches_11_nentries_0_V               => FM_AAAA_L2PHID_AV_dout_nent(0),
      barrelFullMatches_11_nentries_1_V               => FM_AAAA_L2PHID_AV_dout_nent(1),
      barrelFullMatches_12_dataarray_data_V_ce0       => FM_AAAA_L3PHIA_enb,
      barrelFullMatches_12_dataarray_data_V_address0  => FM_AAAA_L3PHIA_V_readaddr,
      barrelFullMatches_12_dataarray_data_V_q0        => FM_AAAA_L3PHIA_V_dout,
      barrelFullMatches_12_nentries_0_V               => FM_AAAA_L3PHIA_AV_dout_nent(0),
      barrelFullMatches_12_nentries_1_V               => FM_AAAA_L3PHIA_AV_dout_nent(1),
      barrelFullMatches_13_dataarray_data_V_ce0       => FM_AAAA_L3PHIB_enb,
      barrelFullMatches_13_dataarray_data_V_address0  => FM_AAAA_L3PHIB_V_readaddr,
      barrelFullMatches_13_dataarray_data_V_q0        => FM_AAAA_L3PHIB_V_dout,
      barrelFullMatches_13_nentries_0_V               => FM_AAAA_L3PHIB_AV_dout_nent(0),
      barrelFullMatches_13_nentries_1_V               => FM_AAAA_L3PHIB_AV_dout_nent(1),
      barrelFullMatches_14_dataarray_data_V_ce0       => FM_AAAA_L3PHIC_enb,
      barrelFullMatches_14_dataarray_data_V_address0  => FM_AAAA_L3PHIC_V_readaddr,
      barrelFullMatches_14_dataarray_data_V_q0        => FM_AAAA_L3PHIC_V_dout,
      barrelFullMatches_14_nentries_0_V               => FM_AAAA_L3PHIC_AV_dout_nent(0),
      barrelFullMatches_14_nentries_1_V               => FM_AAAA_L3PHIC_AV_dout_nent(1),
      barrelFullMatches_15_dataarray_data_V_ce0       => FM_AAAA_L3PHID_enb,
      barrelFullMatches_15_dataarray_data_V_address0  => FM_AAAA_L3PHID_V_readaddr,
      barrelFullMatches_15_dataarray_data_V_q0        => FM_AAAA_L3PHID_V_dout,
      barrelFullMatches_15_nentries_0_V               => FM_AAAA_L3PHID_AV_dout_nent(0),
      barrelFullMatches_15_nentries_1_V               => FM_AAAA_L3PHID_AV_dout_nent(1),
      barrelFullMatches_16_dataarray_data_V_ce0       => FM_AAAA_L4PHIA_enb,
      barrelFullMatches_16_dataarray_data_V_address0  => FM_AAAA_L4PHIA_V_readaddr,
      barrelFullMatches_16_dataarray_data_V_q0        => FM_AAAA_L4PHIA_V_dout,
      barrelFullMatches_16_nentries_0_V               => FM_AAAA_L4PHIA_AV_dout_nent(0),
      barrelFullMatches_16_nentries_1_V               => FM_AAAA_L4PHIA_AV_dout_nent(1),
      barrelFullMatches_17_dataarray_data_V_ce0       => FM_AAAA_L4PHIB_enb,
      barrelFullMatches_17_dataarray_data_V_address0  => FM_AAAA_L4PHIB_V_readaddr,
      barrelFullMatches_17_dataarray_data_V_q0        => FM_AAAA_L4PHIB_V_dout,
      barrelFullMatches_17_nentries_0_V               => FM_AAAA_L4PHIB_AV_dout_nent(0),
      barrelFullMatches_17_nentries_1_V               => FM_AAAA_L4PHIB_AV_dout_nent(1),
      barrelFullMatches_18_dataarray_data_V_ce0       => FM_AAAA_L4PHIC_enb,
      barrelFullMatches_18_dataarray_data_V_address0  => FM_AAAA_L4PHIC_V_readaddr,
      barrelFullMatches_18_dataarray_data_V_q0        => FM_AAAA_L4PHIC_V_dout,
      barrelFullMatches_18_nentries_0_V               => FM_AAAA_L4PHIC_AV_dout_nent(0),
      barrelFullMatches_18_nentries_1_V               => FM_AAAA_L4PHIC_AV_dout_nent(1),
      barrelFullMatches_19_dataarray_data_V_ce0       => FM_AAAA_L4PHID_enb,
      barrelFullMatches_19_dataarray_data_V_address0  => FM_AAAA_L4PHID_V_readaddr,
      barrelFullMatches_19_dataarray_data_V_q0        => FM_AAAA_L4PHID_V_dout,
      barrelFullMatches_19_nentries_0_V               => FM_AAAA_L4PHID_AV_dout_nent(0),
      barrelFullMatches_19_nentries_1_V               => FM_AAAA_L4PHID_AV_dout_nent(1),
      trackWord_V_din       => TW_AAAA_stream_AV_din,
      trackWord_V_full_n    => TW_AAAA_stream_A_full_neg,
      trackWord_V_write     => TW_AAAA_stream_A_write,
      barrelStubWords_0_V_din       => BW_AAAA_L1_stream_AV_din,
      barrelStubWords_0_V_full_n    => BW_AAAA_L1_stream_A_full_neg,
      barrelStubWords_0_V_write     => BW_AAAA_L1_stream_A_write,
      barrelStubWords_1_V_din       => BW_AAAA_L2_stream_AV_din,
      barrelStubWords_1_V_full_n    => BW_AAAA_L2_stream_A_full_neg,
      barrelStubWords_1_V_write     => BW_AAAA_L2_stream_A_write,
      barrelStubWords_2_V_din       => BW_AAAA_L3_stream_AV_din,
      barrelStubWords_2_V_full_n    => BW_AAAA_L3_stream_A_full_neg,
      barrelStubWords_2_V_write     => BW_AAAA_L3_stream_A_write,
      barrelStubWords_3_V_din       => BW_AAAA_L4_stream_AV_din,
      barrelStubWords_3_V_full_n    => BW_AAAA_L4_stream_A_full_neg,
      barrelStubWords_3_V_write     => BW_AAAA_L4_stream_A_write,
      barrelStubWords_4_V_din       => BW_AAAA_L5_stream_AV_din,
      barrelStubWords_4_V_full_n    => BW_AAAA_L5_stream_A_full_neg,
      barrelStubWords_4_V_write     => BW_AAAA_L5_stream_A_write,
      barrelStubWords_5_V_din       => BW_AAAA_L6_stream_AV_din,
      barrelStubWords_5_V_full_n    => BW_AAAA_L6_stream_A_full_neg,
      barrelStubWords_5_V_write     => BW_AAAA_L6_stream_A_write,
      diskStubWords_0_V_din       => DW_AAAA_D1_stream_AV_din,
      diskStubWords_0_V_full_n    => DW_AAAA_D1_stream_A_full_neg,
      diskStubWords_0_V_write     => DW_AAAA_D1_stream_A_write,
      diskStubWords_1_V_din       => DW_AAAA_D2_stream_AV_din,
      diskStubWords_1_V_full_n    => DW_AAAA_D2_stream_A_full_neg,
      diskStubWords_1_V_write     => DW_AAAA_D2_stream_A_write,
      diskStubWords_2_V_din       => DW_AAAA_D3_stream_AV_din,
      diskStubWords_2_V_full_n    => DW_AAAA_D3_stream_A_full_neg,
      diskStubWords_2_V_write     => DW_AAAA_D3_stream_A_write,
      diskStubWords_3_V_din       => DW_AAAA_D4_stream_AV_din,
      diskStubWords_3_V_full_n    => DW_AAAA_D4_stream_A_full_neg,
      diskStubWords_3_V_write     => DW_AAAA_D4_stream_A_write,
      diskStubWords_4_V_din       => DW_AAAA_D5_stream_AV_din,
      diskStubWords_4_V_full_n    => DW_AAAA_D5_stream_A_full_neg,
      diskStubWords_4_V_write     => DW_AAAA_D5_stream_A_write,
      done        => TB_AAAA_last_track,
      done_ap_vld => TB_AAAA_last_track_vld
  );

end rtl;
