#include <stdio.h>
#include "mapa.h"
#include "inventario.h"

int main() {
    // Criando o inventário
    Inventario *inventario = criarInventario();

    adicionarItem(inventario, "Pocao");
    adicionarItem(inventario, "Cajado");

    listarItens(inventario);

    // Criando os locais
    NoMapa *condado = criarNoMapa("Condado", "o ponto de partida da sua aventura.", 0);
    NoMapa *bree = criarNoMapa("Bree", "o vilarejo com a famosa Estalagem do Ponei Saltitante.", 0);
    NoMapa *topo_vento = criarNoMapa("Topo do Vento", "uma colina antiga com ruinas que sussurram segredos do passado.", 0);
    NoMapa *shire = criarNoMapa("Condado Ocidental", "uma regiao tranquila de colinas verdes e hobbits pacatos.", 0); 
    NoMapa *corno_de_prata = criarNoMapa("Corno de Prata", "pico montanhoso onde os ventos sussurram profecias elficas.", 0);
    NoMapa *floresta = criarNoMapa("Floresta das Trevas", "um lugar misterioso e cheio de perigos.", 0);
    NoMapa *valfenda = criarNoMapa("Valfenda", "a antiga morada dos anoes, agora infestada de inimigos.", 0);
    NoMapa *tormenta = criarNoMapa("Tormenta Sombria", "uma passagem montanhosa traicoeira, envolta em nevoa.", 0);
    NoMapa *nimloth = criarNoMapa("Vale de Nimloth", "um vale florido, lar de antigas lendas elficas.", 0);
    NoMapa *eldarion = criarNoMapa("Ruinas de Eldarion", "uma fortaleza abandonada habitada por criaturas misteriosas.", 0);
    NoMapa *lothlorien = criarNoMapa("Lothlorien", "a floresta dourada dos elfos, protegida pela magia de Galadriel.", 1);
    NoMapa *edoras = criarNoMapa("Edoras", "a capital de Rohan, onde o salao dourado de Meduseld se ergue.", 0);
    NoMapa *fangorn = criarNoMapa("Floresta de Fangorn", "morada dos Ents, onde as arvores guardam segredos ancestrais.", 0);
    NoMapa *erebor = criarNoMapa("Erebor", "a Montanha Solitaria, reino dos anoes sob a guarda de Smaug (destruido).", 0);
    NoMapa *pantanos = criarNoMapa("Pântanos dos Mortos", "lamacais traicoeiros onde luzes-fatuas levam viajantes a morte.", 0);
    NoMapa *isengard = criarNoMapa("Isengard", "a fortaleza de Saruman, com sua torre de Orthanc e maquinas de guerra.", 0);
    NoMapa *osgiliath = criarNoMapa("Osgiliath", "ruinas da antiga capital de Gondor, agora campo de batalha constante.", 0);
    NoMapa *abismo_helm = criarNoMapa("Abismo de Helm", "uma fortaleza impenetravel esculpida nas montanhas.", 0);
    NoMapa *mirrormere = criarNoMapa("Lago Espelhado", "um lago cristalino aos pes das Montanhas Nevoentas, sagrado para os anoes.", 0);
    NoMapa *baraddur = criarNoMapa("Barad-dur", "a torre sombria de Sauron, erguida com poder e maldade.", 0);
    NoMapa *campos_iris = criarNoMapa("Campos de Iris", "uma vasta planicie dourada proxima a Lothlorien, cheia de flores.", 0);
    NoMapa *passo_rohan = criarNoMapa("Passo de Rohan", "uma rota perigosa entre as montanhas, vigiada pelos cavaleiros.", 0);
    NoMapa *moria = criarNoMapa("Mina de Moria", "o famigerado refugio elfico de Elrond.", 1);
    NoMapa *dol_guldur = criarNoMapa("Dol Guldur", "fortaleza das trevas no sul da Floresta das Trevas.", 0);
    NoMapa *mordor = criarNoMapa("Mordor", "a terra sombria de Sauron, cercada por montanhas de cinzas.", 0);
    NoMapa *minas_morgul = criarNoMapa("Minas Morgul", "a cidade-fantasma iluminada por uma luz palida e maligna.", 1);
    NoMapa *gondor = criarNoMapa("Minas Tirith", "a cidade branca de Gondor, ultima esperanca dos homens.", 1);
    NoMapa *montanha = criarNoMapa("Montanha da Perdicao", "o seu destino final, o local onde o Um Anel deve ser destruido.", 0);

    // Conectando os locais (Dificuldade: Fácil)
    conectarMapas(condado, bree, 1);
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

    // Conectando os locais (Dificuldade: Difícil)
    conectarMapas(condado, topo_vento, 2);
    conectarMapas(topo_vento, moria, 1);
    conectarMapas(topo_vento, floresta, 2); // Opcional
    conectarMapas(floresta, tormenta, 1); // Subopcional
    conectarMapas(tormenta, mirrormere, 2); // Subopcional (2)
    conectarMapas(moria, dol_guldur, 1);
    conectarMapas(dol_guldur, minas_morgul, 1);
    conectarMapas(dol_guldur, pantanos, 2); // Opcional
    conectarMapas(pantanos, osgiliath, 1); // Subopcional
    conectarMapas(pantanos, mordor, 2); // Subopcional
    conectarMapas(mordor, isengard, 1); // Subopcional (2)
    conectarMapas(isengard, baraddur, 1); // Subopcional (3)
    conectarMapas(isengard, eldarion, 2); // Subopcional (3)
    conectarMapas(minas_morgul, montanha, 1);

    // Iniciando a exploração a partir do Condado
    explorar(condado);

    return 0;
}
