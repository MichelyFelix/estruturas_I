#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tamanho;
    printf("informe o tamanho do vetro:\n");
    scanf("%d", &tamanho);

    int *vetor = (int *)calloc(tamanho, sizeof(int));
    if (vetor == NULL)
    {
        printf("erro de alocacao");
        exit(1);
    }
    else
    {
        printf("alocacao realizada");
    }
    int contador;
    printf("informe os valores do vetor:\n");
    for (contador = 0; contador < tamanho; contador++)
    {
        scanf("%d", &vetor[contador]);
    }
    for (contador=tamanho-1;contador>=0 ; contador-- ){
        printf("\n%d\n", vetor[contador]);
    }
    free(vetor);
    return 0;

}