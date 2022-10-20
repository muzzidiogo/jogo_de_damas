#include "../include/tabuleiro.hpp"

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

void Tabuleiro_t::RemoverPeca(Peca_t peca) {
    for(auto it = _tabuleiro.begin(); it != _tabuleiro.end(); it++) {
        if((it->get_posicao().coluna == peca.get_posicao().coluna) &&
           (it->get_posicao().linha == peca.get_posicao().linha))
        {
            _tabuleiro.erase(it);
            return;
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
    return true;
}

std::vector<Peca_t> Tabuleiro_t::get_tabuleiro(){
    return _tabuleiro;
}
