#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int inicio, fim;
	
    printf("Informe a hora de inicio do evento\nHora de inicio: ");
    	scanf("%d", &inicio);
    
    printf("\nInforme a hora de fim do evento\nHora de fim: ");
    	scanf("%d", &fim);
    
    
    if(inicio >= fim){
    	printf("\nDuracao: %i horas\n", fim + 24 - inicio);
	}else{
		printf("\nDuracao: %i horas\n", fim - inicio);
	}
    
    	

  
	return 0;
}
