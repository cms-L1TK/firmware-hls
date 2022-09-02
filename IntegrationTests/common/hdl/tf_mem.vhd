library ieee;
use ieee.std_logic_1164.all;
use work.tf_pkg.all;


entity tf_mem is
generic (
  RAM_WIDTH: natural := 14;
  NUM_PAGES: natural := 2;
  RAM_DEPTH: natural := NUM_PAGES*PAGE_LENGTH;
  RAM_TYPE: string := "block"
);
port (
  clk: in std_logic;
  --memory_din: in t_write;
  rstb: in std_logic;
  wea: in std_logic;
  bxa: in std_logic_vector( 2 downto 0 );  -- set to bx_o
  addra: in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  dina: in std_logic_vector( RAM_WIDTH - 1 downto 0 );
  --memory_read: in t_read;
  addrb: in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  --memory_dout: out t_data
  nent_o: out t_arr_7b(0 to NUM_PAGES-1);
  doutb: out std_logic_vector( RAM_WIDTH - 1 downto 0 )
);
end;


architecture rtl of tf_mem is

constant widthAddr: natural := clogb2(RAM_DEPTH);
constant widthNent: natural := 7;

constant widthNentIn: natural := widthNent;
function init_widthIndexBX return natural is begin if widthAddr = 8 then return 1; end if; return 3; end function;
constant widthIndexBX: natural := init_widthIndexBX;
constant widthIndexNent: natural := widthAddr - widthNentIn;

type t_ram is array ( 0 to  2 ** widthAddr - 1 ) of std_logic_vector( RAM_WIDTH - 1 downto 0 );

signal bx, bxReg: std_logic_vector( widthIndexBX - 1 downto 0 ) := ( others => '0' );
signal ram: t_ram := ( others => ( others => '0' ) );
signal nent: std_logic_vector( widthNent - 1 downto 0 ) := ( others => '0' );
signal indexNent: std_logic_vector( widthIndexNent - 1 downto 0 ) := ( others => '0' );
signal optional: std_logic_vector( RAM_WIDTH - 1 downto 0 ) := ( others => '0' );
signal reg: std_logic_vector( RAM_WIDTH - 1 downto 0 ) := ( others => '0' );
signal dout_nents: t_arr_7b(0 to NUM_PAGES-1) := ( others => ( others => '0' ) );
signal dout_data: std_logic_vector( RAM_WIDTH - 1 downto 0 ) := ( others => '0' );

attribute ram_style: string;
attribute ram_style of ram: signal is RAM_TYPE;

begin


doutb <= dout_data;
nent_o <= dout_nents;


-- step 1

nent <= incr( resize( addra( widthNentIn - 1 downto 0 ), widthNent ) );
indexNent <= addra( widthAddr - 1 downto widthAddr - widthIndexNent );
bx <= bxa( widthIndexBX - 1 downto 0 );

-- step 2

dout_data( RAM_WIDTH - 1 downto 0 ) <= reg;


process ( clk ) is
begin
if rising_edge( clk ) then

  -- step 1

  bxReg <= bx;
  optional <= ram( uint( addrb( widthAddr - 1 downto 0 ) ) );

  if bxReg /= bx then
    dout_nents( uint( incr( bx ) ) )( widthNent - 1 downto 0 ) <= ( others => '0' );
  end if;

  if wea = '1' then
    dout_nents( uint( indexNent ) )( widthNent - 1 downto 0 ) <= nent;
    ram( uint( addra( widthAddr - 1 downto 0 ) ) ) <= dina( RAM_WIDTH - 1 downto 0 );
  end if; 

  if rstb = '1' then
    for k in 0 to 2 ** widthIndexNent - 1 loop
      dout_nents( k )( widthNent - 1 downto 0 ) <= ( others => '0' );
    end loop;
  end if;

  -- step 2

  reg <= optional;

end if;
end process;


end;
