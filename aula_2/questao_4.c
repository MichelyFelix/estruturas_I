#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maximo 100

int main(void){
    int quant_pessoas,*vetor,contador;
    char **matriz;

    printf("informe a quantidade de pessoas que deseja armazenar:\n");
    scanf("%d",&quant_pessoas);

   if(quant_pessoas>maximo){
    printf("Quantidade  invalida");
    exit(1);
   }

    matriz = (char**)calloc(quant_pessoas,sizeof(char*));
    if (matriz == NULL){
        printf("erro de alocação\n");
        exit(1);
    }

    for(contador = 0; contador<quant_pessoas; contador++){
        matriz[contador] = (char*)calloc(maximo,sizeof(char));
        printf("informe o nome completo da %d pessoa:\n", contador+1);
            scanf(" %[^\n]", matriz[contador]);
    }

    vetor = (int*)calloc(quant_pessoas,sizeof(int));
    if (vetor == NULL){
        printf("erro de alocação");
        exit(1);
    }
        for(contador = 0; contador<quant_pessoas; contador++){
            printf("informe a idade da %d pessoa:\n",contador+1);
            scanf("%d",&vetor[contador]);
        }
        printf("\nnomes:\n");
        for(contador = 0; contador<quant_pessoas;contador++){
            printf("%s\n",matriz[contador]);
        }
        for(contador = 0; contador<quant_pessoas; contador++){
            free(matriz[contador]);
        }
        free(matriz);
        free(vetor);
        return 0;
}