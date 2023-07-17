#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct funcionario{
    char nome_funcionario;
    float salario;
    int identificador;
    char cargo;
}Funcionario;

    void preencher(Funcionario *pessoa){//preenche as informações do funcionário
        printf("Informe o nome do funcionario:\n");
            scanf(" %[^\n]", &pessoa->nome_funcionario);
        printf("Informe o salario:\n");
            scanf("%f",&pessoa->salario);
        printf("Informe o identificador do funcionario:\n");
            scanf("%d", &pessoa->identificador);
        printf("Informe o cargo do funcionario:\n");
            scanf(" %[^\n]",&pessoa->cargo); 
    }

    void imprimir(Funcionario *pessoa){//imprime as informações do funcionário
        printf("NOME DO FUNCIONARIO:%s\t SALARIO:%f\t IDENTIFICADOR:%d\t CARGO:%s\t",pessoa->nome_funcionario, pessoa->salario, pessoa->identificador, pessoa->cargo);
    }

    void alterar_salario(Funcionario *pessoa, float novo_salario){
        pessoa->salario += novo_salario;
    }

    void maior_menor(Funcionario *pessoa, int tamanho){
        int maior_salario = 0, menor_salario = 0;
        int contador;
        for(contador = 0; contador<tamanho; contador++){
            if(pessoa[contador].salario > pessoa[maior_salario].salario){
                maior_salario = contador;
            }
            if(pessoa[contador].salario < pessoa[menor_salario].salario){
                menor_salario = contador;
            
        }}
    printf("\n Funcionario com o maior salario:\n Cargo: %s\t Salario: %f\t",pessoa[maior_salario].cargo, pessoa[maior_salario].salario);
    printf("\nFuncionario com menor salario:\n Cargo:%s\t Salario:%f\t",pessoa[menor_salario].cargo, pessoa[menor_salario].salario);
    }

int main(void){
    int qunat;
    printf("Informe a quantidade de funcionarios que deseja cadastrar:\n");
        scanf("%d",&qunat);
    Funcionario pessoa[qunat];
    int contador;
    for(contador = 0; contador < qunat; contador++){
        preencher(&pessoa[contador]);
    }
    for(contador = 0; contador < qunat; contador++){
        imprimir(&pessoa[contador]);
    }
        alterar_salario(&pessoa[0],1000);
   
}