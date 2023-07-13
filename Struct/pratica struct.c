#include<stdio.h>
#include<stdlib.h>
// armazenar os dados de uma pessoa
typedef struct pessoa{
    char nome[25];
    int idade;
    float RG;
    float altura;
}Pessoa;
int main(void){
    Pessoa var_pessoa[2];
    int indice;
    for(indice = 0;indice<2;indice++){
    printf("informe o nome:\n");
        scanf(" %[^\n]", var_pessoa[indice].nome);
    printf("informe a idade da pessoa:\n");
        scanf("%d", &var_pessoa[indice].idade);
    printf("informe o numero do RG:\n ");
        scanf("%f", &var_pessoa[indice].RG);
    printf("informe a altura:\n");
        scanf("%f", &var_pessoa[indice].altura);
        //esta incompleto
    }
    for(indice = 0; indice<2; indice++){
        printf("\nos dados obtidos foram:\n");
          printf(" Nome: %s \t Idade: %d \t  RG: %f\t altura: %.2f ", var_pessoa[indice].nome, var_pessoa[indice].idade, var_pessoa[indice].RG, var_pessoa[indice].altura);
    }
    return 0;
}