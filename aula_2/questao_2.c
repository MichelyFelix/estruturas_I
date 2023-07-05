#include<stdio.h>
#include<stdlib.h>

int main(void){
    int linhas,colunas;
    printf("informe o tamanho das linhas:");
    scanf("%d",&linhas);
    printf("informe o tamanho das colunas:");
    scanf("%d",&colunas);
    int **matriz = (int**)malloc(linhas*sizeof(int*));
    if (matriz==NULL){
        printf("erro de alocaçõa");
        exit(1);
 
    }
    int contador;
    for ( contador=0; contador<linhas; contador++){
        matriz[contador]= (int*) malloc(colunas*sizeof(int));
    }
    int linha,coluna;
    printf("informe os dados da matriz:\n");
    for (linha = 0; linha<linhas; linha++){
        for (coluna = 0; coluna<colunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    int **matriz2=(int**)malloc(linha*sizeof(int*));
    if(matriz2==NULL){
        printf("erro de alocação");
        exit(1);
    }
    for ( contador=0; contador<linhas; contador++){
        matriz2[contador]= (int*) malloc(colunas*sizeof(int));
    }
     for (linha = 0; linha<linhas; linha++){
        for (coluna = 0; coluna<colunas; coluna++){
           matriz2[linha][coluna]=matriz[coluna][linha];
        }
     }
      printf("Valores da matriz:\n");
    for (linha = 0; linha < linhas; linha++) {
        for (coluna = 0; coluna < colunas; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\t\n");
    }
     for (linha=0;linha<linhas;linha++){
        free(matriz[linha]);
        free(matriz2[linha]);
     }
    free(matriz);
    free(matriz2);
    return 0;
}