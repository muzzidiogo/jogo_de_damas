#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include "peca.hpp"
#include "tabuleiro.hpp"


class Engine {
    private:
        int quantidadeDeJogadas, quantidadeDeJogadasMax;
    public:
        bool conta_jogadas(Tabuleiro_t _tabuleiro, Peca_t _peca);
        void roda_engine(Tabuleiro_t _tabuleiro, char _cor);
        Peca_t get_maior(Tabuleiro_t _tabuleiro, char _cor);
};
#endif