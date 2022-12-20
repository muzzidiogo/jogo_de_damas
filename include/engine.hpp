#ifndef ENGINE_H
#define ENGINE_H

#include "peca.hpp"
#include "tabuleiro.hpp"
#include <vector>

typedef struct {
    Peca_t peca;
    std::vector<Posicao_t> * posRemover;
} PecaPorCapturas_t;

class Engine {
    private:
        int _numCapturas; 
        int _numCapturasMax;
        std::vector<Posicao_t> _posRemover;
        std::vector<Posicao_t> _posRemoverMax;
        bool conta_jogadas(Tabuleiro_t tabuleiro, Peca_t peca);
        void roda_engine(Tabuleiro_t tabuleiro, char cor);
        Tabuleiro_t * aloca_tabuleiro_com_captura(Tabuleiro_t tabuleiro, Movimento_t movimento, Peca_t peca);
    public:
        void get_maior(Tabuleiro_t tabuleiro, char cor, Peca_t &pecaPreencher, std::vector<Posicao_t> &posicaoPreencher);
};

#endif