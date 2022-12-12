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
    bool procura_peca(int linha, int coluna, char cor);
    void copiaTabuleiroDe(Tabuleiro_t tabuleiroAntigo);
    
    //esta função foi declarada aqui porque, para capturar, informações do tabuleiro são necessárias
    void capturaPeca(Peca_t pecaJogada, Posicao_t posicaoRemover, int linhasMover, int colunasMover); //apaga a peça 'pecaCapturar', movimenta a peca 'pecaJogada' 
    
    Peca_t retornaMaior();
};

#endif //TABULEIRO_H
