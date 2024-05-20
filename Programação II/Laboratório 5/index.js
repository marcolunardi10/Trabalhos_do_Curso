const db = require('./database');
console.log(db.cursos[0]);
const express = require('express');
const body = require('body-parser');
const app = express();
const path = require('path');
app.use(body.json());
app.use(express.static('public'));


app.listen(3001, () => console.log("Servidor rodando na porta 3001"));

app.get("/index", (req, res) => {
    const filePath = path.join(__dirname, 'public', 'index.html');
    res.sendFile(filePath);
});

app.get("/cursos", (req, res) => {
        res.json(db.cursos);
    });

app.get("/curso/:id", (req, res) => {
    const idCurso = parseInt(req.params.id);
    const curso = db.cursos.find(curso => curso.id === idCurso);
        res.json(curso);
});


app.post("/cursos", (req, res) => {
    const novoCurso = req.body;
    db.cursos.push(novoCurso);
    res.json({ message: "Curso inserido!", curso: novoCurso });
});


app.put("/curso/:id", (req, res) => {
    const idCurso = parseInt(req.params.id);
    const Index = db.cursos.findIndex(curso => curso.id === idCurso);
    const cursoAtualizado = req.body;
    db.cursos[Index].nome = cursoAtualizado.nome;
    db.cursos[Index].turno = cursoAtualizado.turno;
    db.cursos[Index].id_campus = cursoAtualizado.id_campus;
    res.json({ message: "Curso atualizado!", curso: db.cursos[Index]});
});


app.delete("/curso/:id", (req, res) => {
    const idCurso = parseInt(req.params.id);
    const Index = db.cursos.findIndex(curso => curso.id === idCurso);
    db.cursos.splice(Index, 1);
    res.json({ message: "Curso excluído!" });
});



app.get("/ccrs", (req, res) => {
    res.json(db.ccrs);
});


app.get("/ccr/:id", (req, res) => {
    const idMateria = req.params.id;
    const materia = db.ccrs.find(materia => materia.id === idMateria);
    res.json(materia);
});


app.post("/ccrs", (req, res) => {
    const novaMateria = req.body;
    db.ccrs.push(novaMateria);
    res.json({ message: "Matéria inserida!", materia: novaMateria });
});


app.put("/ccr/:id", (req, res) => {
    const idMateria = req.params.id;
    const materiaAtualizada = req.body;
    const index = db.ccrs.findIndex(materia => materia.id === idMateria);
    db.ccrs[index] = materiaAtualizada;
    res.json({ message: "Matéria atualizada!", materia: materiaAtualizada });
});


app.delete("/ccr/:id", (req, res) => {
    const idMateria = req.params.id;
    const index = db.ccrs.findIndex(materia => materia.id === idMateria);
    db.ccrs.splice(index, 1);
    res.json({ message: "Matéria excluída!" });
});






// para inserir na lista, use push:
// db.cursos.push({ ... })


// para remover da lista, use splice passando o índice do elemento e a quantidade de
// elementos a serem removidos. Exemnplo para remover o primeiro elemento:
// db.cursos.splice(0, 1) remove um elemento a partir do índice 0
