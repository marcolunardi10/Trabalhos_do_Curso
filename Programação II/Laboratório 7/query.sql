CREATE TABLE curso (
    id SERIAL PRIMARY KEY,
    nome TEXT NOT NULL,
    descricao TEXT NOT NULL
);

--       GET        --
SELECT * FROM curso


--       GET BY ID       --
SELECT * FROM curso WHERE id = $1, idCurso


--       POST        --
INSERT INTO curso (nome, descricao) VALUES ($1, $2) RETURNING *


--       PUT        --
UPDATE curso SET nome = $1, descricao = $2 WHERE id = $3 RETURNING *


--      DELETE       --
DELETE FROM curso WHERE id = $1