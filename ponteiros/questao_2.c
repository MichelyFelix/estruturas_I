#include<stdio.h>

int main(void) {
int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);

return 0;
}
/*a) Esta mensagem é de erro ou advertência? R=será uma mensagem de advertência 
b)  Por que o compilador emite tal mensagem? R=O compilador está avisando que está convertendo um inteiro em um ponteiro sem um cast explícito.
c) Compile e execute o programa. A execução foi bem sucedida?
R= sim,apesar daa mensagem de advertência
d)Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida 
pelo compilador R= p =&x; return 0;
e) Compile e execute novamente o programa. A execução foi bem sucedida? R=sim*/
