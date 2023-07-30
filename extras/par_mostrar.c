 #include<stdio.h>
 #include<stdlib.h>

 int par(int vet[], int n){
int contador;
int pares = 0;
for(contador = 0; contador < n; contador++){
    if(vet[contador] % 2 == 0){
    printf(" \nnumeros pares:%d\n", vet[contador]);
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
    printf("\nInforme o %d valor do vetor:\n", contador+1);
    scanf("%d",&vetor[contador]);
}
   int total = par(vetor,n);
   printf(" Qunantidade de numeros pares: %d",total);
   free(vetor);
   return 0;
 }