#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//constantes
#define MAX_TURMAS 3
#define MAX_VAGAS 2

 typedef struct aluno {
 int matricula;
 char nome[90];
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
        printf("Nao ha vaga disponivel na turma %c\n", turma->id);
    }
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
                printf("Aluno matriculado com sucesso!");
                break;
            }
        }
          turma->vagas--;//como um aluno foi cadastrado as vags diminuem 
    }
  

    void lanca_notas(Turma* turma){
   
         float soma = 0.0;

        for(int contador = 0; contador < MAX_VAGAS; contador++){
            if(turma->alunos[contador] != NULL ){//verifica se a turma já tem alunos cadastrados e se o id da turma é igual
                printf("Nome:%s\n ",turma->alunos[contador]->nome);
                printf("Matricula:%d\n", turma->alunos[contador]->matricula);
                for(int contador2 = 0; contador2 < 3; contador2++){
                    printf("Informe a %d nota:\n",contador2+1);
                        scanf("%f", &turma->alunos[contador]->notas[contador2]);
                }
            for(int contador3 = 0; contador3 < MAX_VAGAS; contador3++){
                soma += turma->alunos[contador]->notas[contador3];
            }
            turma->alunos[contador]->media = soma/3.0;
        }
        }
        printf("Notas lancadas com sucesso!");
    }

    void imprime_alunos(Turma* turma){
    for (int contador = 0; contador < MAX_VAGAS; contador ++){
        Aluno *aluno = turma->alunos[contador];
        if(aluno != NULL){
            printf("Nome:%s\n", aluno->nome);
            printf("Matricula:%d\n", aluno->matricula);
            printf("Notas:%.1f\n, %.1f\n, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media:%.1f\n", aluno->media);
        }
    } 
    }

     void imprime_turmas(Turma** turmas, int n){
        if(n == 0){
            printf("Nenhuma turma cadastrada!");
        }
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
        return NULL;//retorna NULL casso a turma com o id não for encontrada
    }

    int main(void){
        char id,nome[80];
        int matricula = 0,n = 0;
        int op = 0;
         Turma **turma = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
    if (turma == NULL){
        exit(1);
    }
        Turma * procurar_turmas;
        printf("\n\nBem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo asfuncionalidades de\n matricula,lancamento de notas e listagem dealunos.\n\n");

        do{
         printf("\n\n\tMenu:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\n");
        scanf("%d",&op);
        switch (op){
        case 1:
            system("cls");
            printf("Criando nova turma...\n");
            printf("Digite um id:\n");
            scanf(" %c", &id);
            if(n == MAX_TURMAS){
             printf("O numero maximo foi atingido");
            }
            else if(procura_turma(turma,n,id) != NULL){
                printf("A turma ja existe");
            }
            else{
            turma[n] = (Turma*)malloc(sizeof(Turma));
            turmas[n] = cria_turma(id);
            n++;
            printf("Turma %c criada com sucesso!\n", id);
            }
            break;

            case 2:
            system("cls");
            printf("listando turmas...\n");
            imprime_turmas(turmas,n);
            break;

            case 3: 
            system("cls");
            printf("Matriculando aluno...\n");
            printf("Digite o id da turma:\n");
            scanf(" %c", &id); 
            procurar_turmas = procura_turma(turmas, n, id);
            if (procurar_turmas != NULL) {
            printf("Digite a matricula:\n");
            scanf("%d", &matricula);
            printf("Digite o nome:\n");
            scanf(" %[^\n]", nome);
            matricula_aluno(procurar_turmas, matricula, nome);
            } else {
            printf("Turma inexistente!\n");
            }
            break;

            case 4:
            system("cls");
            printf("Lancando notas...\n");
            printf("Digite o id da turma:\n");
            scanf(" %c", &id);
            procurar_turmas = procura_turma(turmas,n,id);
            lanca_notas(procurar_turmas);
            break;

            case 5:
            system("cls");
            printf("Listando alunos...\n");
            printf("Digite o id da turma:\n");
            scanf(" %s", &id);
            procurar_turmas = procura_turma(turmas, n, id);
            imprime_alunos(procurar_turmas);
           
            break;

            case 6:
            system("cls");
            printf("Obrigado por usar este programa!\n");
             break;

            default:
            system("cls");
            printf("Opcao invalida!\n");
            break;
        }
        }while(op!= 6);
         for (int i = 0; i < MAX_TURMAS; i++) {
        free(turma[i]);
    }
    free(turma);

        return 0;
        }
