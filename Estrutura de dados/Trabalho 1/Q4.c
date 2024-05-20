#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int numero, contador=0, i;
	
    printf("Informe 4 numeros inteiros\n");
    	
	for(i=0;i<4;i++){
		scanf("%d", &numero);
		if(numero >= 0){
			contador++;
		}
	}
	
	printf("Dos numeros digitados, existe(m) %d positivo(s) e %d negativo(s)\n", contador, 4-contador);
  
	return 0;
	
	}
