#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void){
    int nota = 0.0;
    int alunos = 10;
    int quant_questoes;
    printf("Informe a quantidade de questoes da prova:\n");
        scanf("%d",&quant_questoes);
        char *gabarito = (char*)calloc((quant_questoes + 1),sizeof(char));
        if (gabarito == NULL){
            printf("erro de alocacao");
            exit(1);
        }
    printf("Informe o gabarito da prova:\n");
        scanf("%s", gabarito);
    if(strlen (gabarito) != quant_questoes){//a função strlen compara o tamanho
        printf("O numero de caracteries do gabarito nao corresponde a quantidade que questoes!");
        exit(1);
    }
    float aprovados = 0.0;
    for(int contador = 0; contador < alunos; contador++){

    char *resposta = (char*)calloc((quant_questoes + 1),sizeof(char));
    if (gabarito == NULL){
            printf("erro de alocacao");
            exit(1);
        }
        printf("informe as respostas do %d aluno:\n",contador + 1);
        scanf("%s", resposta);
        if (strlen(resposta) != quant_questoes){
            printf("O numero de caracteries das respostas do aluno %d nao correspondem a quantidade de questoes", contador + 1);
            exit(1);
        }
     for (int contador2 = 0; contador2 < quant_questoes; contador2++) {
            if (resposta[contador2] == gabarito[contador2]) {
                nota += 10.0 / quant_questoes;
            }
        }

        printf("A nota obtida do aluno %d e %.2d\n", contador + 1, nota);

        if (nota >= 6.0) {
            aprovados++;
        }

        free(resposta);
        nota = 0.0;
    }

    float porcent_aprov = (float)(aprovados / alunos) * 100.0;
    printf("A porcentagem de aprovacao foi de %.2f\n", porcent_aprov);

    free(gabarito);

    return 0;
}