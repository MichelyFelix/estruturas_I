#include<stdio.h>

int main(void){
    char  nome_arquivo[50];
    int c;
    FILE*fp;
    printf("Informe o nome do arquivo:\n");
    scanf(" %[^\n]", nome_arquivo);

   FILE * arquivo = fopen(nome_arquivo, "rt");
    if(nome_arquivo == NULL){
        printf("erro ao abrir!\n");
        return 1;
    }
    else{
        printf("arquivo criado com sucesso!\n");
    }
    fputc('A', arquivo);
    fprintf(arquivo, "\nalgoritmos e estrutura de dados I\n");
    fclose(arquivo);
    return 0;
}