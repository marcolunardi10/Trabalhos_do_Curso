/**
 * @file Trabalho2.c
 * @author Marco_Aurélio_Lunardi
 * @version 0.3
 * @date 2023-09-19
 *
 * @copyright Copyright (c) 2023
 *
 *
  * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b);
void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void quickSort(int *A, int low, int high);
void heapSort(int *A, int size);
void radixSort(int *A, int size);

long double contador_bubble = 0;
long double contador_selection = 0;
long double contador_insertion = 0;
long double contador_quick = 0;
long double contador_heap = 0;
long double contador_radix = 0;


int main(){

	int i;
    long int tamanhoVetor = 100;
	int *vetor = (int*)malloc(tamanhoVetor*sizeof(int));
    srand(time(NULL));

     for (int i=0; i< tamanhoVetor; i++){
        vetor[i]=(rand()%1000);
    } 

	printf("\nVetor original: ");
	for (i = 0 ; i < tamanhoVetor ; i++)
    	printf("%d ", vetor[i]);

	printf("\nVetor tamanho = %ld\n", tamanhoVetor);


	// bubble sort
	int sortVec[tamanhoVetor];
	copia(vetor, sortVec, tamanhoVetor);
    clock_t begin = clock();
	bubbleSort(sortVec, tamanhoVetor);
    clock_t end = clock();
    double time_spent_bubble = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nBubble sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n");


	// selection sort
    copia(vetor, sortVec, tamanhoVetor);
    begin = clock();
    selectionSort(sortVec,tamanhoVetor);
    end = clock();
    double time_spent_selection = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nSelection sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n");
   


	// insertion sort
    copia(vetor, sortVec, tamanhoVetor);
    begin = clock();
    insertionSort(sortVec,tamanhoVetor);
    end = clock();
    double time_spent_insertion = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nInsertion sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n");
    


	// quick sort
    copia(vetor, sortVec, tamanhoVetor);
    begin = clock();
    quickSort(sortVec, 0, tamanhoVetor-1);
    end = clock();
    double time_spent_quick = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nQuick sort: ");
	for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n");



    // heap sort
    copia(vetor, sortVec, tamanhoVetor);
    begin = clock();
    heapSort(sortVec, tamanhoVetor);
    end = clock();
    double time_spent_heap = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nHeap sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n");

    // radix sort
    copia(vetor, sortVec, tamanhoVetor);
    begin = clock();
    radixSort(sortVec, tamanhoVetor);
    end = clock();
    double time_spent_radix = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nRadix sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++){
    	printf("%d ", sortVec[i]);
    }
	printf("\n\n");


    printf("Numero de trocas bubble sort: %.0Lf \t tempo gasto: %f\n", contador_bubble, time_spent_bubble);
    printf("Numero de trocas selection sort: %.0Lf \t tempo gasto: %f\n", contador_selection, time_spent_selection);
    printf("Numero de trocas insertion sort: %.0Lf  tempo gasto: %f\n", contador_insertion, time_spent_insertion);
    printf("Numero de trocas quick sort: %.0Lf \t tempo gasto: %f\n", contador_quick, time_spent_quick);
    printf("Numero de trocas heap sort: %.0Lf \t tempo gasto: %f\n", contador_heap, time_spent_heap);
    printf("Numero de trocas radix sort: %.0Lf \t tempo gasto: %f\n", contador_radix, time_spent_radix);
    printf("\n");


	return 0;
}

void copia(int *A, int *V, int size){
	int i;
	for (i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void swap (int *a, int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
}


void bubbleSort(int *A, int size) {
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++){
            if (A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                contador_bubble++;
            }
        } 
    }
}

void insertionSort(int *A, int size){ 

    int i,j, min;

    for (i = 1; i < size; i++) {   
        
        min=A[i];
        for (j=i; j>=1 && min< A[j-1];j--){
            A[j]=A[j-1];
            contador_insertion++;
        }   
        A[j]=min;
        contador_insertion++;
    }
}

void selectionSort(int *A, int size){
    
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }

        
        if (min_index != i) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
            contador_selection++;
        }
    }
}

int partition(int *A, int low, int high){
    int pivo = A[high];
    int i = low -1;

    for(int j = low; j<= high-1; j++){
        if(A[j] < pivo){
            i++;
            swap(&A[i], &A[j]);
            contador_quick++;
        }
    }
    swap(&A[i+1], &A[high]);
    contador_quick++;
    return (i+1);
}

void quickSort(int *A, int low, int high){
    if(low < high){
        int pivo = partition(A,low,high);

        quickSort(A, low, pivo-1);
        quickSort(A, pivo + 1, high);
    }
}

void criaHeap(int *A, int i, int size){
    int maior = i, esq= 2*i+1, dir = 2*i+2;
    
    if(esq < size && A[esq] > A[i]){
        maior = esq;
    }
    if(dir < size && A[dir] > A[maior]){
        maior = dir;
    }

    if(maior != i){
        swap(&A[i], &A[maior]);
        contador_heap++;
        criaHeap(A, maior, size);
    }
}

void heapSort(int *A, int size){
    for(int i= (size/2)-1; i >= 0; i--){
        criaHeap(A,i,size);
    }

    for(int i=size-1; i>=0; i--){
        swap(&A[0],&A[i]);
        contador_heap++;
        criaHeap(A,0,i);
    }

}

int buscaMax(int *A, int size){
    int max = A[0];
    for(int i=0;i<size;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}


void countingSort(int *A, int size, int pos){
    int aux[size];
    int count[10] = {0,0,0,0,0,0,0,0,0,0};
    int digito;

    for(int i=0;i<size;i++){
        digito = (A[i]/pos) %10;
        count[digito]++;
    }

    for(int i = 1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    for(int i = size-1; i>=0; i--){
        digito = (A[i]/pos) %10;
        count[digito]--;
        aux[count[digito]] = A[i];
    }

    for(int i=0; i< size; i++){
        A[i] = aux[i];
        contador_radix++;
    }
}

void radixSort(int *A, int size){
    int max = buscaMax(A, size);

    for(int i=1; max/i>0; i*=10){
        countingSort(A, size, i);
    }
}
