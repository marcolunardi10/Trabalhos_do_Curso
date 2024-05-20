library ieee;
use ieee.std_logic_1164.all;

--w = key2
--clock = key1
--reset = key0
--z = sw0

entity maqRefri is
    port(
        key : in std_logic_vector(3 downto 0);
 ledr : out std_logic_vector(9 downto 0)
    );
    end maqRefri;  
   
    architecture Behavior of maqRefri is
    type Tipo_estado is (A,B,C,D);
    signal y_atual, y_prox : Tipo_estado;
begin
    process (key(2), y_atual)
    begin
        case y_atual is
            when A =>
                if key(2) = '1' then
                    y_prox <= B;
                else
                    y_prox <= C;
                end if;
            when B =>
                if key(2) = '1' then
                    y_prox <= C;
                else
                    y_prox <= D;
                end if;
            when C =>
                if key(2) = '1' then
                    y_prox <= D;
                else
                    y_prox <= D;
                end if;
             when D =>
                if key(2) = '1' then
                    y_prox <= A;
                else
                    y_prox <= A;
                end if;
        end case;
    end process;

    process (key(1), key(0))
    begin
        if key(0) = '0' then
            y_atual <= A;
        elsif (key(1)'event and key(1) = '0') then
            y_atual <= y_prox;
        end if;
    end process;
    ledr(0) <= '1' when y_atual = D else '0';
end Behavior;

