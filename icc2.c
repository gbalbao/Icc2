/* Introdução à Ciência da Computação II SSC0503 - Professor: Adenilso da Silva Simão

Métodos de ordenação: Seleção e Bolha

Sarah Piske Dalmoro
Ravila Vilela Pieri
Gustavo Balbão Santos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort();
void selection_sort();

void bubble_sort(int *v, int t) {

    int ultima_troca = 0; // parametro de controle da ultima troca

    if(t == 1) // quando a funcao recebe o tamanho do vetor == 1, nao ha mais trocas possiveis
        return;

    int flag = 0; // parametro de controle se houve troca ou nao
        
    for(int j = 0; j < t-1; j++) {
            
        printf("C %d %d\n", j, j+1);

        if(v[j] > v[j+1]) {  

            printf("T %d %d\n", j, j+1);

            // troca entre  v[j] (valor maior) e v[j+1] (valor menor)
            int aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            flag++;
            ultima_troca = j+1; // armazena a informação da ultima posicao trocada
        } 

    }
        
    if(flag == 0) // nenhuma troca foi realizada e o vetor está ordenado
            return; 
    else
        bubble_sort(v, ultima_troca); // recursao da funcao, passando o vetor e o tamanho do vetor igual a ultima troca
}

void selection_sort(int *v, int t) {
    
    for(int i = 0; i < t-1; i++) {

        int j, posicao_menor = i; // parametro que irá guardar a posicao de menor valor; inicializado com o valor de i a cada ciclo

        for(j = i+1; j < t; j++){

            printf("C %d %d\n", posicao_menor, j);
            
            if(v[j] < v[posicao_menor]) { // se encontrar um valor menor, posicao_menor recebe o indice desta nova posicao menor
                posicao_menor = j;
            } 
        }
        
        if(i != posicao_menor) { // se i == posicao_menor, valores menores nao foram encontrados no laco anterior e nao ha trocas a fazer

            printf("T %d %d\n", i, posicao_menor);
            
            // troca entre  v[i] (valor maior) e v[posicao_menor] (valor menor)
            int x = v[i];
            v[i] = v[posicao_menor];
            v[posicao_menor] = x;
        }
    }
}

int main() {

    int tamanho, i, *p;
    char metodo[7];

    scanf("%s", metodo);
    scanf("%d" , &tamanho);

    p = (int*) malloc(tamanho * sizeof(int)); // alocacao dinamica do vetor conforme tamanho de entrada

    for(i = 0; i < tamanho ; i++) { // leitura dos valores
        scanf("%d" , &p[i]);
    }

    if(strcmp(metodo,"selecao") == 0) { // compara a string de entrada com os dois metodos, selecao e bolha
        selection_sort(p, tamanho); // executa a funcao se a entrada for selecao
    } else if(strcmp(metodo,"bolha") == 0) {
        bubble_sort(p,tamanho); // executa a funcao se a entrada for bolha
    }
    
    for(i = 0; i < tamanho; i++) { // imprime o vetor ordenado
        printf("%d ", p[i]);
    }

    free(p); // libera o vetor alocado

    return 0;
}