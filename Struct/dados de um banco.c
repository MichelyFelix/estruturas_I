#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct dados
{
   char nome[30];
   int num_conta;
   float saldo;
   int agencia;
   int senha;
}dados;

int main(void){
    dados *var_dados = (dados*)malloc(sizeof(dados));
    if( var_dados == NULL){
        printf("erro de alocacao");
        exit(1);
    }
    int indice;
    for(indice = 0; indice<2; indice++){
        printf("informe a sua agencia:");
            scanf("%d",&var_dados[indice].agencia);
        printf("informe o nome do cliente: ");
            scanf(" %[^\n]",var_dados[indice].nome);
        printf("informe o numero da conta: ");
            scanf("%d", &var_dados[indice].num_conta);
        printf("informe a sua senha");
            scanf("%d", &var_dados[indice].senha);
        printf("informe o saldo da conta:");
            scanf("%f",&var_dados[indice].saldo);
    }
    for(indice = 0; indice < 2; indice++) {
        printf("\nDados obtidos:\n");
        printf("Agencia: %d\n", var_dados[indice].agencia);
        printf("Nome do cliente: %s\n", var_dados[indice].nome);
        printf("Numero da conta: %d\n", var_dados[indice].num_conta);
        printf("Senha: %d\n", var_dados[indice].senha);
        printf("Saldo da conta: %.2f\n", var_dados[indice].saldo);
    }
    free(var_dados);
    return 0;
}
