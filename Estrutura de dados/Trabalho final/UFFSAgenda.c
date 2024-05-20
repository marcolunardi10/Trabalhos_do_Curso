#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.c"

int main(){

    Evento *first = NULL, *novoEvento;
    int opcao, contadorDeEvento=1;
    menu();
    scanf("%d", &opcao);

    while(opcao != 6){
        switch(opcao){
            case 1: novoEvento = (Evento*)malloc(sizeof(Evento));
                    novoEvento = setaEvento(novoEvento,contadorDeEvento);
                    first = adicionaEvento(first, novoEvento);
                    contadorDeEvento++;
            break;

            case 2: if(first == NULL){
                        printf("\nA lista esta vazia!\n");
                    }else{
                        consultaEvento(first);
                    }
            break;

            case 3: if(first == NULL){
                        printf("\nA lista esta vazia!\n");
                    }else{
                        first = excluirEvento(first);
                    }
            break;

            case 4: if(first == NULL){
                        printf("\nA lista esta vazia!\n");
                    }else{
                        first = alterarEvento(first);
                    }
            break;
            
            case 5: if(first == NULL){
                        printf("\nA lista esta vazia!\n");
                    }else{
                        listaEvento(first);
                    }
            break;

            default : printf("Digite uma opcao valida\n");
        }
        menu();
        scanf("%d", &opcao);
    }
    liberaMemoria(first);
    
    return 0;
}