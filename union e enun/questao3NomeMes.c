/*. Escreva um programa que implementa uma struct Data com os campos dia, mˆes e ano. O mˆes deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa.
*/

#include<stdio.h>
#include<stdlib.h>

   enum Mes{
    JANEIRO,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO

};
typedef struct data{
int dia, ano;
enum Mes mes ;
}Data;

const char *nomesMeses[] = {
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
};

int main(void){
    Data data;
    printf("Digite o dia:\n");
    scanf("%d", &data.dia);

    printf("Digite o mes(1-12):\n");
    scanf("%d", &data.mes);

    printf("Digite o ano:\n");
    scanf("%d", &data.ano);

    printf("%02d/%s/%d", data.dia, nomesMeses[data.mes-1], data.ano);

return 0;
}