#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "peca.hpp"

typedef struct {
    int linha;
    int coluna;
} Movimento_t;

class Tabuleiro_t {
private:
    const static unsigned int TAMANHO;
    std::vector<Peca_t> _tabuleiro;
public:
    Tabuleiro_t();
    void remover_peca(Posicao_t posicao);
    bool verificar_posicao(Posicao_t posicao); 
    bool atualizar_tabuleiro(Posicao_t novaPosicao, Peca_t peca);
    std::vector<Peca_t> get_tabuleiro();
    bool procura_peca(Posicao_t posicao, char cor); 
    void copia_tabuleiro(Tabuleiro_t tabuleiroAntigo);
    void captura_peca(Peca_t pecaJogada, Posicao_t posicaoRemover, Movimento_t movimento);   
};

#endif //TABULEIRO_H
