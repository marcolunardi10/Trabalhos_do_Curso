 class Model {
    constructor() {
        this.temaEscuro = false;
        this.cursoAtual = 'cc';
    }

    setTema(temaEscuro) {
        this.temaEscuro = temaEscuro;
    }

    getTema() {
        return this.temaEscuro;
    }

    setCursoAtual(curso) {
        this.cursoAtual = curso;
    }

    getCursoAtual() {
        return this.cursoAtual;
    }
}

export default Model;
