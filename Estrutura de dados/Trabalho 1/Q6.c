#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int idade;
	
    printf("Informe a idade\nIdade: ");
    scanf("%d", &idade);	
    
    if(idade>70 || (idade<18 && idade>=16)){
    	printf("\nVoto facultativo\n");
	}	else if(idade >=18 && idade<=70){
			printf("\nVoto obrigatorio\n");
			}else{
				printf("\nNão pode votar\n");
				}
	return 0;
	
	}
