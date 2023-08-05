#include<stdio.h>
#include<stdlib.h>

int main(void){

 FILE* entrada;
 FILE* saida;
char nome_aluno[100];
int linha[100];

entrada = fopen("entrada_q3.txt", "r");
if(entrada == NULL){
    printf("Erro ao abrir arquivo!");
    exit(1);
}
 saida = fopen("saída_q3.txt", "w");
 if(saida == NULL){
    printf("Erro ao abrir arquivo!");
    exit(1);
 }

while(fgets(linha,100,entrada)!= NULL){
float nota1 = 0,nota2 = 0,nota3 = 0;
 float media = 0;
    sscanf(linha,"%20[^\t]\t%f\t%f\t%f\t", nome_aluno, &nota1, &nota2, &nota3);
    media = (nota1 + nota2 + nota3)/3.0;
     fprintf(saida, "%s\t%.1f\t %s\n", nome_aluno, media, (media>=7.0)?"aprovado":"reprovado");
}

fclose(entrada);
fclose(saida);

    return 0;
}