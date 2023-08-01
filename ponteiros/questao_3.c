#include <stdio.h>
int main(void) {
 int a, b, c, d;
 int *p1;
 int *p2 = &a;//'p2' é inicializado e recebe o endereço da variável 'a'
 int *p3 = &c;//'p3' é inicializado e recebe o e endereço da variável 'c'
 p1 = p2;//'p1' recebe o valor de 'p2'
 *p2 = 10;//o valor que 'p2' aponta é alterado para '10'
 b = 20;
 int **pp;//declaração de ponteiro para ponteiro
 pp = &p1;//rece o endereço de 'p1'
 *p3 = **pp;//a endereço que 'p3' aponta é atribuido com valor que 'pp' aponta, ou seja, p1 (a)
 int *p4 = &d;//é declarado um ponteiro de inteiro que é inicializado com endereço de 'd'
 *p4 = b + (*p1)++;//p4 recebe o valor de 'b'(20) e soma com o valor de 'p1'(10) e depois 'p1' é incrementado
 printf("%d\t%d\t%d\t%d\n", a, b, c, d);//11 20 10 30
 return 0;
}
