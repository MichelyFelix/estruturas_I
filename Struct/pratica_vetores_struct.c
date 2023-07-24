#include<stdio.h>
#include<stdlib.h>
#define MAX 100//constante

typedef struct aluno{//estrutura do tipo aluno
    int matricula; 
    char nome_aluno[81]; 
    char endereco[121]; 
    char telefone[21]; 
}Aluno;

void inicializa(int quant,Aluno** tabela){//função para inicializar vetor do tipo Aluno com o valor NULL
    int contador;
    for(contador = 0; contador < quant; contador++){
        tabela[contador] = NULL;
    }
}

void preenche (int quant, Aluno** tabela, int contador){/*Função que aloca espaço para cada indice do vetor do tipo Aluno para preencher as informações do usuário*/
    if (contador < 0 || contador >= quant){
        printf("indice fora do limite do vetor!\n");
        exit(1);
    }

    if (tabela[contador] == NULL){
        tabela[contador] = (Aluno*) malloc(sizeof(Aluno));
    }
    printf("Entre com a matricula: ");
    scanf("%d", &tabela[contador]->matricula);
    printf("Entre com o nome: ");
    scanf(" %80[^\n]", tabela[contador]->nome_aluno);
    printf("Entre com o endereco: ");
    scanf(" %120[^\n]", tabela[contador]->endereco);
    printf("Entre com o telefone: ");
    scanf(" %20[^\n]", tabela[contador]->telefone);
}

void retirar (int quant, Aluno ** tabela, int contador){//Função que retira dos dosdos do vetor do tipo Aluno
    if (contador < 0 || contador >= quant){
        printf("O indice esta fora do limite do vetor!\n");
        exit(1);
    }

    if (tabela[contador] != NULL){
        free(tabela[contador]);
        tabela[contador] = NULL;//informa que na posição não existe mais dado
    }
}

void imprime (int quant, Aluno ** tabela, int contador){//Função que imprime os campos de um Aluno
    if (contador < 0 || contador >= quant){
        printf("Indice fora do limite do vetor!\n");
        exit(1);
    }

    if (tabela[contador] != NULL){
        printf("Matricula: %d\n", tabela[contador]->matricula);
        printf("Nome: %s\n", tabela[contador]->nome_aluno);
        printf("Endereco: %s\n", tabela[contador]->endereco);
        printf("Telefone: %s\n", tabela[contador]->telefone);
    }
}

void imprime_tudo(int quant, Aluno** tabela){//Imprime os campos de cada indice do vetor tipo Aluno
    int contador;
    for( contador = 0; contador < MAX; contador++){
        imprime (MAX,tabela,contador);
    }
}

int main(void){
    Aluno* tabela[MAX];
    inicializa(MAX, tabela);//inicializa o vetor
    /*preenche os campos de vetor 0, 1 e 2*/
    preenche(MAX, tabela, 0);
    preenche(MAX, tabela, 1);
    preenche(MAX, tabela, 2);

    imprime_tudo(MAX,tabela);

    retirar(MAX, tabela, 0);
    retirar(MAX, tabela, 1);
    retirar(MAX, tabela, 2);
    
    return 0;
}
