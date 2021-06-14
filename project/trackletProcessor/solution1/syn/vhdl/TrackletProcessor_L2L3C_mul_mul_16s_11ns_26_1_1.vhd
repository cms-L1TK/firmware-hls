
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_DSP48_7 is
port (
    a: in std_logic_vector(16 - 1 downto 0);
    b: in std_logic_vector(11 - 1 downto 0);
    p: out std_logic_vector(26 - 1 downto 0));

end entity;

architecture behav of TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_DSP48_7 is
    signal a_cvt: signed(16 - 1 downto 0);
    signal b_cvt: unsigned(11 - 1 downto 0);
    signal p_cvt: signed(26 - 1 downto 0);


begin

    a_cvt <= signed(a);
    b_cvt <= unsigned(b);
    p_cvt <= signed (resize(unsigned (signed (a_cvt) * signed ('0' & b_cvt)), 26));
    p <= std_logic_vector(p_cvt);

end architecture;
Library IEEE;
use IEEE.std_logic_1164.all;

entity TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1 is
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER);
    port (
        din0 : IN STD_LOGIC_VECTOR(din0_WIDTH - 1 DOWNTO 0);
        din1 : IN STD_LOGIC_VECTOR(din1_WIDTH - 1 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(dout_WIDTH - 1 DOWNTO 0));
end entity;

architecture arch of TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1 is
    component TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_DSP48_7 is
        port (
            a : IN STD_LOGIC_VECTOR;
            b : IN STD_LOGIC_VECTOR;
            p : OUT STD_LOGIC_VECTOR);
    end component;



begin
    TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_DSP48_7_U :  component TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_DSP48_7
    port map (
        a => din0,
        b => din1,
        p => dout);

end architecture;


