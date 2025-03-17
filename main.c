#include <stdio.h>
#include "mapa.h"

int main() {
    // Criando os locais
    No *condado = criarNo("Condado");
    No *bree = criarNo("Bree");
    No *floresta = criarNo("Floresta das Trevas");
    No *valfenda = criarNo("Valfenda");
    No *moria = criarNo("Mina de Moria");
    No *montanha = criarNo("Montanha da Perdicao");

    // Conectando os locais
    conectarNos(condado, bree, 1);
    conectarNos(condado, floresta, 2);
    conectarNos(bree, valfenda, 1);
    conectarNos(floresta, moria, 1);
    conectarNos(moria, montanha, 1);

    // Iniciando a exploração a partir do Condado
    explorar(condado);

    return 0;
}
