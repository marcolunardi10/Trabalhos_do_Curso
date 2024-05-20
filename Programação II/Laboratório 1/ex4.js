let n1, n2;

n1 = parseInt(prompt("Informe o primeiro operando: "));
n2 = parseInt(prompt("Informe o segundo operando: "));
multi(n1, n2);


function multi(n1, n2){
    let r = 0;
    for(i=0; i<n2; i++){
        r+= n1;
    }
    console.log("Resultado: " + r);
}
