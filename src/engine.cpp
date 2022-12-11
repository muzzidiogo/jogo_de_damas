#include "../include/engine.hpp"

void Engine::rodaEngine(Tabuleiro_t _tabuleiro, char _cor) {
    tabuleiro = _tabuleiro;
    cor = _cor;

    for (Peca_t peca : tabuleiro.get_tabuleiro()) {
        if (peca.get_cor() == _cor) {
            //resultados.insert({peca, 0});
        }        
    }
}

std::map<Peca_t, int> Engine::get_resultados() {
    return resultados;
}