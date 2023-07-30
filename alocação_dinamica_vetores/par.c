/*implemente uma função que receba como parâmetro um vetor de números inteiros (vet) 
de tamanho n e retorne quantos números pares estão armazenados nesse vetor.
 Essa função deve obedecer ao protótipo: int pares(int n, int* vet);*/

 #include<stdio.h>
 #include<stdlib.h>

 int par(int vet[], int n){
int contador;
int pares = 0;
for(contador = 0; contador < n; contador++){
    if(vet[contador] % 2 == 0){
    pares++;
    }
}
return pares;
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
for(int contador = 0; contador < n; contador++){
    printf("Informe o %d valor do vetor:\n", contador+1);
    scanf("%d",&vetor[contador]);
}
   int total = par(vetor,n);
   printf(" Qunantidade de numeros pares: %d",total);
   free(vetor);
   return 0;
 }