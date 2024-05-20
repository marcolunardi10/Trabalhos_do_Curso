const express = require('express');
const body = require('body-parser');
const app = express();
const path = require('path');
app.use(body.json());
app.use(express.static('public'));
const pgp = require("pg-promise")({});
const usuario = "postgres";
const senha = "1234";
const host = "localhost";
const porta = "5432";
const banco_de_dados = "Banco1";
const db = pgp(`postgres://${usuario}:${senha}@${host}:${porta}/${banco_de_dados}`);


app.listen(3001, () => console.log("Servidor rodando na porta 3001"));


app.get("/index", (req, res) => {
    const filePath = path.join(__dirname, 'public', 'index.html');
    res.sendFile(filePath);
});


app.get("/cursos", async (req, res) => {
    const cursos = await db.any("SELECT * FROM curso");
    res.json(cursos);
    });


app.get("/curso/:id", async (req, res) => {
    const idCurso = parseInt(req.params.id);
    const curso = await db.oneOrNone("SELECT * FROM curso WHERE id = $1", idCurso);
    res.json(curso);
});


app.post("/cursos", async (req, res) => {
    const { nome, descricao } = req.body;
    const novoCurso = await db.one(
        "INSERT INTO curso (nome, descricao) VALUES ($1, $2) RETURNING *",
        [nome, descricao]
    );
    res.json({ message: "Curso inserido!", curso: novoCurso });
});


app.put("/curso/:id", async (req, res) => {
    const idCurso = parseInt(req.params.id);
    const { nome, descricao } = req.body;
    const cursoAtualizado = await db.oneOrNone(
        "UPDATE curso SET nome = $1, descricao = $2 WHERE id = $3 RETURNING *",
        [nome, descricao, idCurso]
    );
    res.json({ message: "Curso atualizado!", curso: cursoAtualizado });
});


app.delete("/curso/:id", async (req, res) => {
    const idCurso = parseInt(req.params.id);
    const cursoDeletado = await db.result(
        "DELETE FROM curso WHERE id = $1",
        [idCurso],
        r => r.rowCount
    );
    res.json({ message: "Curso excluído!" });
});




// para inserir na lista, use push:
// db.cursos.push({ ... })


// para remover da lista, use splice passando o índice do elemento e a quantidade de
// elementos a serem removidos. Exemnplo para remover o primeiro elemento:
// db.cursos.splice(0, 1) remove um elemento a partir do índice 0
