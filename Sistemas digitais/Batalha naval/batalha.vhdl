library ieee;
use ieee.std_logic_1164.all;

--key0 = reset
--key1 = set barcos
--key2 = disparo

entity batalha is
    port(
        key0, key1, key2 : in std_logic;
        sw0, sw1, sw2, sw3, sw4 : in std_logic;
        ledstart,ledacerto, ledwin, ledlose : out std_logic;
        hex0, hex1, hex2, hex3, hex4, hex5, hex6 : out std_logic
    );
    end batalha;  
   
    architecture Behavior of batalha is
    type Tipo_estado is (inicio, navio1set, navio2set, start);
    signal estado_atual, prox_estado: Tipo_estado;
    signal navio1, navio2a, navio2b, posicao_disparo, novo_jogo : std_logic_vector(0 to 3);
    begin
    process (key1, key2, estado_atual)
        variable disparos : integer;
        variable chance : integer;
        variable acertos : integer;
    begin
        case estado_atual is
            when inicio => 
                    navio1 <= novo_jogo;
                    navio2a <= novo_jogo;
                    navio2b <= novo_jogo;
                    posicao_disparo <= novo_jogo;
                    disparos := 6;
                    chance := 0;
                    acertos := 0;
                    ledwin <= '0';
                    ledlose <= '0';
                    ledacerto <= '0';
                    prox_estado <= navio1set;
            when navio1set => 
                if key2'event then
                    navio1(0) <= sw0;
                    navio1(1) <= sw1;
                    navio1(2) <= sw2;
                    navio1(3) <= sw3;
                    if navio1 = "0000" then
                        navio1 <= "0001";
                    elsif navio1 = "0001" then 
                        navio1 <= "1100";
                    elsif navio1 = "0010" then 
                        navio1 <= "1010";
                    elsif navio1 = "0011" then 
                        navio1 <= "1111";
                    elsif navio1 = "0100" then 
                        navio1 <= "0110";
                    elsif navio1 = "0101" then 
                        navio1 <= "0000";
                    elsif navio1 = "0110" then 
                        navio1 <= "1001";
                    elsif navio1 = "0111" then 
                        navio1 <= "0101";
                    elsif navio1 = "1000" then 
                        navio1 <= "0111";
                    elsif navio1 = "1001" then 
                        navio1 <= "1110";
                    elsif navio1 = "1010" then 
                        navio1 <= "0100";
                    elsif navio1 = "1011" then 
                        navio1 <= "1011";
                    elsif navio1 = "1100" then 
                        navio1 <= "1000";
                    elsif navio1 = "1101" then 
                        navio1 <= "1101";
                    elsif navio1 = "1110" then 
                        navio1 <= "0011";
                    elsif navio1 = "1111" then 
                        navio1 <= "0010";
                    end if;
                end if;
                prox_estado <= navio2set;  
            when navio2set => 
                if key2'event then
                    navio2a(0) <= sw0;
                    navio2a(1) <= sw1;
                    navio2a(2) <= sw2;
                    navio2a(3) <= sw3;
                    if navio2a(0) = '0' and navio2a(1) = '0' and navio2a(2) = '0' and navio2a(3) = '0' then
                        navio2a <= "0001";
                         if sw4 = '0' then
                            navio2b <= "1111";
                        else
                            navio2b <= "0111";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '0' and navio2a(2) = '0' and navio2a(3) = '1' then
                        navio2a <= "1100";
                        if sw4 = '0' then
                            navio2b <= "1101";
                        else
                            navio2b <= "1100";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '0' and navio2a(2) = '1' and navio2a(3) = '0' then
                        navio2a <= "1010";
                        if sw4 = '0' then
                            navio2b <= "1011";
                        else
                            navio2b <= "1001";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '0' and navio2a(2) = '1' and navio2a(3) = '1' then
                        navio2a <= "1111";
                        if sw4 = '0' then
                            navio2b <= "1001";
                        else
                            navio2b <= "1011";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '1' and navio2a(2) = '0' and navio2a(3) = '0' then
                        navio2a <= "0110";
                        if sw4 = '0' then
                            navio2b <= "1000";
                        else
                            navio2b <= "0010";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '1' and navio2a(2) = '0' and navio2a(3) = '1' then
                        navio2a <= "0000";
                        if sw4 = '0' then
                            navio2b <= "0000";
                        else
                            navio2b <= "1010";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '1' and navio2a(2) = '1' and navio2a(3) = '0' then
                        navio2a <= "1001";
                        if sw4 = '0' then
                            navio2b <= "0010";
                        else
                            navio2b <= "1101";
                        end if;
                    elsif navio2a(0) = '0' and navio2a(1) = '1' and navio2a(2) = '1' and navio2a(3) = '1' then
                        navio2a <= "0101";
                        if sw4 = '0' then
                            navio2b <= "0100";
                        else
                            navio2b <= "0110";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '0' and navio2a(2) = '0' and navio2a(3) = '0' then
                        navio2a <= "0111";
                        if sw4 = '0' then
                            navio2b <= "0100";
                        else
                            navio2b <= "1011";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '0' and navio2a(2) = '0' and navio2a(3) = '1' then
                        navio2a <= "1110";
                        if sw4 = '0' then
                            navio2b <= "0011";
                        else
                            navio2b <= "0010";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '0' and navio2a(2) = '1' and navio2a(3) = '0' then
                        navio2a <= "0100";
                        if sw4 = '0' then
                            navio2b <= "0111";
                        else
                            navio2b <= "1100";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '0' and navio2a(2) = '1' and navio2a(3) = '1' then
                        navio2a <= "1011";
                        if sw4 = '0' then
                            navio2b <= "1010";
                        else
                            navio2b <= "0011";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '1' and navio2a(2) = '0' and navio2a(3) = '0' then
                        navio2a <= "1000";
                        if sw4 = '0' then
                            navio2b <= "0110";
                        else
                            navio2b <= "0001";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '1' and navio2a(2) = '0' and navio2a(3) = '1' then
                        navio2a <= "1101";
                        if sw4 = '0' then
                            navio2b <= "1001";
                        else
                            navio2b <= "0110";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '1' and navio2a(2) = '1' and navio2a(3) = '0' then
                        navio2a <= "0011";
                        if sw4 = '0' then
                            navio2b <= "1111";
                        else
                            navio2b <= "1000";
                        end if;
                    elsif navio2a(0) = '1' and navio2a(1) = '1' and navio2a(2) = '1' and navio2a(3) = '1' then
                        navio2a <= "0010";
                        if sw4 = '0' then
                            navio2b <= "1110";
                        else
                            navio2b <= "0100";
                        end if;
                    end if;
                end if;
                prox_estado <= start;
        when start =>
            hex0 <= '1';
            hex2 <= '1';
            hex3 <= '1';
            hex4 <= '1';  
            hex5 <= '1';  
            hex6 <= '1'; 
             if key2'event and key2 = '1' then
                disparos := disparos -1;
                posicao_disparo(0) <= sw0;
                posicao_disparo(1) <= sw1;
                posicao_disparo(2) <= sw2;
                posicao_disparo(3) <= sw3;
             elsif key2'event and key2 = '0' then
                if (posicao_disparo = navio1) or
                    (posicao_disparo = navio2a) or
                    (posicao_disparo = navio2b) then 
                    acertos := acertos + 1;
                    ledacerto <= '1';
                    chance := 1;
                else
                    chance := 0;
                    ledacerto <= '0';
                end if;
                    
                if disparos = 0 then
                    if chance = 1 then
                        disparos:= disparos +1;
                    else
                        ledlose <= '1';
                        hex0 <= '1';
                        hex1 <= '1';
                        hex2 <= '1';
                        hex4 <= '1';
                        hex3 <= '1'; 
                        hex5 <= '1';  
                        hex6 <= '0'; 
                    end if;
                end if;
                if acertos = 3 then
                    ledwin <= '1';
                end if;
                if disparos = 5 then
                    hex0 <= '1';
                    hex1 <= '0';
                    hex2 <= '1';
                    hex4 <= '0';
                    hex3 <= '1'; 
                    hex5 <= '1';  
                    hex6 <= '1'; 
                elsif disparos = 4 then
                    hex0 <= '0';
                    hex1 <= '1';
                    hex2 <= '1';
                    hex3 <= '0';
                    hex4 <= '0';  
                    hex5 <= '1';  
                    hex6 <= '1'; 
                elsif disparos = 3 then
                    hex0 <= '1';
                    hex1 <= '1';
                    hex2 <= '1';
                    hex3 <= '1';
                    hex4 <= '0';
                    hex5 <= '0';  
                    hex6 <= '1';  
                elsif disparos = 2 then
                    hex0 <= '1';
                    hex1 <= '1';
                    hex2 <= '0';
                    hex3 <= '1';
                    hex4 <= '1';
                    hex5 <= '0';  
                    hex6 <= '1'; 
                elsif disparos = 1 then
                    hex0 <= '0';
                    hex1 <= '1';
                    hex2 <= '1';
                    hex3 <= '0';
                    hex4 <= '0';
                    hex5 <= '0';
                    hex6 <= '0';
                end if;
            end if;
        end case;
    end process;

    process (key1, key0)
    begin
        if key0 = '1' then
            estado_atual <= inicio;
        elsif (key1'event and key1 = '1') then
            estado_atual <= prox_estado;
        end if;
    end process;
     
     ledstart <= '1' when estado_atual = start else '0';
end Behavior;

