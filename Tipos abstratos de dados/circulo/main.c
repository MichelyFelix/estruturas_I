#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

int main(){
    Circulo *c = circ_cria(3.5, 2.0, 1.5);
    float a = circ_area(c);
    printf("A area do ciruclo: %f\n", a);
    Ponto *p = pto_cria(2.2, 1.5);
    
    int verifica_pto = circ_interior(c, p);

    if (verifica_pto==1){
        printf("O ponto se encontra dentro do circulo!\n");
    }else{
        printf("O ponto não existe dentro do circulo!\n");
    }

    pto_libera(p);
    circ_libera(c);
    return 0;
}