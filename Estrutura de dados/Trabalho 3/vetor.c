#include <stdio.h>
#include <math.h>           //adicionar o comando "-lm" na hora da compilação, caso contrário ira ocorrer um erro
#include "vetor.h"  

v2d atribVetor(int a, int b){  //funçao que atribui valores inteiros passados por parâmetro a um vetor bidimensional e retorna este vetor
    v2d vet;                   //cria uma variavel do tipo vetor bidimensional
    vet.p1 = a;                //atribui o valor de "a" à primeira posição do vetor
    vet.p2 = b;                //atribui o valor de "b" à primeira posição do vetor
    return vet;                //retorna o vetor bidimensional para o chamador da funcao
}

void imprimeVetor(v2d v){      //funçao que recebe um vetor bidimensional como parâmetro e imprime na tela o valor das suas posições
    printf("<%d,%d>", v.p1, v.p2);
}

v2d somaVetor(v2d v1, v2d v2){          //função que recebe dois vetores bidimensionais por parâmetro e retorna um novo vetor com a soma das posicoes dos mesmos
        v2d resultado;                  //cria um vetor bidimensional que ira armazenar o resultado da soma
        resultado = atribVetor(v1.p1 + v2.p1, v1.p2 + v2.p2);     //realiza a soma das posiçoes e as atribui no vetor resultado utilizando a funcao de atribuicao
    return resultado;                   //retorna o vetor com o resultado da soma para o chamador da função
}

v2d subVetor(v2d v1, v2d v2){           //função que recebe dois vetores bidimensionais por parâmetro e retorna um novo vetor com a diferença das posicoes dos mesmos
        v2d resultado;                  //cria um vetor bidimensional que ira armazenar o resultado da subtração
        resultado = atribVetor(v1.p1 - v2.p1, v1.p2 - v2.p2);   //realiza a subtração das posiçoes e as atribui no vetor resultado utilizando a funcao de atribuicao
    return resultado;                   //retorna o vetor com o resultado da soma para o chamador da função
}       

int produtoInterno(v2d v){      //funcao que recebe um vetor bidimensional por parâmetro, calcula seu produto interno e retorna o resultado
    int produto;
    produto = v.p1*v.p1 + v.p2*v.p2;
    return produto;
}

float modulo(v2d v){
    float modulo;
    modulo = sqrt(produtoInterno(v));
    return modulo;
}

