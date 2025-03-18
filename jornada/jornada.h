#ifndef JORNADA_H
#define JORNADA_H

#include "../mapa/mapa.h"

// Estrutura para um nó da pilha
typedef struct NoJornada {
    NoMapa *local;
    struct NoJornada *prox;
} NoJornada;

// Estrutura da pilha
typedef struct PilhaJornada {
    NoJornada *topo;  // Ponteiro para o topo da pilha
} PilhaJornada;

PilhaJornada* criarPilha();
void registrarLocal(PilhaJornada *pilha, NoMapa *local);
void exibirJornada(PilhaJornada *pilha);
void destruirPilha(PilhaJornada *pilha);

#endif
