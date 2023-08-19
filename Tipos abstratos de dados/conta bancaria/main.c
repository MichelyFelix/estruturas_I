#include<stdio.h>
#include<stdlib.h>
#include"contaBancaria.h"

int main(void){
ContaBancaria* conta1 = Cria_conta("", 0, 0.0);
ContaBancaria* conta2 = Cria_conta("", 0, 0.0);

preenche (conta1);
preenche (conta2);
imprime_dados(conta1);
imprime_dados(conta2);

float valor_deposito1,valor_deposito2;
printf("Informe o valor que deseja depositar na conta 1:\n");
scanf("%f", &valor_deposito1);
deposita(conta1,valor_deposito1);
printf("Informe o valor que deseja depositar na conta 2:\n");
scanf("%f", &valor_deposito2);
deposita(conta1,valor_deposito2);

float valor_saque;
printf("\nInforme o valor que deseja sacar:\n");
scanf("%f", &valor_saque);
saca(conta2,valor_saque);

float valorTransferencia;
printf("\nInforme o valor da transferência: ");
scanf("%f", &valorTransferencia);
transfere(conta1, conta2, valorTransferencia);

printf("\nSaldo da primeira conta: %.2f\n", saldo(conta1));
printf("Saldo da segunda conta: %.2f\n", saldo(conta2));

exclui_Conta(conta1);
exclui_Conta(conta2);

return 0;
}