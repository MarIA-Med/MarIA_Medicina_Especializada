#include <stdio.h>

int main() {
    int n, impacto, tempo, incerteza, importancia, relevancia, dependencia;
    char nomes[10000][81];  
    float medias[10];    

    // Pergunta ao usuario quantos requisitos ele quer classificar
    printf("Quantos requisitos deseja classificar? ");
    scanf("%d", &n);

    // Coleta os dados de cada requisito
    for (int i = 0; i < n; i++) {
        printf("\nInforme o requisito %d (ate 80 caracteres): ", i + 1);

        // Le o nome do requisito 
        scanf(" %[^\n]s", nomes[i]);  // Le ate 80 caracteres ou ate a nova linha

        // Coleta as classifica��es
        printf("Classifique de 1 a 6 para as perguntas a seguir:\n");

        printf("Qual o impacto do requisito no resultado final? (1-6): ");
        scanf("%d", &impacto);

        printf("Quanto tempo e recursos serao necessarios para implementar o requisito? (1-6): ");
        scanf("%d", &tempo);

        printf("Qual o nivel das incertezas e desafios associados a implementacao? (1-6): ");
        scanf("%d", &incerteza);

        printf("Qual o nivel de importancia do requisito para o cronograma do projeto? (1-6): ");
        scanf("%d", &importancia);

        printf("Qual o nivel de relevancia desse requisito para o usuario final? (1-6): ");
        scanf("%d", &relevancia);

        printf("Qual o nivel de dependencia do sistema desse requisito? (1-6): ");
        scanf("%d", &dependencia);

        // Calcula a media das respostas
        medias[i] = (impacto + tempo + incerteza + importancia + relevancia + dependencia) / 6.0;
    }

    // Mostra os requisitos suas medias e classifica��es
    printf("\nRequisitos, medias e classificacoes:\n");
    for (int i = 0; i < n; i++) {
        printf("Requisito: %s\n", nomes[i]);
        printf("Media: %.2f - ", medias[i]);

        // Classifica��o de acordo com a media
        if (medias[i] <= 2) {
            printf("Alta\n");
        } else if (medias[i] <= 4) {
            printf("Media\n");
        } else {
            printf("Baixa\n");
        }
    }

    return 0;
}
    