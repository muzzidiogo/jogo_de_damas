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
    bool VerificarPosicao(Posicao_t posicao); //trocar todos os verificarposicao por procura peca
    bool AtualizarTabuleiro(Posicao_t novaPosicao, Peca_t peca);
    std::vector<Peca_t> get_tabuleiro();
    bool procura_peca(long unsigned int linha, long unsigned int coluna, char cor); //trocar variaveis por structs
    void copiaTabuleiroDe(Tabuleiro_t tabuleiroAntigo);
    
    //esta fun��o foi declarada aqui porque, para capturar, informa��es do tabuleiro s�o necess�rias
    void capturaPeca(Peca_t pecaJogada, Posicao_t posicaoRemover, int linhasMover, int colunasMover); //apaga a pe�a 'pecaCapturar', movimenta a peca 'pecaJogada' 
    //trocar linhas e colunasmover por struct
};

#endif //TABULEIRO_H
