#include <stdio.h>
#include <stdlib.h>

void salvaVetor(int *vetor, FILE *fp){
    for(int i=0;i<10;i++){
        fprintf(fp, "vetor[%d] = %d\n", i, vetor[i]);
    }
}

int main(){

    FILE* fp = fopen("vetor.txt", "w");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    int vetor[10];
    for(int i=1; i<11; i++){
        vetor[i-1] = i;
    }

    salvaVetor(vetor,fp);


    fclose(fp);

    return 0;
}