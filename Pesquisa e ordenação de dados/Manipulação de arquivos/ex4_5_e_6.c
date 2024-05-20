#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarArquivo(){
    FILE* fp = fopen("exercicio4.txt", "w");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    fputs("Eu sei trabalhar com arquivos em C", fp);
    fclose(fp);
}

void modificarTexto(){
    FILE* fp = fopen("exercicio4.txt", "r+");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    fseek(fp, 30, 0);
    fputs("em todas as linguagens de programacao", fp);
    fclose(fp);
}

void adicionarQuase(){
    FILE* fp = fopen("exercicio4.txt", "r+");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    fseek(fp, 33, 0);
    char temp[50];
    fgets(temp, sizeof(temp), fp);
    fseek(fp, 33, 0);
    fputs("quase ", fp);
    fputs(temp, fp);
    fclose(fp);
}



int main(){

   criarArquivo();
   modificarTexto();
   adicionarQuase();


    return 0;
}