#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

typedef struct matriz {
int lin;
int col;
float** v;
}Matriz;

Matriz* mat_cria(int m, int n){
Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
if(matriz == NULL){
    printf("Erro ao alocar memoria!\n");
    exit(1);
}  
matriz->lin = m;
matriz->col = n;
matriz->v = (float**)malloc(m* sizeof(float*));
if(matriz->v == NULL){
    printf("Erro ao alocar memoria!\n");
    exit(1);
}
for(int contador = 0; contador < matriz->col; contador++){
  matriz->v[contador] =  (float*)malloc(sizeof(float));  
}
printf("A matriz foi criado com sucesso!\n");
return(matriz);
}

void mat_libera(Matriz* matriz){
   if(matriz != NULL){
    for(int contador = 0; contador < matriz->lin; contador ++){
        free(matriz->v[contador]);
        free(matriz->v);
    }
    free(matriz);
   } 
}

float mat_acessa(Matriz*matriz, int m, int n){
  if(matriz == NULL ||m > matriz->lin ||n > matriz->col) {
    printf("O indice está fora dos limetes da matriz ou a matriz nao existe!\n");
  } 
  else{
   return matriz->v[m][n];
  }
}

void mat_atribui(Matriz*matriz, int m, int n, float v){
   if(matriz == NULL ||m > matriz->lin ||n > matriz->col) {
    printf("O indice está fora dos limetes da matriz ou a matriz nao existe!\n");
  } 
  else{
   return matriz->v[m][n] = v;
  } 
}

int mat_linhas(Matriz*matriz){
    if(matriz != NULL){
        return matriz->lin;
    }
    else{
        return 0.0;
    }
}

int mat_colunas(Matriz*matriz){
    if(matriz != NULL){
        return matriz->col;
    }
    else{
        return 0.0;
    }
}