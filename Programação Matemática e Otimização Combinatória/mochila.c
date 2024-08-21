#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila(int i, int c, int *p, int *v, int n){
    if(i>=n || c==0){
        return 0;
    }
    if(p[i] > c){
        return mochila(i+1, c , p, v, n);
    }
    return max(v[i] + mochila(i+1, c-p[i], p, v ,n), mochila(i+1, c, p, v, n));
}

int main(int argc, char *argv[]){

    int n, c,i,valor, peso, resposta;
    FILE *dados;
    dados = fopen("knapPI_1_200_1000_1", "r");
    fscanf(dados, "%d %d", &n, &c);
    printf("%d, %d", n,c);
    int v[n], p[n];

    for(int j = 0; j < n; j++){
        fscanf(dados, "%d %d", &p[j], &v[j]);
    }

    resposta = mochila(0,c,p,v,n);


    return 0;
}