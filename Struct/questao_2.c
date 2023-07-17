#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa{
    char nome_pessoa[40];
    int documento;
    int idade;
}Pessoa;

void preencher_pessoa (Pessoa *pessoa){
    printf("Informe o nome da pessoa:\n");
        scanf(" %[^\n]", &pessoa->nome_pessoa);
     
    printf("Informe o numero do documento:\n");
        scanf("%d", &pessoa->documento);

    printf("Informe a idade:\n");
        scanf("%d", &pessoa->idade);
}

void imprimir_dados (Pessoa *pessoa){
    printf("\nDADOS OBTIDOS:\n\n NOME:%s\n NUMERO DO DOCUMENTO:%d\n IDADE:%d\n", pessoa->nome_pessoa, pessoa->documento, pessoa->idade);
}

void nova_idade(Pessoa *pessoa, int nova_idade){
   pessoa->idade = nova_idade; 
}

void MaisVelhaMaisNova(Pessoa *pessoa, int tamanho){
    int Mais_nova = 0,Mais_velha = 0,contador;
    
    for(contador = 0;contador < tamanho; contador++){
        if(pessoa[contador].idade < pessoa[Mais_nova].idade){
            Mais_nova = contador;
        }
        if(pessoa[contador].idade > pessoa[Mais_velha].idade){
            Mais_velha = contador;
        }
    }
    printf("Pessoa mais velha:%s\n Pessoa mais nova:%s\n", pessoa[Mais_velha].nome_pessoa, pessoa[Mais_nova].nome_pessoa);
}

int main(void){
    int quant,idade;

    printf("Informe a quantidade de pessoas que deseja cadastrar:\n");
        scanf("%d", &quant);

    Pessoa pessoa[quant];
    int contador;

    for(contador = 0; contador < quant; contador++){
        preencher_pessoa(&pessoa[contador]);
    }

    for(contador = 0; contador < quant; contador++){
        imprimir_dados(&pessoa[contador]);
    }

    printf("Informe a nova idade pa pessoa 1:\n");
        scanf("%d", &idade);
    nova_idade(&pessoa[0],idade);
    MaisVelhaMaisNova(pessoa,quant);
    return 0;
}
