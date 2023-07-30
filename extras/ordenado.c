/* Implemente uma função que preencha um vetor de N elementos com valores inteiros fornecidos via teclado,
 de modo que, à medida que um novo elemento é inserido, o vetor já permaneça organizado de maneira ordenada crescente. 
 Escreva um programa que utiliza esta função, que deve obedecer ao seguinte protótipo: void preenche_ordenado(int n, int* vet)*/

 #include<stdio.h>
 #include<stdlib.h>

 void preenche_ordenado(int n, int *vet){
int vetor;
int contador1;

for(contador1 = 0; contador1 < n; contador1++){
    printf("Informe o %d elemento do vetor:\n", contador1+1);
    scanf("%d", &vetor);

int contador2;
for (contador2 = contador1 - 1; contador2 >= 0 && vet[contador2] >  vetor; contador2--){
vet[contador2 + 1] = vet[contador2];
}
vet[contador2 + 1] = vetor;
 }
 }

 int main(void){
    int tam;
printf("Informe o tamanho do vetor:\n");
scanf("%d", &tam);

int *vetor = (int*)malloc(tam*sizeof(int));
if(vetor == NULL){
    printf(("Erro ao alocar memoria!"));
    exit(1);
}
preenche_ordenado(tam,vetor);
printf("\nElementos do vetor organizados em ordem crescente:\n");
for(int contador = 0; contador < tam; contador++){
    printf("%d\n",vetor[contador]);
}
free(vetor);
return 0;
 }