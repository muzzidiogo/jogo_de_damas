#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include "peca.hpp"
#include "tabuleiro.hpp"

class Engine {
    private:
        Tabuleiro_t tabuleiro;
        char cor;
        std::map<Peca_t, int> resultados;
    public:
        void rodaEngine(Tabuleiro_t _tabuleiro, char _cor);
        std::map<Peca_t, int> get_resultados();
    
};
#endif