#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int v[] , int t);
void selection_sort();

void bubble_sort(int v[], int t){
    int flag , x; 
    do{
        flag = 0;
        for(int i =0; i+1<t ; i++){
            printf("C %d %d\n", i,i+1 );
            if(v[i] > v[i+1]){
                printf("T %d %d\n", i, i+1);
                x = v[i+1];
                v[i+1] = v[i];
                v[i] = x;
                flag++;
                
            }
        }
        t--;
    }while(flag!=0);
    }

void selection_sort(int *v, int t){
	for (int i = 0; i < t; i++) {

		int posicao_menor = i;

		for (int j = i + 1; j < t; j++)
			if (v[j] < v[posicao_menor])
				posicao_menor = j;
		
		int x = v[i];
		v[i] = v[posicao_menor];
		v[posicao_menor] = x;
    }
}
int main()
{
    int tamanho,i,*p; // * significa ponteiro
    char metodo[7];

    printf("Selecione o metodo (selecao ou bolha):\n");
    scanf("%s", metodo);

    printf("Digite o tamanho do vetor:\n");
    scanf("%d" , &tamanho);
    p = (int*)malloc(tamanho*sizeof(int));

    printf("Digite os elementos do vetor:\n");
    for(i=0 ; i < tamanho ; i++){
        scanf("%d" , &p[i]);
    }


    if(strcmp(metodo,"selecao")==0){
        printf("Voce selecionou o metodo 'selecao' para a ordenacao do vetor\nAguarde...\n");
        selection_sort(p, tamanho);
    }
    else if (strcmp(metodo,"bolha")==0){
        printf("Voce selecionou o metodo 'bolha' para a ordenacao do vetor\nAguarde...\n");
        bubble_sort(p,tamanho);
    }
    else{
        printf("Erro! \nMetodo invalido!");
    }

}