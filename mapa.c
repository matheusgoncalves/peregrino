#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

// Função para criar um novo local no mapa
No* criarNo(char nome[]) {
    No *novo = (No*) malloc(sizeof(No));

    strcpy(novo->nome, nome);
    novo->filho_esq = NULL;
    novo->filho_dir = NULL;
    novo->pai = NULL;

    return novo;
}

// Função para conectar dois locais na árvore
void conectarNos(No *pai, No *filho, int lado) {
    if (lado == 1) {
        pai->filho_esq = filho;
    } else if (lado == 2) {
        pai->filho_dir = filho;
    } else {
        printf("Numero invalido.");
    }
    filho->pai = pai;
}

// Função para explorar o mapa
void explorar(No *local) {
    if (local == NULL) {
        return;
    }

    printf("\nVoce esta em: %s\n", local->nome);

    if (local->filho_esq || local->filho_dir || local->pai) {
        printf("Para onde deseja ir?\n");

        if (local->filho_esq) {
            printf("1 - %s\n", local->filho_esq->nome);
        }

        if (local->filho_dir) {
            printf("2 - %s\n", local->filho_dir->nome);
        }

        if (local->pai) {
            printf("3 - Voltar para %s\n", local->pai->nome);
        }

        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1 && local->filho_esq) {
            explorar(local->filho_esq);
        } else if (escolha == 2 && local->filho_dir) {
            explorar(local->filho_dir);
        } else if (escolha == 3 && local->pai) {
            explorar(local->pai);
        } else {
            printf("Opcao invalida!\n");
            explorar(local);
        }
    } else {
        printf("Fim do caminho! Voce nao pode mais avancar.\n");
    }
}
