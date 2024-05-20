#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void salvaVetor(int *vetor, FILE *fp){
    for(int i=0;i<500;i++){
        fprintf(fp, "%d\n", vetor[i]);
    }
}

void removeValores(int *vetor, FILE *fp){
    double media = 0;
    fclose(fp);
    fp = fopen("vetor2.txt", "w");
    for(int i=0; i<500; i++){
        media = media + vetor[i];
    }
    media = media/500;
    printf("%f", media);

    for(int i=0; i<500; i++){
        if(vetor[i] < media){
            fprintf(fp, "%d\n", vetor[i]);
        }
    }
}

int main(){

    FILE* fp = fopen("vetor2.txt", "w");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    srand(time(NULL));

    int vetor[500];
    for(int i=1; i<501; i++){
        vetor[i-1] = (rand()%100);
    }

    salvaVetor(vetor,fp);
    removeValores(vetor, fp);


    fclose(fp);

    return 0;
}