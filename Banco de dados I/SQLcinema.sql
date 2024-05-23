--1. Altere o comentário Uau! Tooke my breath away!!! para Uau! Took my breath away!!!

SELECT * 
FROM avaliacao 
WHERE codf=10 
AND email='she@hotmail.com';
UPDATE avaliacao 
SET coment='Uau! Took my breath away!!!' 
WHERE codf=10 
AND email='she@hotmail.com';
  
-----------------------------------------------------------------------------------------------------------------------------------

--2. Insira o comentário Super fã dos filmes Tubarão do usuário jaws@gmail.com para o filme Jaws. Ele deu 5 estrelas.

INSERT INTO avaliacao (codf, email, nestrelas, coment) 
VALUES (30, 'jaws@gmail.com', 5, 'Super fã dos filmes Tubarão');

-----------------------------------------------------------------------------------------------------------------------------------

--3. Execute o seguinte INSERT:

INSERT INTO elenco (codf, codp, codpapel, oscar) 
VALUES (30,177,5,'N');

--Analise a mensagem de erro e cONserte o problema para que o comANDo acima seja re-executado da mesma forma que está escrito.

INSERT INTO pessoa (codp, nome, dtnasc, paisn) 
VALUES (177, 'FerdinAND', '1975-05-12', 'Canada');

--Não havia pessoa com codp valor 177, após adiciONar o código pode ser executaco sem erros.

-----------------------------------------------------------------------------------------------------------------------------------

--4. Retornar os nomes dos filmes com os nomes dos respectivos diretores

SELECT filme.titulo, pessoa.nome 
FROM filme
JOIN pessoa ON filme.codd=pessoa.codp;

-----------------------------------------------------------------------------------------------------------------------------------

--5. Retornar os nomes dos filmes dirigidos por Alfred

SELECT filme.titulo 
FROM filme 
JOIN pessoa ON filme.codd=pessoa.codp
AND pessoa.nome = 'Alfred';

-----------------------------------------------------------------------------------------------------------------------------------

--6. Retorne os nomes dos atores que já receberam um oscar (oscar=’Y’).

SELECT DISTINCT pessoa.nome 
FROM pessoa 
JOIN elenco ON pessoa.codp = elenco.codp 
AND elenco.oscar = 'Y';

-----------------------------------------------------------------------------------------------------------------------------------

--7. Retorne os nomes, anos de lançamento, duração dos filmes bem com os nomes dos atores que fizeram parte do elenco.

SELECT filme.titulo, filme.anol, filme.dur, pessoa.nome 
FROM filme 
JOIN elenco ON filme.codf=elenco.codf 
JOIN pessoa ON pessoa.codp = elenco.codp;

-----------------------------------------------------------------------------------------------------------------------------------

--8. Retornar os nomes dos filmes que receberam 5 estrelas na avaliação

SELECT DISTINCT filme.titulo 
FROM filme 
JOIN avaliacao ON filme.codf=avaliacao.codf 
AND avaliacao.nestrelas = 5.0;

-----------------------------------------------------------------------------------------------------------------------------------

--9. Retornar os nomes dos filmes que o ator Steven fez parte do elenco

SELECT filme.titulo 
FROM filme 
JOIN elenco ON filme.codf=elenco.codf
JOIN pessoa ON elenco.codp=pessoa.codp 
AND pessoa.nome='Steven';

-----------------------------------------------------------------------------------------------------------------------------------

--10. Retornar os nomes de todos os atores cadastros e os filmes que eles foram elenco, caso existirem.

SELECT pessoa.nome, filme.titulo 
FROM pessoa 
LEFT JOIN elenco ON pessoa.codp=elenco.codp
LEFT JOIN filme ON elenco.codf=filme.codf;

-----------------------------------------------------------------------------------------------------------------------------------

--11. Retornar os nomes das pessoas que não participaram de nenhum filme

SELECT pessoa.nome 
FROM pessoa
LEFT JOIN elenco ON pessoa.codp=elenco.codp
WHERE elenco.codp IS NULL;

-----------------------------------------------------------------------------------------------------------------------------------

--12. Retornar, caso existe, um filme que não possua nenhuma avaliação

SELECT filme.titulo 
FROM filme  
LEFT JOIN avaliacao ON filme.codf=avaliacao.codf
WHERE avaliacao.codf IS NULL;

-----------------------------------------------------------------------------------------------------------------------------------

--13. Retornar o nome e a duração dos filmes que foram lançados nos anos 1960

SELECT filme.titulo, filme.dur 
FROM filme 
WHERE anol BETWEEN 1960 AND 1969;

-----------------------------------------------------------------------------------------------------------------------------------

--14. Retornar os nomes dos atores que já tiveram o papel de figur em qualquer filme

SELECT pessoa.nome 
FROM pessoa 
JOIN elenco ON pessoa.codp=elenco.codp
WHERE elenco.codpapel = 5;

-----------------------------------------------------------------------------------------------------------------------------------

--15. Retornar quantos comentários o usuário cinefilo@gmail.com fez.

SELECT count(coment) 
FROM avaliacao 
WHERE email = 'cinefilo@yahoo.com';

-----------------------------------------------------------------------------------------------------------------------------------       

--16. Retornar o país e a quantidade de atores cadastrados nele

SELECT paisn, count(*)
FROM pessoa 
GROUP BY paisn;

-----------------------------------------------------------------------------------------------------------------------------------

--17. Retornar a pessoa mais velha cadastrada (pode existir mais de 1)

SELECT nome 
FROM pessoa 
WHERE dtnasc = (
    SELECT min(dtnasc) 
    FROM pessoa
);

-----------------------------------------------------------------------------------------------------------------------------------

--18. Retornar o filme com a menor duração (pode existir mais de 1)

SELECT titulo 
FROM filme 
WHERE dur = (
    SELECT min(dur) 
    FROM filme
);

-----------------------------------------------------------------------------------------------------------------------------------

--19. Retornar o nome do filme e número de atores no elenco

SELECT filme.titulo, count(elenco.codp) 
FROM filme 
JOIN elenco ON filme.codf=elenco.codf;

-----------------------------------------------------------------------------------------------------------------------------------

--20. Retornar o nome do filme e a média de número de estrela recebidas

SELECT filme.titulo, avg(avaliacao.nestrelas) 
FROM filme
JOIN avaliacao ON filme.codf=avaliacao.codf
GROUP BY filme.codf, filme.titulo
ORDER BY filme.titulo;
        
