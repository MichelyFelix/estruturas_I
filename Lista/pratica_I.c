#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct frutas{
    char nome[20];
    struct listaFruta*proxima;
 }listaFruta;

insere(listaFruta*fruta, char* nome){
    listaFruta* novaFruta = (listaFruta*)malloc(sizeof(listaFruta));
    strcpy(novaFruta->nome, nome);
    novaFruta->proxima = fruta;
    return novaFruta;
}
int main(void){

listaFruta* fruta1 = malloc(sizeof(listaFruta));
listaFruta* fruta2 = malloc(sizeof(listaFruta));
listaFruta* fruta3 = malloc(sizeof(listaFruta));

strcpy(fruta1->nome, "maca");
strcpy(fruta2->nome, "abacate");
strcpy(fruta3->nome, "uva");

fruta1->proxima = fruta2;
fruta2->proxima = fruta3;
fruta3->proxima = NULL;

listaFruta*P;
for(P = fruta1; P!=NULL;P = P->proxima){
    printf("%s",  P->nome);
}
return 0;
}