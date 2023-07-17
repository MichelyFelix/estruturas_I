#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    typedef struct disciplina{
        char nome[10];
        float nota;
    }Disciplina;

 typedef struct aluno{
    char nome[20];
    int matricula;
    Disciplina *disciplina;
}Aluno;
 
int main(void){

    Aluno * var_Aluno = (Aluno*)malloc(sizeof(Aluno));
    if (var_Aluno==NULL){
        printf("erro de alocacao");
        exit(1);
    }
    var_Aluno->disciplina = (Disciplina*)malloc(2*sizeof(Disciplina));
    printf("informe o nome do aluno: ");
         scanf("%s", var_Aluno->nome);
    printf("informe o numero de matricula do aluno:");
        scanf("%d",&var_Aluno->matricula);
    printf("informe o nome da 1 disciplina:");
        scanf("%s",var_Aluno->disciplina[0].nome);
    printf("informe o nome da 2 disciplina:");
        scanf("%s",var_Aluno->disciplina[1].nome);
    printf("informe a nota:");
        scanf("%f",&var_Aluno->disciplina->nota);
    
   printf("os dados dos alunos foram:\n nome:%s\t disciplina: %s\t matricula:%d\t nota:%.2f\t",var_Aluno->nome,var_Aluno->disciplina->nome,var_Aluno->matricula, var_Aluno->disciplina->nota);
   free(var_Aluno->disciplina);
   free(var_Aluno);
    return 0;
}