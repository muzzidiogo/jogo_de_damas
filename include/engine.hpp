#ifndef ENGINE_H
#define ENGINE_H

#include "peca.hpp"
#include "tabuleiro.hpp"


class Engine {
    private:
        int quantidadeDeJogadas; 
        int quantidadeDeJogadasMax;
        std::vector<Peca_t> pecasRemover;
        std::vector<Peca_t> pecasRemoverMax;
    public:
        bool conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca);
        void roda_engine(Tabuleiro_t tabuleiro, char cor);
        Peca_t get_maior(Tabuleiro_t tabuleiro, char cor);
};
#endif