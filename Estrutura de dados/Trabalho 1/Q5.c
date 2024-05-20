#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int posicao;
	
    printf("Informe a posicao do competidor\nPosicao: ");
    scanf("%d", &posicao);	
    
    
    if(posicao<=0 || posicao >100){
    	printf("\nDigite um numero valido\n");
	}
	
	if(posicao>=1 && posicao <=5){
    	printf("\nTop 5\n");
	}
  
  	if(posicao>=6 && posicao <=10){
    	printf("\nTop 10\n");
	}
	
	if(posicao>=11 && posicao <=20){
    	printf("\nTop 20\n");
	}
	
	if(posicao>=21 && posicao <=30){
    	printf("\nTop 30\n");
	}
	
	if(posicao>30 && posicao<=100){
    	printf("\nTop 100\n");
	}
	
	return 0;
	
	}
