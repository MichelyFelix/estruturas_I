
#include<stdio.h>
#include<stdlib.h>

float *soma(float * vetor1, float * vetor2, int tam){
    int contador;
float* resul = (float*)calloc(tam,sizeof(float));
if(resul == NULL){
    exit(1);
}
for (contador = 0; contador < tam; contador++){
    resul[contador] = vetor1[contador] + vetor2[contador];
}
return resul;
}

int main(void){

int tam;
int contador;
printf("Informe o tamanho do vetor:\n");
scanf("%d", &tam); 

float *vetor1 = (float*)calloc(tam,sizeof(float));
float * vetor2 = (float*)calloc(tam,sizeof(float));
if(vetor1 == NULL|| vetor1 == NULL){
    exit(1);
}

for(contador = 0; contador < tam; contador++){
    printf("Informe o %d valor do vetor 1:\n", contador+1);
    scanf("%f", &vetor1[contador]);
}
printf("\n");
for(contador = 0; contador < tam; contador++){
    printf("Informe o %d valor do vetor 2:\n", contador+1);
    scanf("%f", &vetor2[contador]);  
}
float *result = soma(vetor1,vetor2,tam);

printf("Resultado da soma:");

for(contador = 0; contador < tam; contador++){
    printf("%.2f\n", result[contador]);
}

free(vetor1);
free(vetor2);
free(result);
return 0;
}
