#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decisao.h"

NoDecisao* criarNoDecisao(char descricao[], char opcao1[], char opcao2[]) {
    NoDecisao *novo = (NoDecisao*) malloc(sizeof(NoDecisao));

    if (novo != NULL) {    
        strcpy(novo->descricao, descricao);
        strcpy(novo->opcao1, opcao1);
        strcpy(novo->opcao2, opcao2);
        novo->opcao1No = NULL;
        novo->opcao2No = NULL;
    }

    return novo;
}

void conectarDecisoes(NoDecisao *no, NoDecisao *filho, int opcao) {
    if (opcao == 1) {
        no->opcao1No = filho;
    } else if (opcao == 2) {
        no->opcao2No = filho;
    } else {
        printf("Opcao invalida!\n");
    }
}

void executarDecisao(NoDecisao *no) {
    if (no == NULL) {
        printf("\nFim das decisoes!\n");
        return;
    } else {
        int escolha;
        printf("\n%s\n", no->descricao);
        printf("1 - %s\n", no->opcao1);
        printf("2 - %s\n", no->opcao2);
        printf("O que voce decide fazer? ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            executarDecisao(no->opcao1No);
        } else if (escolha == 2) {
            executarDecisao(no->opcao2No);
        } else {
            printf("Escolha invalida! Tente novamente.\n");
            executarDecisao(no);
        }
    }
}
