let inicio, fim;

inicio = parseInt(prompt("Informe o horário de inicio do evento: "));
fim = parseInt(prompt("Informe o horário de fim do evento: "));
calculaTempo(inicio, fim);


function calculaTempo(inicio, fim){
    let duracao;
    if(fim < inicio){
        duracao = (24-inicio)+fim;
    }
    else{
        duracao = fim - inicio;
    }
    console.log("Duração: "+ duracao + " horas");
}
