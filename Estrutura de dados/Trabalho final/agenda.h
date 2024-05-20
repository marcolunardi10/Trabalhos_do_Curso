struct _data {
   int dia;
   int mes;
   int ano;
   int hora;
   int minuto;
};
typedef struct _data Data;


struct _evento {
   int codigo;
   Data dataEvento;
   float duracao;
   char descricao[100];
   struct _evento *proximo;
};
typedef struct _evento Evento;

Evento *setaEvento(Evento*,int);

Evento *adicionaEvento(Evento*, Evento*);

void consultaEvento(Evento*);

Evento *alterarEvento(Evento*);

Evento *excluirEvento(Evento*);

int comparaData(Evento*, Evento*);

void listaEvento(Evento*);

void liberaMemoria(Evento*);

void menu();