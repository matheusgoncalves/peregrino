#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

// Função para criar um novo local no mapa
NoMapa* criarNoMapa(char nome[], char descricao[], int tem_decisao) {
    NoMapa *novo = (NoMapa*) malloc(sizeof(NoMapa));

    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
    novo->filho_esq = NULL;
    novo->filho_dir = NULL;
    novo->pai = NULL;
    novo->tem_decisao = tem_decisao;
    novo->bloqueado = 0;

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
    filho->pai = pai;
}

// Função para explorar o mapa
void explorar(NoMapa *local) {
    if (local == NULL) {
        return;
    }

    printf("\nVoce esta em: %s, %s\n", local->nome, local->descricao);

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

        if (escolha == 1 && local->filho_esq && local->filho_esq->bloqueado == 0) {
            tomarDecisao(local, local->filho_esq);
        } else if (escolha == 2 && local->filho_dir && local->filho_dir->bloqueado == 0) {
            tomarDecisao(local, local->filho_dir);
        } else if (escolha == 3 && local->pai && local->pai->bloqueado == 0) {
            explorar(local->pai);
        } else {
            printf("Opcao invalida ou mapa bloqueado! Tente novamente.\n");
            explorar(local);
        }
    } else {
        printf("Fim do caminho! Voce nao pode mais avancar.\n");
    }
}

void tomarDecisao(NoMapa *origem, NoMapa *destino) {
    if (origem->tem_decisao == 1 && origem->bloqueado == 0) {
        printf("Voce esta prestes a tomar uma decisao importante!\n");
        printf("Ir para %s bloqueara o caminho de volta para %s.\n", destino->nome, origem->nome);
        printf("1. Sim, avancar.\n");
        printf("2. Nao, ficar em %s.\n", origem->nome);

        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1) {
            origem->bloqueado = 1;
            printf("Voce avancou para %s. O caminho de volta para %s esta bloqueado!\n", 
                   destino->nome, origem->nome);
            explorar(destino);
        } else if (escolha == 2) {
            printf("Voce decidiu ficar em %s.\n", origem->nome);
            explorar(origem);
        } else {
            printf("Escolha invalida! Tente novamente.\n");
            tomarDecisao(origem, destino);
        }
    } else {
        explorar(destino);
    }
}
