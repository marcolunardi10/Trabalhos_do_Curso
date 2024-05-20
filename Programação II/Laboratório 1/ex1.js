let horas, valor, salario;

horas = parseInt(prompt("Informe o numero de horas trabalhadas"));
valor = parseFloat(prompt("Agora informe o valor da hora trabalhada"));

salario = calculo(horas, valor);
console.log("Salário: " + salario);

function calculo(horas, valor){
    let salario = horas * valor;
    if(horas>200){
        salario = salario + (salario*0.05);
    }
    return salario;
}