#ifndef MAPA_H
#define MAPA_H

typedef struct NoMapa {
    char nome[50];
    char descricao[100];
    struct NoMapa *filho_esq;
    struct NoMapa *filho_dir;
    struct NoMapa *pai;
    int tem_decisao;
    int descricao_decisao;
    int bloqueado;
} NoMapa;

NoMapa* criarNoMapa(char nome[], char descricao[], int tem_decisao);
void conectarMapas(NoMapa *pai, NoMapa *filho, int lado);
void explorar(NoMapa *local);
void tomarDecisao(NoMapa *origem, NoMapa *destino);

#endif
