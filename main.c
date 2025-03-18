#include <stdio.h>
#include "mapa/mapa.h"
#include "inventario/inventario.h"
#include "decisao/decisao.h"
#include "historia/facil/facil.h"

int main(void) {
    // Boas vindas ao jogador
    printf("Seja bem vindo ao mundo de Peregrino. Aqui voce ira contar a historia de Frodo, o Hobbit mais importante da historia de Senhor dos Aneis, e suas decisoes impactam diretamente no rumo da historia.\n\n");
    printf("Voce esta no Condado, e, depois de alguns dias de descanso, voce sente que precisa voltar para sua missao.\n\n");
    
    // Escolha da dificuldade
    printf("Segundo as informacoes que voce coletou, voce sabe que pode seguir por dois caminhos distintos:\n");
    printf("[1] - A historia nos diz que o caminho mais seguro e pela cidade de Bree. E melhor nao arriscar (Facil)\n");
    printf("[2] - Segundo fontes confiaveis, poderiamos encontrar coisas interessantes indo pelo Topo do Vento (Dificil)\n\n");

    int dificuldade;
    do {
        printf("O que voce escolhe? ");
        scanf("%d", &dificuldade);

        if (dificuldade != 1 && dificuldade != 2) {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (dificuldade != 1 && dificuldade != 2);

    // Carregamento da historia adequada
    if (dificuldade == 1) {
        carregarHistoriaFacil();
    } else {
        // carregarHistoriaDificil(&mapa, &decisao);
    }

    // // Criando os locais
    // NoMapa *topo_vento = criarNoMapa("Topo do Vento", "uma colina antiga com ruinas que sussurram segredos do passado.");
    // NoMapa *floresta = criarNoMapa("Floresta das Trevas", "um lugar misterioso e cheio de perigos.");
    // NoMapa *tormenta = criarNoMapa("Tormenta Sombria", "uma passagem montanhosa traicoeira, envolta em nevoa.");
    // NoMapa *eldarion = criarNoMapa("Ruinas de Eldarion", "uma fortaleza abandonada habitada por criaturas misteriosas.");
    // NoMapa *pantanos = criarNoMapa("Pantanos dos Mortos", "lamacais traicoeiros onde luzes-fatuas levam viajantes a morte.");
    // NoMapa *isengard = criarNoMapa("Isengard", "a fortaleza de Saruman, com sua torre de Orthanc e maquinas de guerra.");
    // NoMapa *osgiliath = criarNoMapa("Osgiliath", "ruinas da antiga capital de Gondor, agora campo de batalha constante.");
    // NoMapa *mirrormere = criarNoMapa("Lago Espelhado", "um lago cristalino aos pes das Montanhas Nevoentas, sagrado para os anoes.");
    // NoMapa *baraddur = criarNoMapa("Barad-dur", "a torre sombria de Sauron, erguida com poder e maldade.");
    // NoMapa *moria = criarNoMapa("Mina de Moria", "o famigerado refugio elfico de Elrond.");
    // NoMapa *dol_guldur = criarNoMapa("Dol Guldur", "fortaleza das trevas no sul da Floresta das Trevas.");
    // NoMapa *mordor = criarNoMapa("Mordor", "a terra sombria de Sauron, cercada por montanhas de cinzas.");
    // NoMapa *minas_morgul = criarNoMapa("Minas Morgul", "a cidade-fantasma iluminada por uma luz palida e maligna.");
    // NoMapa *montanha = criarNoMapa("Montanha da Perdicao", "o seu destino final, o local onde o Um Anel deve ser destruido.");

    // // Conectando os locais (Dificuldade: Difícil)
    // conectarMapas(condado, topo_vento, 2);
    // conectarMapas(topo_vento, moria, 1);
    // conectarMapas(topo_vento, floresta, 2); // Opcional
    // conectarMapas(floresta, tormenta, 1); // Subopcional
    // conectarMapas(tormenta, mirrormere, 2); // Subopcional (2)
    // conectarMapas(moria, dol_guldur, 1);
    // conectarMapas(dol_guldur, minas_morgul, 1);
    // conectarMapas(dol_guldur, pantanos, 2); // Opcional
    // conectarMapas(pantanos, osgiliath, 1); // Subopcional
    // conectarMapas(pantanos, mordor, 2); // Subopcional
    // conectarMapas(mordor, isengard, 1); // Subopcional (2)
    // conectarMapas(isengard, baraddur, 1); // Subopcional (3)
    // conectarMapas(isengard, eldarion, 2); // Subopcional (3)
    // conectarMapas(minas_morgul, montanha, 1);

    // // Iniciando a exploração a partir do Condado
    // explorar(condado);

    return 0;
}
