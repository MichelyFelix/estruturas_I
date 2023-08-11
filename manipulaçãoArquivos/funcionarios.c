#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct funcionario{
    char nome[100];
    char funcional[10];
    float salario;
    char departamento;
}Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal){
*pessoal = (Funcionario*)malloc(n*sizeof(Funcionario));

int contador;
char linha[100];
for(contador = 0; contador < n; contador++){
  for (int contador = 0; contador < n; contador++) {
        fscanf(fl, "%s\t%99[^\t]\t %c\t%f", (*pessoal)[contador].funcional, (*pessoal)[contador].nome, &(*pessoal)[contador].departamento, &(*pessoal)[contador].salario);
    }
}
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){
    float total = 0;
    printf("Funional\tNome\tDepartamento\tSalario\n");
    for(int contador = 0; contador < n; contador++){
        if(pessoal[contador]->departamento == depto){
        printf("%s\t%s\t%c\t%.2f\n", pessoal[contador]->funcional, pessoal[contador]->nome, pessoal[contador]->departamento, pessoal[contador]->salario);
           total = total + pessoal[contador]->salario;
        }
    }
    printf("VALOR TOTAL:R$ %.2f\n",total);
}

int main(void){
FILE* arquivo;
int num_funcionarios;
Funcionario*funcionarios;

arquivo = fopen("funcionarios.txt","r");
if(arquivo==NULL){
    printf("Erro ao abrir arquivo!");
    exit(1);
}

fscanf(arquivo, "%d", &num_funcionarios);//ve a quantidade de funcionários que tem no arquivo
funcionarios = (Funcionario*)malloc(num_funcionarios*sizeof(Funcionario));

copia_dados(arquivo,num_funcionarios,&funcionarios);

    imprime_folha_pagamento(num_funcionarios, &funcionarios, 'A');
    imprime_folha_pagamento(num_funcionarios, &funcionarios, 'B');
    imprime_folha_pagamento(num_funcionarios, &funcionarios, 'C');

    fclose(arquivo);
    
    free(funcionarios);
    return 0;
}
