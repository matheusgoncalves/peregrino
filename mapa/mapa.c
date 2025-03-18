#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

// Função para criar um novo local no mapa
NoMapa* criarNoMapa(char nome[], char descricao[]) {
    NoMapa *novo = (NoMapa*) malloc(sizeof(NoMapa));

    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
    novo->filho_esq = NULL;
    novo->filho_dir = NULL;

    return novo;
}

// Função para conectar dois locais na árvore
void conectarMapas(NoMapa *pai, NoMapa *filho, int lado) {
    if (lado == 1) {
        pai->filho_esq = filho;
    } else if (lado == 2) {
        pai->filho_dir = filho;
    } else {
        printf("Numero invalido.");
    }
}

// Função para explorar o mapa
NoMapa* explorar(NoMapa *local) {
    if (local == NULL) {
        return NULL;
    }

    if (local->filho_esq || local->filho_dir) {
        printf("Para onde deseja ir?\n");

        if (local->filho_esq) {
            printf("1 - %s\n", local->filho_esq->nome);
        }

        if (local->filho_dir) {
            printf("2 - %s\n", local->filho_dir->nome);
        }

        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1 && local->filho_esq) {
            return local->filho_esq;
        } else if (escolha == 2 && local->filho_dir) {
            return local->filho_dir;
        } else {
            printf("Opcao invalida! Voce permanece em %s.\n", local->nome);
            return local;
        }
    } else {
        printf("Fim do caminho! Voce nao pode mais avancar.\n");
        return local;
    }
}
