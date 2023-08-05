#include<stdio.h>
#include<ctype.h>

int main(void){
    int c;
    char entrada[121];
    char saida[121];

FILE*e;
FILE*s;

printf("nome do arquivo de entrada:\n");
scanf("%120s", entrada);
printf("nome do arquivo de saida:\n");
scanf("%120s", saida);

e = fopen(entrada, "rt");
if(e == NULL){
    printf("erro!");
    return 1;
}
s = fopen(saida, "wt");
if(s == NULL){
    printf("erro!\n");
    return 1;
}

while((c = fgetc(e)) != EOF){//le cada  caractere presente no arquivo de entrada 
    fputc(toupper(c), s);//converte os caracteres para maiusculo 
}
    //fecha os arquivos de entrada e saida
    fclose(e);
    fclose(s);
return 0;
}
