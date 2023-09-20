#include<stdio.h>
#include<stdio.h>
#define N 50

typedef struct pilha{
    int n;
    float vet[N];
}Pilha;

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;//inicioaliza com zero elementos
    return p;
}

void pilha_push(Pilha* p, float v){
    if(p->n == N){
        printf("Capacidade da pilha está cheia!\n");
        exit(1);
    }
    /*insere elementos na proxima posição da pilha*/

    p->vet[p->n] = v;
    p->n++;
}

int pilha_vazia(Pilha* p){
    return(p->n == 0);
}

float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

void pilha_libera(Pilha* p){
free(p);
}

void pilha_imprime(Pilha* p, float v){
    int cont;
    for(cont = p->n-1; cont>0; cont--){
        printf("%d", p->vet[cont]);
    }
}