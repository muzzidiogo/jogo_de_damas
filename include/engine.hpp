#ifndef ENGINE_H
#define ENGINE_H

#include "peca.hpp"
#include "tabuleiro.hpp"

typedef struct {
    Peca_t peca;
    std::vector<Peca_t> pecasCapturar;
    int numCapturas;
} Informacoes_pecas_t;

class Engine {
    private:
        int _numCapturas; 
        std::vector<Peca_t> _pecasCapturar;
        bool conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca);
        void roda_engine(Tabuleiro_t tabuleiro, char cor);
        Tabuleiro_t * aloca_tabuleiro_com_captura(Tabuleiro_t tabuleiro, Movimento_t movimento, Peca_t peca);
    public:
        Informacoes_pecas_t get_maior(Tabuleiro_t tabuleiro, char cor);
};

#endif