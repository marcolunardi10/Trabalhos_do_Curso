import Model from './model.js';
const model = new Model();

export function mudaTema() {
    const temaescuro = !model.getTema();
    model.setTema(temaescuro);

    const response = {
        backgroundColor: temaescuro ? 'rgb(35, 41, 57)' : 'white',
        textColor: temaescuro ? 'white' : 'black',
        buttonText: temaescuro ? 'Claro' : 'Escuro',
        buttonClasses: temaescuro ? 'btn-light' : 'btn-dark', 
        spanClasses: temaescuro ? 'bg-dark text-light' : 'bg-light text-dark',
    };

    return Promise.resolve(response);
}

export function mudaCurso(curso) {
    model.setCursoAtual(curso);

    const response = {
        showCC: curso === 'cc',
        showFil: curso === 'fil',
    };

    return Promise.resolve(response);
}

