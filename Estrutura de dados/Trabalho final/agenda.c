#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

Evento *setaEvento(Evento *novoEvento, int codigo){
    
    novoEvento->codigo = codigo;

    printf("Informe a data do evento: ");
    scanf("%d %d %d", &novoEvento->dataEvento.dia,&novoEvento->dataEvento.mes, &novoEvento->dataEvento.ano);

    printf("Informe o horario do evento: ");
    scanf("%d %d", &novoEvento->dataEvento.hora, &novoEvento->dataEvento.minuto);

    printf("Informe a duracao do evento: ");
    scanf("%f", &novoEvento->duracao);

    printf("Descreva o evento: ");
    getchar();
    fgets(novoEvento->descricao, sizeof(novoEvento->descricao), stdin);
    novoEvento->descricao[strcspn(novoEvento->descricao, "\n")] = '\0'; 
        
    novoEvento->proximo = NULL;

    return novoEvento;
}


Evento *adicionaEvento(Evento *first, Evento *novo_evento) {
    
    Evento *aux, *aux_ant = NULL;

    if (first == NULL) {
        first = novo_evento;
        printf("\n--------------Evento adicionado--------------\n");
        return first;
    }

    for (aux = first;aux!=NULL;aux=aux->proximo) {
        if(aux->dataEvento.ano==novo_evento->dataEvento.ano && aux->dataEvento.mes == novo_evento->dataEvento.mes && aux->dataEvento.dia == novo_evento->dataEvento.dia
         && aux->dataEvento.hora == novo_evento->dataEvento.hora && aux->dataEvento.minuto == novo_evento->dataEvento.minuto){
            printf("\nJá há um evento marcado para a data e hora escolhida\n");
            free(novo_evento);
            return first;
         }

        if (comparaData(novo_evento, aux) < 0) {
            break;
        }
        aux_ant = aux;
    }

    if (aux_ant == NULL) {
        novo_evento->proximo = first;
        first = novo_evento;
    } 
    else {
        aux_ant->proximo = novo_evento;
        novo_evento->proximo = aux;
    }
    printf("\n--------------Evento adicionado--------------\n");
    return first;
}


int comparaData(Evento *novo_evento, Evento *aux) {

    if (novo_evento->dataEvento.ano != aux->dataEvento.ano) {
        return novo_evento->dataEvento.ano - aux->dataEvento.ano;
    }
    if (novo_evento->dataEvento.mes != aux->dataEvento.mes) {
        return novo_evento->dataEvento.mes - aux->dataEvento.mes;
    }
    if (novo_evento->dataEvento.dia != aux->dataEvento.dia) {
        return novo_evento->dataEvento.dia - aux->dataEvento.dia;
    }
    if (novo_evento->dataEvento.hora != aux->dataEvento.hora) {
        return novo_evento->dataEvento.hora - aux->dataEvento.hora;
    }
    if (novo_evento->dataEvento.minuto != aux->dataEvento.minuto) {
        return novo_evento->dataEvento.minuto - aux->dataEvento.minuto;
    }
    return 0;
}


void consultaEvento(Evento *first){

    int escolha, i=0;
    Evento *aux;
    Data d;

    printf("\nEscolha o tipo de consulta a ser realizado\n1. Consulta por data\n2. Consulta por data e hora\n\n");
    scanf("%d", &escolha);

    switch(escolha){
        case 1: printf("Digite a data para consulta: ");
                scanf("%d %d %d", &d.dia, &d.mes, &d.ano);
                printf("\nEventos do dia %d/%d/%d\n", d.dia, d.mes, d.ano);

                for(aux = first; aux!=NULL; aux = aux->proximo){
                    if(aux->dataEvento.ano==d.ano && aux->dataEvento.mes == d.mes && aux->dataEvento.dia == d.dia){
                        printf("-----------------------------------------------\n");
                        printf("Codigo do evento: %d\nHorario: %d:%d\n", aux->codigo,aux->dataEvento.hora,aux->dataEvento.minuto);
                        printf("Duracao do evento: %.2fhr\n", aux->duracao);
                        printf("Descricao do evento: %s\n", aux->descricao);
                        i++;
                    }
                }
                if(i==0){
                    printf("\nAgenda Vazia\n");
                }
                break;

        case 2: printf("Digite a data para consulta: ");
                scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

                printf("Digite a hora para consulta: ");
                scanf("%d %d", &d.hora, &d.minuto);

                for(aux = first; aux!=NULL; aux = aux->proximo){
                    if(aux->dataEvento.ano==d.ano && aux->dataEvento.mes == d.mes && aux->dataEvento.dia == d.dia 
                    && aux->dataEvento.hora == d.hora && aux->dataEvento.minuto == d.minuto){
                        printf("\n-----------------------------------------------");
                        printf("\nCodigo do evento: %d\nHorario: %d:%d\n", aux->codigo,aux->dataEvento.hora,aux->dataEvento.minuto);
                        printf("Duracao do evento: %.2fhr\n", aux->duracao);
                        printf("Descricao do evento: %s\n", aux->descricao);
                        i++;
                    }
                }
                if(i==0){
                    printf("\nAgenda Vazia\n");
                }
                break;
    }
    return;
}


Evento *alterarEvento(Evento *first){

    Data d;
    Evento *aux;

    printf("Digite a data do evento a ser alterado: ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    printf("Digite a hora do evento a ser alterado: ");
    scanf("%d %d", &d.hora, &d.minuto);

    for(aux = first; aux!=NULL; aux = aux->proximo){
        if(aux->dataEvento.ano==d.ano && aux->dataEvento.mes == d.mes && aux->dataEvento.dia == d.dia 
        && aux->dataEvento.hora == d.hora && aux->dataEvento.minuto == d.minuto){
            printf("\nQual a nova duração do evento: ");
            scanf("%f", &aux->duracao);
            printf("Qual a nova descricao do evento: ");
            getchar();
            fgets(aux->descricao, sizeof(aux->descricao), stdin);
            aux->descricao[strcspn(aux->descricao, "\n")] = '\0';
            printf("\nCompromisso alterado com sucesso\n");
            return first;
        }
    }
    printf("\nCompromisso nao encontrado\n");
    return first;
}


Evento *excluirEvento(Evento *first){

    Data d;
    Evento *aux, *aux_ant = first;

    printf("Digite a data do evento a ser excluido: ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    printf("Digite a hora do evento a ser excluido: ");
    scanf("%d %d", &d.hora, &d.minuto);

    for(aux = first; aux!=NULL; aux = aux->proximo){
        if(aux->dataEvento.ano==d.ano && aux->dataEvento.mes == d.mes && aux->dataEvento.dia == d.dia 
        && aux->dataEvento.hora == d.hora && aux->dataEvento.minuto == d.minuto) break;
        aux_ant = aux;
        }

        if(aux==NULL){
            printf("\nCompromisso nao encontrado\n");
            return first;
        }

        if(aux==first){
            first=aux->proximo;
            free(aux);
            printf("\n--------------Evento excluido--------------\n");
            return first;
        }

        if (aux->proximo==NULL){
            aux_ant->proximo=NULL;
            free(aux);
            printf("\n--------------Evento excluido--------------\n");
            return first;
        }

        aux_ant->proximo=aux->proximo;
        free(aux);
        printf("\n--------------Evento excluido--------------\n");
        return first;
}


void listaEvento(Evento *first){

    Evento *aux;
    
    for(aux=first; aux!=NULL; aux = aux->proximo){
        printf("-----------------------------------------------");
        printf("\nCodigo do evento: %d\n",aux->codigo) ;
        printf("Data e hora do evento: %d/%d/%d as %d:%d\n",aux->dataEvento.dia,aux->dataEvento.mes,aux->dataEvento.ano,aux->dataEvento.hora,aux->dataEvento.minuto);
        printf("Duracao do evento: %.2fhr\n", aux->duracao);
        printf("Descricao do evento: %s\n", aux->descricao);
    }
}


void liberaMemoria(Evento *e) {
  if (e == NULL)
    return;
  free(e);
  liberaMemoria(e->proximo);
}


void menu(){
    printf("\nInforme a opcao desejada\n1. Incluir evento\n2. Consultar evento\n3. Excluir evento\n4. Alterar evento\n5. Listar eventos\n6. Sair\n\n");
}