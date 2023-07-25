#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 2


typedef struct banda{
char nome_banda[50];
char tipo_musical[50];
int quant_integrantes;
int  ranking;
}Banda;

void preenche_banda(Banda *banda){
printf("Nome da banda:\n");
    scanf(" %[^\n]", &banda->nome_banda);
printf("Informe o tipo musical da banda:\n");
    scanf(" %[^\n]", &banda->tipo_musical);
printf("Informe a quantidade de integrantes:\n");
    scanf("%d", &banda->quant_integrantes);
printf("Em qua ranking a banda esta da sua lista de bandas favoritas:\n");
    scanf("%d", &banda->ranking);
}

void exibe_banda(Banda *banda){
  printf("Nome da banda:%s\n", banda->nome_banda);  
  printf("tipo musical: %s\n", banda->tipo_musical);
  printf("quantidade de integrandes:%d\n", banda->quant_integrantes);
  printf("ranking da banda:%d\n", banda->ranking);
}

void ranking(Banda banda[]){
    int position,contador;
    for( contador = 0; contador < max; contador++){
    printf("Informe a posicao no ranking que a banda %d esta entre 1 a 5:\n", contador + 1);
        scanf("%d",&position);
        if(position <1 || position >5){
            printf("invalido");
        }
        else{
            exibe_banda(&banda[position - 1]);
        }
    }
}

void tipo(Banda banda[]){
    char tipo[50];
    
printf("Informe o tipo musical que deseja buscar:\n");
    scanf(" %[^\n]", &tipo);

for(int contador = 0; contador < max; contador++){

if(strcmp(banda[contador].tipo_musical, tipo)==0){
exibe_banda(&banda[contador]);
break;
}
else{
    printf("Nenhuma banda encontrada com esse tipo de música.\n");
    break;
}
}
}

void preferida(Banda banda[]){
    char nome[50];
    int contador,encontrado=0;
    printf("Qual panda deseja verificar?\n");
        scanf(" %[^\n]", &nome);
    
    for(contador = 0; contador < max; contador++){
        if(strcmp(banda[contador].nome_banda,nome)==0){
            printf("Sim, essa banda está entre as suas favoritas!\n");
            encontrado = 1;
            break;
        }
        if(!encontrado){
            printf("Nao, essa banda nao se encontra as suas preferidas");
        }
    }
}

int main(void){
 int opcao;
 Banda banda[max];

 printf("Preencha as informacoes das bandas:\n");
 for (int contador = 0; contador < max; contador++){
    printf("Banda %d:\n", contador+1);
    preenche_banda(&banda[contador]);
 }
 
do
{
printf("\nMenu:\n 1-Exibir as infirmacoes da banda por posicao no ranking\n 2- Exibir banda por tipo musical\n 3-Verificar se a banda esta entre as suas favoritas\n 4- Sair\n");
scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:

    ranking(banda);
    break;

  case 2:

    tipo(banda);
    break;

    case 3:

    preferida(banda);
    break;

    case 4:

    printf("Obrigado por usar o program!\n");
    break;

  default:

  printf("Opcao invalida!\n");
    break;
  }


} while (opcao !=4);
return 0;
}