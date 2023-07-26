/*. Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto. */

#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

typedef union tipo{
char alimento[20];
char bebida[20];
char eletronico[20];
}Tipo;

typedef struct produto{
char nome[50];
float preco;
Tipo tipo;
}Produto;


int main(void){

Produto produto;
int op;

printf("Digite o tipo do produto:\n1-alimento\n2-bebidas\n3-eletronico\n");
scanf("%d", &op);

printf("Digite o nome do produto:\n");
scanf(" %[^\n]", produto.nome);

printf("Digite o valor do produto:\n");
scanf("%f", &produto.preco);

 
 printf("\nDados do produto\n");
 printf("Nome: %s\nPreco: R$%.2f\n", produto.nome, produto.preco);

 switch (op)
 {
 case 1: 
 printf("Tipo: Alimento");
    break;
 
 case 2:
 printf("Tipo: Bebida");
 break;

 case 3:
 printf("Tipo: Eletronico");
 break;

 }
 
    return 0;
}