const calcArrow = (n) => {
    let r = 0;
    for(i=1;i<=n;i++){
        r += i;
    }
    return r;
}

let n;

n = parseInt(prompt("Informe um número: "));
console.log("Resultado: "+ calcArrow(n));
