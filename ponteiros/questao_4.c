#include<stdio.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3 * pow(l,2) * sqrt(3))/2;
    *perimetro = 6*l;
}
int main(void){
    float lado,area,perimetro;
    printf("informe o lado do hexagono: \n");
    scanf("%f",&lado);
    calcula_hexagono(lado,&area,&perimetro);

    printf("A area do hexagono e: %.2f\n",area);
    printf("O perimetro do hexagono e: %.2f\n",perimetro);
    return 0;
}