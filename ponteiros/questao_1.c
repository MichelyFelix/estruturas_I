#include<stdio.h>

int main(void){
int x, y, *p;
y = 0;
p = &y;//'p' aponta para o endereço de 'y'
x = *p;// 'x' recebe o valor que 'p' aponta
x = 4;
(*p)++;//o valor que 'p' aponta é incremnetado mais 1; y = 1
--x; //4-1
(*p) += x;//o valor que 'p' aponta(y) é incrementado com o valor de 'x' 3 y=4
printf("%d %d %d",x,y,*p);// x = 3, y = 4, *p = 4
return 0;
}