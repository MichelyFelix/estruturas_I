#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

int main(void){
int m,n;
Matriz* matriz;
int v;

printf("Informe o tamanho da linha da matriz:\n");
scanf("%d", &m);
printf("Informe o tamanho da coluna da matriz:\n");
scanf("%d", &n);
matriz = mat_cria(m,n);

printf("Prencha a matriz:\n");
for(int contador = 0; contador < m; contador++){
    for(int contador2 = 0; contador2 < n; contador2++){
    printf("Informe o valor da posicao %d, %d \n", contador, contador2);
    scanf("%d",&v); 
    mat_atribui(matriz,contador,contador2,v);
    }
}

for(int contador1 = 0; contador1 < mat_linhas(matriz); contador1++){
    for(int contador2 = 0; contador2 < mat_colunas(matriz); contador2++){
        printf("%.1f", mat_acessa(matriz,contador1,contador2));
    }
}
mat_libera(matriz);
    return 0;
}