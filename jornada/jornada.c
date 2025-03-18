#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jornada.h"

PilhaJornada* criarPilha() {
    PilhaJornada *pilha = (PilhaJornada*) malloc(sizeof(PilhaJornada));

    pilha->topo = NULL;

    return pilha;
};

void registrarLocal(PilhaJornada *pilha, NoMapa *local) {
    NoJornada *novo = (NoJornada*) malloc(sizeof(NoJornada));

    if (novo == NULL) {
        printf("Erro de alocacao de memoria.");
        return;
    }

    novo->local = local;
    novo->prox = pilha->topo;
    pilha->topo = novo;
};

void exibirJornada(PilhaJornada *pilha) {
    if (pilha->topo != NULL) {
        NoJornada *atual = pilha->topo;

        printf("\nJornada percorrida ate agora:\n");

        while (atual != NULL) {
            printf("%s\n", atual->local->nome);

            atual = atual->prox;
        }

        printf("\n");
    } else {
        printf("\nVoce ainda nao visitou nenhum local.\n");
        return;
    }
};

void destruirPilha(PilhaJornada *pilha) {
    NoJornada *atual = pilha->topo;

    while (atual != NULL) {
        NoJornada *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(pilha);
};
