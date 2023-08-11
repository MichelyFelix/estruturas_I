#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct fruta{
    char nome[50];
    float preco;
}Fruta;

int main(void){
FILE* arquivo;
Fruta fruta;
arquivo = fopen("frutas.txt", "wt");
if (arquivo == NULL){
    printf("Erro ao abrir arquivo!");
    exit(0);
}

do {
printf("Digite '1' quando desejar sair!\n");
printf("Nome da frutas:\n");
scanf(" %[^\n]", fruta.nome);
if (fruta.nome[0] == '1' && fruta.nome[1] == '\0') {
        printf("Encerrando o programa...\n");
        break;
    }
printf("Preco:\n");
scanf("%f", &fruta.preco);
fprintf(arquivo, "%s, %.2f\n", fruta.nome, fruta.preco);
}while(1);
fclose(arquivo);
    return 0;
}