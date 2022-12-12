#include "../include/tabuleiro.hpp"
#include <cstddef>

Tabuleiro_t::Tabuleiro_t() {
    for(unsigned int i = 0; i<3; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(false, Cores::PRETO, Posicao_t{i, j}));
            }
        }
    }
    for(unsigned int i = 5; i<8; i++) {
        for(unsigned int j=0; j<8; j++) {
            if((i%2 != 0 && j%2 != 0) || ((i%2 == 0 && j%2 == 0))) {
                _tabuleiro.push_back(Peca_t(false, Cores::BRANCO, Posicao_t{i, j}));
            }
        }
    }
}

void Tabuleiro_t::RemoverPeca(Posicao_t posicao) { //fonte de bug???
    for(auto it = _tabuleiro.begin(); it != _tabuleiro.end(); it++) {
        if((it->get_posicao().coluna == posicao.coluna) &&
           (it->get_posicao().linha == posicao.linha))
        {
            _tabuleiro.erase(it);
        }
    }
}

bool Tabuleiro_t::VerificarPosicao(Posicao_t posicao){
    for(Peca_t peca : _tabuleiro) {
        if((peca.get_posicao().coluna == posicao.coluna) && 
           (peca.get_posicao().linha == posicao.linha)) 
        {
            return true;
        }
    }
    return false;
}

bool Tabuleiro_t::AtualizarTabuleiro(Posicao_t novaPosicao, Peca_t peca){
    if(VerificarPosicao(novaPosicao)){
        RemoverPeca(novaPosicao); //Resolver: remove mesmo se for peça da mesma cor
        Posicao_t posicaoDeCaptura;
        posicaoDeCaptura.coluna = novaPosicao.coluna + 1;
        posicaoDeCaptura.linha = novaPosicao.linha + 1;
        return true; //Resolver: a posição após captura deve ser na mesma direção em que a peça movimentou.
    }
    peca.Andar(novaPosicao);
    return true;
}

std::vector<Peca_t> Tabuleiro_t::get_tabuleiro(){
    return _tabuleiro;
}

bool Tabuleiro_t::procura_peca(int linha, int coluna, char cor) {
    for (Peca_t peca : _tabuleiro) {
        if (peca.get_posicao().linha == linha && 
           peca.get_posicao().coluna == coluna && 
           peca.get_cor() == cor) {
            return true;    
        } 
    }
    return false;
}

void Tabuleiro_t::copiaTabuleiroDe(Tabuleiro_t tabuleiroAntigo) {
    _tabuleiro.clear();

    for (Peca_t peca : tabuleiroAntigo.get_tabuleiro()) {
        _tabuleiro.push_back(peca);
    }
}

void Tabuleiro_t::capturaPeca(Peca_t pecaJogada, Posicao_t posicaoRemover, int linhasMover, int colunasMover) {
    unsigned int linha = pecaJogada.get_posicao().linha;
    unsigned int coluna = pecaJogada.get_posicao().coluna;
    pecaJogada.Andar({linha + linhasMover, coluna + colunasMover});
    this->RemoverPeca(posicaoRemover);
}
