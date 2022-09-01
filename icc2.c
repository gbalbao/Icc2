#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int *v , int t);
void selection_sort();

void bubble_sort(int *v, int t){
    int flag , x; 
    do{
        flag = 0;
        for(int i =0; i<t ; i++){
            if(v[i] > v[i+1]){
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
    int metodo,tamanho,i,*p; // * significa ponteiro

    printf("Digite o tamanho do vetor:\n");
    scanf("%d" , &tamanho);
    p = (int*)malloc(tamanho*sizeof(int));

    printf("Digite os elementos do vetor:\n");
    for(i=0 ; i < tamanho ; i++){
        scanf("%d" , &p+1);
    }

    printf("Selecione o metodo (S ou B):\n");
    scanf("%s", &metodo);
    if(metodo == 'S' || metodo == 's'){
        printf("Voce selecionou o metodo 'selection' para a ordenacao do vetor\nAguarde...");
        //selection_sort()
    }
    else if (metodo == 'B' || metodo == 'b'){
    printf("Voce selecionou o metodo 'bubble' para a ordenacao do vetor\nAguarde...");
    bubble_sort(*p,tamanho);
    }
    else{
        printf("Erro! \nMetodo invalido!");
    }

}