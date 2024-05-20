function fatorial(n){
    if(n==0 || n ==1){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

let n = parseInt(prompt("Informe um número: "));
console.log("O fatorial de " + n + " é: " + fatorial(n));