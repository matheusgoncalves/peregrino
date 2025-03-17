#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

// Função para criar e inicializar um novo inventário
Inventario* criarInventario() {
    Inventario* inv = (Inventario*)malloc(sizeof(Inventario));

    if (inv != NULL) {
        inv->primeiro = NULL;
    }

    return inv;
}

// Função para liberar a memória do inventário e seus itens
void liberarInventario(Inventario* inv) {
    if (inv == NULL) {
        return;
    }

    Item* atual = inv->primeiro;

    while (atual != NULL) {
        Item* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(inv);
}

// Função para adicionar um item ao inventário
void adicionarItem(Inventario* inv, char nome[]) {
    if (inv == NULL) {
        return;
    }

    Item* novo = (Item*)malloc(sizeof(Item));
    
    if (novo == NULL) {
        return;
    }

    strcpy(novo->nome, nome);
    novo->proximo = inv->primeiro;
    inv->primeiro = novo;

    printf("Voce adicionou %s ao seu inventario.\n\n", nome);
}

// Função para remover um item do inventário pelo nome
void removerItem(Inventario* inv, char nome[]) {
    if (inv == NULL || inv->primeiro == NULL) {
        printf("Inventario vazio ou invalido.\n\n");
        return;
    }

    Item* atual = inv->primeiro;
    Item* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                inv->primeiro = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item '%s' nao encontrado.\n\n", nome);
}

// Função para listar todos os itens do inventário
void listarItens(Inventario* inv) {
    if (inv == NULL || inv->primeiro == NULL) {
        printf("Inventario vazio.\n\n");
        return;
    }

    Item* atual = inv->primeiro;

    printf("Itens no inventario:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->nome);
        atual = atual->proximo;
    }
}
