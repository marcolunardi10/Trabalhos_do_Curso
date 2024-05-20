function PouN(){
   let p=0, n=0, n1;
   for(i=1;i<=4;i++){
        n1 = prompt("Informe um número");
        if(n1<0){
            n++;
        }else{
            p++;
        }
   }
   console.log(p + "(+) e " + n + "(-)");
}

PouN();
