/* Considere listas encadeadas de valores inteiros e implemente uma função para
retornar o número de nós da lista que possuem o campo info com valores
maiores do que n. Essa função deve obedecer ao protótipo: int maiores(Lista* l,
int n);
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
int n;
struct lista* prox;
}Lista;

void* list_cria(void){
    return NULL;
}

int list_insere(Lista*valor,int n){
    Lista*v = (Lista*)malloc(sizeof(Lista));
        if(v == NULL){
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }
    v->n = n;
    v->prox = valor;
    return v;
}

int maiores(Lista*valor, int n){
int contador = 0;
Lista* i = valor;

while(i!=NULL){
if(i->n > n){
    contador++;
}
i = i->prox;
}
return contador;
}

void list_libera(Lista*valor){
Lista* i = valor;
Lista* t;

while(i != NULL){
    free(i);
    i = t;
}
}

int main(void){
    Lista* novaLista = list_cria();

    novaLista = list_insere(novaLista,11);
    novaLista = list_insere(novaLista,5);
    novaLista = list_insere(novaLista,15);
    novaLista = list_insere(novaLista,111);

    int valorComparar = 10;

    printf("Quantidade de elementos maior que %d: %d", valorComparar, maiores(novaLista,valorComparar));

    list_libera(novaLista);
    return 0;
}