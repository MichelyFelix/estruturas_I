/* Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
 e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois,
 no programa principal, o vetor preenchido deve ser impresso. Além disso, antes de finalizar o programa,
 deve-se liberar a área de memória alocada. */
#include<stdio.h>
#include<stdlib.h>

void ler(int *vetor,int n){
    int contador;
    for(contador = 0; contador < n; contador++){
    printf("Informe o elemento %d do vetor\n", contador + 1);
    scanf("%d",&vetor[contador]);
    }

}

int main(void){
int n;

printf("Informe o tamanho do vetor:\n");
scanf("%d", &n);

int *vetor = (int*)malloc(n*sizeof(int));
if(vetor == NULL){
    printf("Erro ao alocar memoria!");
    exit(1);
}

ler(vetor,n);
printf("Valores do vetor:\n");
for(int contador = 0; contador < n; contador++){
    printf("%d\t", vetor[contador]);
}
free(vetor);
return 0;
}
