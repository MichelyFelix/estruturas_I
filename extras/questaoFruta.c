#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct fruta
 {
   char nome[50];
   char cor[50];
   char sabor[50];
   int quant;
 }Fruta;

void cadastrar_fruta(Fruta*fruta, int quant){
for(int contador = 0; contador < quant; contador++){
    printf("Informe o nome da fruta:\n");
    scanf(" %[^\n]", fruta[contador].nome);
    printf("Informe a cor:\n");
    scanf(" %[^\n]", fruta[contador].cor);
    printf("Informe o sabor:\n");
    scanf(" %[^\n]", fruta[contador].sabor);
    printf("Informe a quantidade da fruta:\n");
    scanf("%d", &fruta[contador].quant);
}
}

void listaDeFrutas(Fruta*fruta, int quant){
printf("\nDado das frutas cadastradas:\n");
for(int contador = 0; contador < quant; contador++){
printf("\nFruta %d\n", contador  + 1);
printf("Nome:%s\n", fruta[contador].nome);
printf("Cor:%s\n", fruta[contador].cor);
printf("sabor:%s\n", fruta[contador].sabor);
printf("Quantidade:%d\n", fruta[contador].quant);
}
}

void buscar_fruta(Fruta*fruta, int quant, char*nome_fruta){
    int achou = 0;
    int contador;
for(contador = 0; contador < quant; contador++){//função usada para comparar o nome das frutas 
 if (strcmp(fruta[contador].nome,nome_fruta) == 0){//se as string forem iguais a função atrcmp retorna 0
    printf("\nFruta %d\n", contador + 1);
    printf("Nome: %s\n", fruta[contador].nome);
    printf("Cor: %s\n", fruta[contador].cor);
    printf("Sabor: %s\n", fruta[contador].sabor);
    printf("Quantidade: %d\n", fruta[contador].quant);
    achou = 1;
}
}
if(!achou){
    printf("nenhuma fruta encontrada com esse nome!\n");
}
}

 int main(void){
    int quant,op;

    printf("Digite a quantidade de frutas que deseja cadastrar:\n");
    scanf("%d", &quant);

    Fruta fruta[quant];
    char busca_fruta[50];
    do{
        printf("\n\nMenu:\n1-Cadastrar frutas:\n2-Lista de frutas cadastradas:\n3-Buscar fruta:\n4-Sair\n\n");
        scanf("%d", &op);
        switch(op){
        case 1:
        cadastrar_fruta(fruta, quant);
        break;   

        case 2: 
        listaDeFrutas(fruta, quant);
        break;

        case 3:
        printf("\nDigite o nome da fruta que deseja buscar:\n");
        scanf(" %[^\n]", busca_fruta);
        buscar_fruta(fruta, quant,busca_fruta);
        break;

        case 4:
        printf("Obrigado por usar o programa...");
        break;

        default:
        printf("opcao invalida!");
        break;
        }
        }while(op != 4);
    return 0;
}
 
