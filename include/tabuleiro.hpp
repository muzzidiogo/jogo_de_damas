#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "peca.hpp"

class Tabuleiro_t {
private:
    const static unsigned int TAMANHO;
    std::vector<Peca_t> _tabuleiro;
public:
    Tabuleiro_t();
    void RemoverPeca(Posicao_t posicao);
    bool VerificarPosicao(Posicao_t posicao); 
    bool AtualizarTabuleiro(Posicao_t novaPosicao, Peca_t peca);
    std::vector<Peca_t> get_tabuleiro();
    bool procura_peca(Posicao_t posicao, char cor); 
    void copia_tabuleiro(Tabuleiro_t tabuleiroAntigo);
    void captura_peca(Peca_t pecaJogada, Posicao_t posicaoRemover, int linhasMover, int colunasMover); 
    
};

#endif //TABULEIRO_H
