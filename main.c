#include <stdio.h>
#include "mapa.h"

int main() {
    // Criando os locais
    NoMapa *condado = criarNo("Condado");
    NoMapa *bree = criarNo("Bree");
    NoMapa *floresta = criarNo("Floresta das Trevas");
    NoMapa *valfenda = criarNo("Valfenda");
    NoMapa *moria = criarNo("Mina de Moria");
    NoMapa *montanha = criarNo("Montanha da Perdicao");

    // Conectando os locais
    conectarMapas(condado, bree, 1);
    conectarMapas(condado, floresta, 2);
    conectarMapas(bree, valfenda, 1);
    conectarMapas(floresta, moria, 1);
    conectarMapas(moria, montanha, 1);

    // Iniciando a exploração a partir do Condado
    explorar(condado);

    return 0;
}
