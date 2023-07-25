#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//constantes
#define MAX_TURMAS 3
#define MAX_VAGAS 3

 typedef struct aluno {
 int matricula;
 char nome[81];
 float notas[3];
 float media;
}Aluno;

 typedef struct turma {
 char id; /* caractere que identifica a turma, por exemplo, A ou B */
 int vagas; /* números de vagas disponíveis para fechar a turma */
 Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char id){ /*Função para criar a turma,fornecer o identificador e atribuir NULL a cada um dos elementos do vetor*/
Turma *turma = (Turma *) malloc(sizeof(Turma));
    if(turma == NULL){
        printf("Erro ao alocar memoria!");
        exit(1);
    }
turma->id = id; //identificador da turma
turma->vagas = MAX_VAGAS; //saber a quantidade maxima de vagas

for (int contador = 0; contador < MAX_VAGAS; contador++){/* preenche os elementos com NULL*/
    turma->alunos[contador] = NULL;
}
return turma;
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    
    if(turma->vagas == 0){
        printf("Nao tem vaga disponivel na turma");
    }
    else{
        Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
        if(aluno == NULL){
            printf("erro ao alocar memoria");
            exit(1);
        }
        aluno->matricula = mat;
        strcpy(aluno->nome,nome);//copia o nome para a estrutura do tipo Aluno
      
        for(int contador = 0; contador < MAX_VAGAS; contador++){//inicializa as notas e a média com 0.0
            aluno->notas[contador]= 0.0;
        }
        aluno->media = 0.0;

        for(int contador = 0; contador < MAX_VAGAS; contador++){
            if(turma->alunos[contador] == NULL){//somente preence se o indice estiver com o valor NULL
                turma->alunos[contador] = aluno;
               turma->vagas--;//como um aluno foi cadastrado as vags diminuem 
            }
        }
    }
}

    void lanca_notas(Turma* turma){
    
        for(int contador = 0; contador < MAX_VAGAS; contador++){
            Aluno *aluno = turma->alunos[contador];
            if(turma->alunos[contador] != NULL){
                printf("Nome:%s\n ",turma->alunos[contador]->nome);
                for(int contador2 = 0; contador2 < 3; contador2++){
                    printf("Informe a %d nota:\n",contador2 = 1);
                        scanf("%f", &turma->alunos[contador]->notas[contador2]);
                }
            float soma = 0.0;
            for(int contador3 = 0; contador3 < 3; contador3++){
                soma = soma + turma->alunos[contador]->notas[contador3];
            }
            turma->alunos[contador]->media = soma/3.0;
            }
        }
    }

    void imprime_alunos(Turma* turma){
    for (int contador = 0; contador < 3; contador ++){
        Aluno *aluno = turma->alunos[contador];
        if(aluno != NULL){
            printf("Nome:%.1s", aluno->nome);
            printf("Matricula:%.1d", aluno->matricula);
            printf("Notas:%.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media:%.1f", aluno->media);
        }
    } 
    }

    imprime_turmas(Turma** turmas, int n){
       for(int contador = 0; contador < n; contador++){
        if(turmas[contador]!=NULL){//verifica se a turma é válida 
            printf("Turma:%c\n Vagas:%d\n", turmas[contador]->id, turmas[contador]->vagas);
        }
       } 
    }

    Turma* procura_turma(Turma** turmas, int n, char id){
        for(int contador = 0; contador < n; contador++){
            if(turmas[contador]->id == id){//verifica se a turma indicada pelo contador é igual ao id do parametro
                return turmas[contador];
            }
        }
    }

    int main(void){
        char id,nome[80];
        int matricula,n;
        int op;
        Turma *procurar_turmas;
        printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo asfuncionalidades de matricula, lancamento de notas e listagem dealunos.");

        do{
        printf("MENU:\n 1 – Criar turma\n 2 – Listar turmas\n3 – Matricular aluno\n 4 – Lancar notas\n 5 – Listar alunos\n 6 – Sair");
        switch (op){
        case 1:
            printf("Criando nova turma...\n");
            printf("Digite um id:\n");
            scanf("%c", &id);
            Turma * turma = cria_turma(id);
            printf("Turma %c criada com sucesso!\n", id);
            break;

            case 2:

            printf("Listando turmas...\n");
            imprime_turmas(turmas,MAX_TURMAS);
            break;

            case 3: 

            printf("Matriculando aluno...");
            printf("Digite o id da turma:\n");
            printf("%c", &id);
            printf("Digite a matricula:\n");
            scanf("%d", &matricula);
            printf("Digite o nome:\n");
            scanf("% [^\n]", &nome);
            matricula_aluno(id,matricula,nome);
            break;

            case 4:

            printf("Lancando notas...\n");
            printf("Digite o id da turma:\n");
            scanf("%c", &id);
            procurar_turmas = procura_turma(turmas,n,id);
            lanca_notas(procurar_turmas);
            break;

            case 5:

            printf("Listando alunos...\n");
            printf("Digite o id da turma:\n");
            imprime_alunos(turma);
            break;

            case 6:

            printf("Obrigado por usar este programa!\n");
             break;

            default:
            printf("Opcao invalida!\n");
            break;

        }while(op!= 6);
        free(turmas);
        return 0;
        }
