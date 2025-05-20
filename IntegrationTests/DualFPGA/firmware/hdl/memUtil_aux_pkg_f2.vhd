--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.memUtil_Pkg.all;

package memUtil_aux_pkg_f2 is

  -- ########################### Types ###########################

  type enum_AS_36_f1 is (L1PHIAn1,L1PHIBn1,L1PHICn1,L1PHIDn1,L1PHIEn1,L1PHIFn1,L1PHIGn1,L1PHIHn1,L2PHIAn1,L2PHIBn1,L2PHICn1,L2PHIDn1,L3PHIAn1,L3PHIBn1,L3PHICn1,L3PHIDn1,L4PHIAn1,L4PHIBn1,L4PHICn1,L4PHIDn1,L5PHIAn1,L5PHIBn1,L5PHICn1,L5PHIDn1,L6PHIAn1,L6PHIBn1,L6PHICn1,L6PHIDn1,D1PHIAn1,D1PHIBn1,D1PHICn1,D1PHIDn1,D2PHIAn1,D2PHIBn1,D2PHICn1,D2PHIDn1,D3PHIAn1,D3PHIBn1,D3PHICn1,D3PHIDn1,D4PHIAn1,D4PHIBn1,D4PHICn1,D4PHIDn1,D5PHIAn1,D5PHIBn1,D5PHICn1,D5PHIDn1);

  type enum_MTPAR_73 is (L1L2ABC,L1L2DE,L1L2F,L1L2G,L1L2HI,L1L2JKL,L2L3ABCD,L3L4AB,L3L4CD,L5L6ABCD,D1D2ABCD,D3D4ABCD,L1D1ABCD,L1D1EFGH,L2D1ABCD);

  type t_arr_AS_36_1b is array(enum_AS_36_f1) of std_logic;
  type t_arr_AS_36_37b is array(enum_AS_36_f1) of std_logic_vector(36 downto 0);
  type t_arr_AS_36_ADDR is array(enum_AS_36_f1) of std_logic_vector(9 downto 0);
  type t_arr_AS_36_DATA is array(enum_AS_36_f1) of std_logic_vector(35 downto 0);

  type t_arr_MTPAR_73_1b is array(enum_MTPAR_73) of std_logic;
  type t_arr_MTPAR_73_76b is array(enum_MTPAR_73) of std_logic_vector(75 downto 0);
  type t_arr_MTPAR_73_ADDR is array(enum_MTPAR_73) of std_logic_vector(11 downto 0);
  type t_arr_MTPAR_73_DATA is array(enum_MTPAR_73) of std_logic_vector(72 downto 0);

  type t_arr_TW_113_1b is array(enum_TW_113) of std_logic;
  type t_arr_TW_113_DATA is array(enum_TW_113) of std_logic_vector(112 downto 0);

  type t_arr_BW_46_1b is array(enum_BW_46) of std_logic;
  type t_arr_BW_46_DATA is array(enum_BW_46) of std_logic_vector(45 downto 0);

  type t_arr_DW_49_1b is array(enum_DW_49) of std_logic;
  type t_arr_DW_49_DATA is array(enum_DW_49) of std_logic_vector(48 downto 0);

  type t_f2_in is record
    PC_start                  :  std_logic;
    PC_bx_in                  :  std_logic_vector(2 downto 0);
    AS_36_wea                 :  t_arr_AS_36_1b;
    AS_36_writeaddr           :  t_arr_AS_36_ADDR;
    AS_36_din                 :  t_arr_AS_36_DATA;
    MPAR_73_wea               :  t_arr_MTPAR_73_1b;
    MPAR_73_writeaddr         :  t_arr_MTPAR_73_ADDR;
    MPAR_73_din               :  t_arr_MTPAR_73_DATA;
  end record t_f2_in;

  constant c_f2_in_init : t_f2_in := (
    PC_start                  =>  '0',
    PC_bx_in                  =>  (others => '0'),
    AS_36_wea                 =>  (others => '0'),
    AS_36_writeaddr           =>  (others => (others => '0')),
    AS_36_din                 =>  (others => (others => '0')),
    MPAR_73_wea               =>  (others => '0'),
    MPAR_73_writeaddr         =>  (others => (others => '0')),
    MPAR_73_din               =>  (others => (others => '0'))
  );

  type t_f2_out is record
    PC_bx_out              :  std_logic_vector(2 downto 0);
    PC_bx_out_vld          :  std_logic;
    PC_done                :  std_logic;
    TB_bx_out              :  std_logic_vector(2 downto 0);
    TB_bx_out_vld          :  std_logic;
    TB_done                :  std_logic;
    TB_last_track          :  std_logic;
    TB_last_track_vld      :  std_logic;
    TW_113_stream_AV_din   :  t_arr_TW_113_DATA;
    TW_113_stream_A_write  :  t_arr_TW_113_1b;
    DW_49_stream_AV_din    :  t_arr_DW_49_DATA;
    DW_49_stream_A_write   :  t_arr_DW_49_1b;
    BW_46_stream_AV_din    :  t_arr_BW_46_DATA;
    BW_46_stream_A_write   :  t_arr_BW_46_1b;
  end record t_f2_out;

  constant c_f2_out_init : t_f2_out := (
    PC_bx_out              =>  (others => '0'),
    PC_bx_out_vld          =>  '0',
    PC_done                =>  '0',
    TB_bx_out              =>  (others => '0'),
    TB_bx_out_vld          =>  '0',
    TB_done                =>  '0',
    TB_last_track          =>  '0',
    TB_last_track_vld      =>  '0',
    TW_113_stream_AV_din   =>  (others => (others => '0')),
    TW_113_stream_A_write  =>  (others => '0'),
    DW_49_stream_AV_din    =>  (others => (others => '0')),
    DW_49_stream_A_write   =>  (others => '0'),
    BW_46_stream_AV_din    =>  (others => (others => '0')),
    BW_46_stream_A_write   =>  (others => '0')
  );

end package memUtil_aux_pkg_f2;

