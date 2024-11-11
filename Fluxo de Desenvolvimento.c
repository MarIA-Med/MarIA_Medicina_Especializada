/*
 * Nome do Arquivo: Fluxo de Desenvolvimento
 * Autor: Marcos Santana
 * Data de Criação: 06/11/2024
 * Última Modificação: 10/11/2024
 * Versão: 1.1
 * Copyright (C) 2024 MarIA
 * Todos os direitos reservados.
 * - 06/11/2024 - Versão inicial.
 */

#include <stdio.h>

#define TOTAL_ETAPAS 5

typedef struct {
    char nome[20];
    int progresso; 
} Etapa;

int main() {
    Etapa etapas[TOTAL_ETAPAS] = {{"Analise", 0}, {"Design", 0}, {"Implementacao", 0}, {"Testes", 0}, {"Implantacao", 0}};
    int todasConcluidas;

    printf("Fluxo de Desenvolvimento de Software\n");

    do {
        todasConcluidas = 1;

        for (int i = 0; i < TOTAL_ETAPAS; i++) {
            if (etapas[i].progresso < 100) {
                todasConcluidas = 0;
                int incremento;
                printf("Etapa: %s (Progresso: %d%%)\nDigite o progresso para a etapa %s (incremento entre 0 e 100): ", 
                       etapas[i].nome, etapas[i].progresso, etapas[i].nome);

                if (scanf("%d", &incremento) != 1 || incremento < 0 || incremento > 100) {
                    printf("Entrada invalida! Digite um numero entre 0 e 100.\n");
                    while (getchar() != '\n');
                    i--;
                    continue;
                }

                etapas[i].progresso = (etapas[i].progresso + incremento > 100) ? 100 : etapas[i].progresso + incremento;
            }
        }

        printf("\nStatus Atual do Projeto:\n");
        for (int i = 0; i < TOTAL_ETAPAS; i++) printf("  %s: %d%% concluido\n", etapas[i].nome, etapas[i].progresso);
        printf("\n");
    } while (!todasConcluidas);

    printf("Todas as etapas foram concluidas! Projeto finalizado com sucesso.\n");

    return 0;
}