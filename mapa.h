#ifndef MAPA_H
#define MAPA_H

typedef struct NoMapa {
    char nome[50];          
    struct NoMapa *filho_esq;    
    struct NoMapa *filho_dir;    
    struct NoMapa *pai;          
} NoMapa;

NoMapa* criarNoMapa(char nome[]);
void conectarMapas(NoMapa *pai, NoMapa *filho, int lado);
void explorar(NoMapa *local);

#endif
