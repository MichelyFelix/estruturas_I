/*02. Escreva uma função que receba duas strings como entrada e 
retorne uma nova string que seja a concatenação das duas. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *vetor_string(char * string1, char * string2){
int contador1,contador2;
int tam1 = strlen(string1);/*saber o tamanho da string*/
int tam2 = strlen(string2);
int resultado = tam1 + tam2 + 1;
char * result = (char*)malloc(resultado*sizeof(char));
    if(result == NULL){
        exit(1);
    }
for (contador1 = 0; contador1 < tam1; contador1++){
    result[contador1] = string1[contador1]; 
}

for (contador2 = 0; contador2 < tam2; contador2++){
    result[contador1] = string2[contador2]; 
    contador1++;
}
result[contador1] = '\0';
return result;
}

int main(void){

    char string1[50];
    char string2[50];
  
    printf("Digite a primeira string:\n");
    scanf("%s", string1);

    printf("Digite a segunda string:\n");
    scanf("%s", string2);

    char*resultado = vetor_string(string1,string2);
    printf(" Resultado:\n%s", resultado);
    free(resultado);
    return 0;
}