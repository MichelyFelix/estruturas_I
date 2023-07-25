#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Considerando uma estrutura para representar um ponto no espaço 2D, 
implemente uma função que indique se um ponto p está localizado dentro ou fora de um retângulo.
 O retângulo é definido por seus vértices inferior esquerdo v1 e superior direito v2.
 A função deve retornar 1, caso o ponto esteja localizado dentro do retângulo, e 0, caso contrário.
 Essa função deve obedecer ao protótipo:
int dentroRet (Ponto* v1 , Ponto* v2 , Ponto* p);*/

typedef struct ponto{
double x;
double y;
}Ponto;

void dentroRet (Ponto*v1, Ponto*v2, Ponto*p){

    if((p->x >= v1->x && p->x <= v2->x) && (p->y >= v1->y && p->y <= v2->y)){
        printf("O ponto P esta dentro do retangulo!");
    }
    else{
        printf("O ponto P esta fora do retangulo!");
    }
}

void preenche_x_y(Ponto*PontoA, Ponto*PontoB){
printf("Digite as coordenadas do ponto A:\n");
printf("Coordenada X:\n");
scanf("%lf", &PontoA->x);
printf("Coordenadas de Y:\n");
scanf("%lf", &PontoA->y);
printf("Digite as coordenadoa do ponto B:\n");
printf("Coordenada X:\n");
scanf("%lf", &PontoB->x);
printf("Coordenadas Y:\n");
scanf("%lf", &PontoB->y);
}

void preenche(Ponto*P){
    printf("Digite as coordenadas do ponto P:\n");
    printf("Coordenada X: ");
    scanf("%lf", &P->x);
    printf("Coordenada Y: ");
    scanf("%lf", &P->y);
}
int main(void){

Ponto PontoA, PontoB, P;

preenche_x_y(&PontoA,&PontoB);
preenche(&P);
dentroRet(&PontoA,&PontoB,&P);
return 0;
}