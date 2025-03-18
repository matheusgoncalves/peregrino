#ifndef MAPA_H
#define MAPA_H

typedef struct NoMapa {
    char nome[50];
    char descricao[100];
    struct NoMapa *filho_esq;
    struct NoMapa *filho_dir;
} NoMapa;

NoMapa* criarNoMapa(char nome[], char descricao[]);
void conectarMapas(NoMapa *pai, NoMapa *filho, int lado);
NoMapa* explorar(NoMapa *local);

#endif
