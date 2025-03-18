#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "facil.h"
#include "../../mapa/mapa.h"
#include "../../decisao/decisao.h"
#include "../../inventario/inventario.h"

void carregarHistoriaFacil() {
    // Criando o inventário
    Inventario *inventario = criarInventario();

    // Criando os locais
    NoMapa *bree = criarNoMapa("Bree", "o vilarejo com a famosa Estalagem do Ponei Saltitante.");
    NoMapa *shire = criarNoMapa("Condado Ocidental", "uma regiao tranquila de colinas verdes e hobbits pacatos."); 
    NoMapa *valfenda = criarNoMapa("Valfenda", "a antiga morada dos anoes, agora infestada de inimigos.");
    NoMapa *corno_de_prata = criarNoMapa("Corno de Prata", "pico montanhoso onde os ventos sussurram profecias elficas.");
    NoMapa *campos_iris = criarNoMapa("Campos de Iris", "uma vasta planicie dourada proxima a Lothlorien, cheia de flores.");
    NoMapa *lothlorien = criarNoMapa("Lothlorien", "a floresta dourada dos elfos, protegida pela magia de Galadriel.");
    NoMapa *edoras = criarNoMapa("Edoras", "a capital de Rohan, onde o salao dourado de Meduseld se ergue.");
    NoMapa *passo_rohan = criarNoMapa("Passo de Rohan", "uma rota perigosa entre as montanhas, vigiada pelos cavaleiros.");
    NoMapa *gondor = criarNoMapa("Minas Tirith", "a cidade branca de Gondor, ultima esperanca dos homens.");
    NoMapa *nimloth = criarNoMapa("Vale de Nimloth", "um vale florido, lar de antigas lendas elficas.");
    NoMapa *fangorn = criarNoMapa("Floresta de Fangorn", "morada dos Ents, onde as arvores guardam segredos ancestrais.");
    NoMapa *erebor = criarNoMapa("Erebor", "a Montanha Solitaria, reino dos anoes sob a guarda de Smaug (destruido).");
    NoMapa *abismo_helm = criarNoMapa("Abismo de Helm", "uma fortaleza impenetravel esculpida nas montanhas.");
    NoMapa *montanha = criarNoMapa("Montanha da Perdicao", "o seu destino final, o local onde o Um Anel deve ser destruido.");

    // Conectando os locais (Dificuldade: Fácil)
    conectarMapas(bree, valfenda, 1);
    conectarMapas(bree, shire, 2); // Opcional
    conectarMapas(shire, nimloth, 1); // Subopcional
    conectarMapas(valfenda, lothlorien, 1);
    conectarMapas(valfenda, corno_de_prata, 2); // Opcional
    conectarMapas(corno_de_prata, campos_iris, 1); // Subopcional (2)
    conectarMapas(campos_iris, fangorn, 1); // Subopcional (3)
    conectarMapas(lothlorien, edoras, 1);
    conectarMapas(edoras, gondor, 1);
    conectarMapas(edoras, passo_rohan, 2); // Opcional
    conectarMapas(passo_rohan, erebor, 1); // Subopcional (2)
    conectarMapas(passo_rohan, abismo_helm, 2); // Subopcional (2)
    conectarMapas(gondor, montanha, 1);

    // Boas vindas ao jogador
    printf("\nVoce decidiu seguir por %s, %s\n", bree->nome, bree->descricao);

    // Iniciando a exploração a partir de Bree
    gerenciarAcoes(bree, inventario);

    printf("Voce encontrou um gigante! Ele te deu um jogo de baralho.\n");
    adicionarItem(inventario, "Baralho do Gigante");
    gerenciarAcoes(bree, inventario);
}

void gerenciarAcoes(NoMapa *localAtual, Inventario *inventario) {
    int opcao;

    while (opcao != 1) {
        printf("O que deseja fazer?\n");
        printf("[1] - Explorar\n");
        printf("[2] - Ver inventario\n");
        printf("[3] - Ver informacoes obtidas\n\n");
    
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    
        switch(opcao) {
            case 1:
                explorar(localAtual);
                break;
            case 2:
                listarItens(inventario);
                break;
            case 3:
                printf("Falta implementar.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
}
