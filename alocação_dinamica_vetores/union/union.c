#include<stdio.h>
#include<stdlib.h>

typedef union indiceacademico{
    float IG;
    float IRA;
    float IRT;
}Indice_Academico;
 
 typedef struct aluno{
   char nome[20];
   int matricula;
   char curso[20];
   Indice_Academico IA;

 }Aluno;

int main(void){
    int op;
    Aluno *aluno = (Aluno*)malloc(sizeof(aluno));
   
    printf("informe o nome: ");
    scanf(" %[^\n]", aluno->nome);
    printf("\nInforme a matricula: ");
    scanf("%d", &aluno->matricula);
    printf("\nInforme o curso: ");
    scanf(" %[^\n]", aluno->curso);
    printf("Digite; \n 0 - IG \n 1 - IRA \n 2 - IRT");
    scanf("%d", &op);
    switch (op){
        case 0:
           printf("informe o IG: ");
           scanf("%f", &aluno->IA.IG); break;
        case 1:
           printf("informe o IRA: ");
           scanf("%f", &aluno->IA.IRA); break;
        case 2:
           printf("informe o IRT: ");
           scanf("%f", &aluno->IA.IRT); break;
    }
    printf("dados informados:\n Nome:%s\t Matricula:%d\t Curso:%s\t Indice:%f", aluno->nome, aluno->matricula, aluno->curso, aluno->IA.IG);
    free(aluno);
    return 0;

}