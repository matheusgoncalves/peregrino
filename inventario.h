#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct Item {
    char nome[50];
    struct Item* proximo;
} Item;

typedef struct Inventario {
    Item* primeiro;
} Inventario;

Inventario* criarInventario();
void liberarInventario(Inventario *inv);
void adicionarItem(Inventario *inv, char nome[]);
void removerItem(Inventario *inv, char nome[]);
void listarItens(Inventario *inv);

#endif
