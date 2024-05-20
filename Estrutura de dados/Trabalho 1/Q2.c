#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float preco;
	int opcao;
	
    printf("Informe o preco do produto\nPreco: ");
    	scanf("%f", &preco);
    
    printf("\nInforme agora a forma de pagamento\n1: A vista\n2: A prazo\n");
    	scanf("%i", &opcao);
    	
    if(opcao != 1 && opcao != 2){
    	printf("Opcao invalida\n");
	}else{
		if(opcao == 1){
			printf("Preco a vista: %.2f\n", preco - (preco/100)*5);
		}else{
			printf("Preco a prazo: %.2f\n", preco + (preco/100)*10);
		}
	}
  
	return 0;
}
