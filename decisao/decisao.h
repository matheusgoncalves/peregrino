#ifndef DECISAO_H
#define DECISAO_H

typedef struct NoDecisao {
    char descricao[256];
    char opcao1[100];
    char opcao2[100];
    struct NoDecisao *opcao1No;
    struct NoDecisao *opcao2No;
} NoDecisao;

NoDecisao* criarNoDecisao(char descricao[], char opcao1[], char opcao2[]);
void conectarDecisoes(NoDecisao *no, NoDecisao *filho, int opcao);
int executarDecisao(NoDecisao *no);

#endif
