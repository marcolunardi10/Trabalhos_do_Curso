#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int horas;
	float valor, salario;
	
    printf("Informe o numero de horas trabalhadas do funcionario\nHoras Trabalhadas: ");
    	scanf("%d", &horas);
    
    printf("\nInforme agora o valor da hora trabalhada do funcionario\nValor da Hora: ");
    	scanf("%f", &valor);
    
    salario = horas * valor;

	if(horas>=200){
		printf("\nSalario: %.2f\n", salario + (salario/100)*5);
	}
		else{
			printf("\nSalario: %.2f\n", salario);
			}
	return 0;
}
