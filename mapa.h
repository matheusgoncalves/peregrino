#ifndef MAPA_H
#define MAPA_H

typedef struct No {
    char nome[50];          
    struct No *filho_esq;    
    struct No *filho_dir;    
    struct No *pai;          
} No;

No* criarNo(char nome[]);
void conectarNos(No *pai, No *filho, int lado);
void explorar(No *local);

#endif
