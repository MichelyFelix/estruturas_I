#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[21];
    int id;
    float salario;
}Dados;

int main(void){
FILE* arquivo;
arquivo = fopen("dados.txt", "w");
if(arquivo == NULL){
    printf("Erro!");
    exit(1);
}
Dados funcionarios;

printf("id:\n");
scanf("%d", &funcionarios.id);
printf("Nome:\n");
scanf(" %[^\n]", funcionarios.nome);
printf("Salario:\n");
scanf("%f", &funcionarios.salario);

fprintf(arquivo, "Id:%d\nNome:%s\nSalario:R$ %.2f\n", funcionarios.id,funcionarios.nome,funcionarios.salario);
fclose(arquivo);
return 0;
}