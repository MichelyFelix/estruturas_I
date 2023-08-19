#include<stdio.h>
#include<stdlib.h>
#include"contabancaria.h"

typedef struct contaBancaria{
char* titular[100];
int numero;
float saldo;
}ContaBancaria;


ContaBancaria*Cria_conta(char* titular, int numero, float saldo){
    ContaBancaria*conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if(conta == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}
void preenche(ContaBancaria*dados){
    printf("Informe o nome:\n");
    scanf(" %[^\n]", dados->titular);
    printf("Informe o numero da conta:\n");
    scanf("%d", &dados->numero);
    printf("Informe o saldo da conta:\n");
    scanf("%f", &dados->saldo);
}

void imprime_dados(ContaBancaria*dados){
    printf("Nome:%s\t", dados->titular);
    printf("Numero da conta:%d\t", dados->numero);
    printf("Saldo da conta:%f\t", dados->saldo);
}

void deposita (ContaBancaria* conta,float novo_salario){
conta->saldo += novo_salario;
printf("Deposito realizado com sucesso!\n");
}

void saca (ContaBancaria* conta, float saque){
   float valoratual = conta->saldo;
   if((valoratual - saque) < 0){//verifica se o saldo na conta é suficiente para realizar o saque 
    printf("Saldo indisponivel para saque!\n");
    return 1;
   } 
   else{//se o valor for suficiente o saque é realizado
    conta->saldo = valoratual - saque;
    printf("Saque realizado com sucesso!\n");
   }
}

void transfere (ContaBancaria* conta1, ContaBancaria* conta2, float valor){
float saldo1 = conta1->saldo;
float saldo2 = conta2->saldo;
if((saldo1 - valor) <0){
    printf("Saldo insuficiente para realizar transferencia!\n");
    return 1;
    }
else{
    saldo1 = saldo1 - valor;//o saldo da conta2 é subtraido com o valor da transferecncia
    saldo2 = saldo2 + valor;//o saldo da conta2 é somado com o valor da transferecncia
    //atualiza os valores das  contas
    conta1->saldo = saldo1;
    conta2->saldo = saldo2;

    printf("Trnaferencia realizada com sucesso!\n");
}
}

float saldo (ContaBancaria* conta){
return(conta)?conta->saldo:-99999;//retorna o saldo da conta se ela existir, se a conta não existir o valor retornado é 99999
}

void exclui_Conta(ContaBancaria* conta){
    if(conta){
     free(conta);   
    }
}