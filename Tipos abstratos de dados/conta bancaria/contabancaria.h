typedef struct contaBancaria ContaBancaria;
ContaBancaria*Cria_conta(char* titular, int numero, float saldo);
void preenche(ContaBancaria*dados);
void imprime_dados(ContaBancaria*dados);
void deposita (ContaBancaria* conta,float novo_salario);
void saca (ContaBancaria* conta, float saque);
void transfere (ContaBancaria* conta1, ContaBancaria* conta2, float valor);
float saldo (ContaBancaria* conta);
void exclui_Conta(ContaBancaria* conta);