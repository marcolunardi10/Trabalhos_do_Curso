let n, a=0, c=0;
do{
    n = prompt("Informe um número: ");
    a++;
    if(n>=10 && n<=20){
        c++;
    }
}while(n != 0);

console.log("% entre 10 e 20: " + parseFloat((c/(a-1))*100)+"%");