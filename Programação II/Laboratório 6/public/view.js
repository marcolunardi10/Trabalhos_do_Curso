function mudarTema() {
    import('./controller.mjs').then((controller) => {
        const { mudaTema } = controller;
        mudaTema().then(response => {
            document.body.style.backgroundColor = response.backgroundColor;
            document.body.style.color = response.textColor;
            
            const botaoTema = document.getElementById('botao-tema');
            botaoTema.textContent = response.buttonText;
            botaoTema.classList.remove('btn-light', 'btn-dark');
            botaoTema.classList.add(response.buttonClasses);
            
            document.querySelectorAll('h1 span, h2 span').forEach(span => {
                span.classList.remove('bg-light', 'text-dark', 'bg-dark', 'text-light');
                const classes = response.spanClasses.split(' '); 
                span.classList.add(...classes); 
            });
        });
    })
}


function mudarCurso(courseType) {
    import('./controller.mjs').then((controller) => {
        const { mudaCurso } = controller;
        mudaCurso(courseType).then(response => {
            document.getElementById('container-cc').style.display = response.showCC ? 'block' : 'none';
            document.getElementById('container-fil').style.display = response.showFil ? 'block' : 'none';
        });
    })
}

document.getElementById('botao-tema').addEventListener('click', mudarTema);
document.getElementById('btnCC').addEventListener('click', () => mudarCurso('cc'));
document.getElementById('btnFil').addEventListener('click', () => mudarCurso('fil'));
