#include <stdio.h>
#include "mapa.h"

int main() {
    // Criando os locais
    NoMapa *condado = criarNoMapa("Condado", "o ponto de partida da sua aventura.", 0);
    NoMapa *bree = criarNoMapa("Bree", "o vilarejo com a famosa Estalagem do Ponei Saltitante.", 0);
    NoMapa *floresta = criarNoMapa("Floresta das Trevas", "um lugar misterioso e cheio de perigos.", 0);
    NoMapa *valfenda = criarNoMapa("Valfenda", "a antiga morada dos anoes, agora infestada de inimigos.", 1);
    NoMapa *moria = criarNoMapa("Mina de Moria", "o famigerado refugio elfico de Elrond.", 1);
    NoMapa *tormenta = criarNoMapa("Tormenta Sombria", "uma passagem montanhosa traicoeira, envolta em nevoa.", 0);
    NoMapa *nimloth = criarNoMapa("Vale de Nimloth", "um vale florido, lar de antigas lendas elficas.", 0);
    NoMapa *eldarion = criarNoMapa("Ruinas de Eldarion", "uma fortaleza abandonada habitada por criaturas misteriosas.", 0);
    NoMapa *montanha = criarNoMapa("Montanha da Perdicao", "o seu destino final, o local onde o Um Anel deve ser destruido.", 1);

    // Conectando os locais
    conectarMapas(condado, bree, 1);
    conectarMapas(condado, floresta, 2);

    conectarMapas(bree, eldarion, 1);
    conectarMapas(bree, moria, 2);

    conectarMapas(floresta, tormenta, 1);
    conectarMapas(floresta, nimloth, 1);

    conectarMapas(eldarion, valfenda, 1);
    conectarMapas(eldarion, tormenta, 1);

    conectarMapas(moria, valfenda, 1);
    conectarMapas(moria, tormenta, 2);

    conectarMapas(nimloth, valfenda, 1);
    conectarMapas(nimloth, tormenta, 2);

    conectarMapas(valfenda, tormenta, 1);
    conectarMapas(valfenda, montanha, 2);

    conectarMapas(tormenta, montanha, 1);
    conectarMapas(tormenta, montanha, 2);

    // Iniciando a exploração a partir do Condado
    explorar(condado);

    return 0;
}
