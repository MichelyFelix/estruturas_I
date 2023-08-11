#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct aluno{
    float nota1,nota2,nota3;
    char nome[100];

}Aluno;

int main(void){
    FILE*arquivo;
    int quant;

    printf("Informe a quantidade de alunos:\n");
    scanf("%d", &quant);
    Aluno*alunos = (Aluno*)malloc(quant*sizeof(Aluno));
    if(alunos == NULL){
        printf("erro ao alocar memoria!");
        exit(1);
    }

    Aluno aluno[quant];

    for(int contador = 0; contador < quant; contador++){
        printf("Nome do %d aluno:\n", contador+1);
        scanf(" %[^\n]", aluno[contador].nome);
        printf("Nota 1 do %d aluno:\n",contador+1);
        scanf("%f", &aluno[contador].nota1);
        printf("Nota 2 do %d aluno:\n",contador+1);
        scanf("%f", &aluno[contador].nota2);
        printf("Nota 3 do %d aluno:\n", contador+1);
        scanf("%f", &aluno[contador].nota3);
    }
   arquivo = fopen("arquivo.txt", "wt"); 
   if(arquivo == NULL){
    printf("Erro");
    exit(1);
   }
    for(int contador = 0; contador < quant; contador++){
    fprintf(arquivo, "\nAluno %d\n", contador+1);
    fprintf(arquivo, "Nome do aluno:%s\n",aluno[contador].nome); 
    fprintf(arquivo, "Nota 1 do aluno:%.2f\n",aluno[contador].nota1);
    fprintf(arquivo,"Nota 2 do aluno:%.2f\n",aluno[contador].nota2);
    fprintf(arquivo, "Nota 3do aluno:%.2f\n",aluno[contador].nota3); 
    }
    fclose(arquivo);
    free(alunos);
    return 0;
   }