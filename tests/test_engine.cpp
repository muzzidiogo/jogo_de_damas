#include <vector>
#include "../third_party/doctest.h"
#include "../include/engine.hpp"
#include "../include/tabuleiro.hpp"

TEST_CASE("Teste de declaração dos resultados") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    
    char cor = 'b';
    Engine engine;

    engine.rodaEngine(tabuleiro, cor);
    std::map<Peca_t, int> resultados = engine.get_resultados();
    std::vector<Peca_t> pecas;
    
    for (Peca_t peca : tabuleiro.get_tabuleiro()) {
        if (peca.get_cor() == cor) {
            pecas.push_back(peca);
        }
    }

    CHECK_EQ(pecas.size(), engine.get_resultados().size());
    


}
    
