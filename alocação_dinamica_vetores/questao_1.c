#include<stdio.h>
#include<stdlib.h>

int main(void){
    int quantidade;
    int total_M = 0; 
    int total_F = 0; 
    float gostaram_F = 0;
    float porcentagem_F,porcentagem_M;
    float N_gostaram_M = 0;

    printf ("informe a quantidade de pessoas entrevistadas:\n ");
        scanf("%d",&quantidade);

    char *sexo = (char*)calloc(quantidade,sizeof(char));
        if (sexo == NULL){
            printf("erro de alocacao");
            exit(1);
        }
    char *opiniao = (char*)calloc(quantidade,sizeof(char));
        if (opiniao == NULL){
            printf("erro de alocacao");
            exit(1);
        }

    for (int contador = 0; contador < quantidade; contador++){
        printf("Pessoa %d\n",contador + 1);

        printf("Informe o seu sexo(M/F):\n");
            scanf(" %c",&sexo[contador]);
        printf("informe se voce gostou ou nao gostou do produto(G/N):\n");
            scanf(" %c",&opiniao[contador]);

        if (sexo[contador] == 'm'|| sexo[contador] == 'M'){
            total_M++;
        
         if (opiniao[contador] == 'N' || opiniao[contador] == 'n'){
            N_gostaram_M++;
        }
        }
         else if (sexo[contador] == 'f'|| sexo[contador] == 'F'){
            total_F++;
        
         if (opiniao[contador] == 'G' || opiniao[contador] == 'g'){
            gostaram_F++;
        }
        }
        }
        porcentagem_F = (gostaram_F / total_F) * 100;
        porcentagem_M = (N_gostaram_M/total_M) * 100;

    
    printf("Porcentagem de pessoas do sexo feminino que gostaram do produto: %.2f\n", porcentagem_F);
    printf("Porcentagem de pessoas do sexo masculino que nao gostaram do produto: %.2f\n", porcentagem_M);

    free(sexo);
    free(opiniao);
    
    return 0;
}