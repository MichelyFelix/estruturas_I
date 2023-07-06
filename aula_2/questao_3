#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(void){
    int ordem; 
     do {
        printf("informe a ordem da matriz:\n");
        scanf("%d", &ordem);
        if (ordem <= 0) {
            printf("Valor inválido!\n");
        }
    } while (ordem <= 0);
    int **matriz = (int**)calloc(ordem,sizeof(int*));
        if (matriz==NULL){
        printf("erro de alocação");
        exit(1);
        }
        for (int contador = 0; contador<ordem; contador++){
            matriz[contador] = (int*)calloc(ordem,sizeof(int));
        }
    srand(time(NULL));
    for(int contador= 0; contador<ordem;contador++){
    for (int contador2 = 0; contador2<ordem; contador2++){
        matriz [contador][contador2]= rand()%100;
    } 
    }
     printf("resultado da Matriz:\n");
    for (int contador = 0; contador < ordem; contador++) {
        for (int contador2 = 0; contador2 < ordem; contador2++) {
            printf("%d ", matriz[contador][contador2]);
        }
        printf("\n");
    }
    for(int contador = 0;contador<ordem;contador++){
        free(matriz[contador]);
    }
    free(matriz);
    return 0;
}