#include<stdio.h>
#include<stdlib.h>



 typedef enum genero{
    MASCULINO, FEMININO
    }Genero;

typedef struct pessoa{
    char nome[80];
    int idade;
    Genero genero;
}Pessoa;

int main(void){

Pessoa pessoa;

 printf("Digite o seu nome:\n");
 scanf(" %[^\n]", pessoa.nome);

 printf("Digite a sua idade:\n");
 scanf("%d", &pessoa.idade);

 printf("Digite 0 para feminino e 1 para masculino :");
 scanf("%d", &pessoa.genero);

if (pessoa.genero == 0){
        printf("Feminino\n");
    }else{
        printf("Masculino\n");
    }
return 0;
}