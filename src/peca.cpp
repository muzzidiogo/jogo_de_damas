#include "../include/peca.hpp"

Peca_t::Peca_t(int cor, Posicao_t posicao)
:_cor(cor), _posicao(posicao){}

void Peca_t::andar(Posicao_t novaPosicao){
    _posicao = novaPosicao;
}

Posicao_t Peca_t::get_posicao() {
    return _posicao;
}

int Peca_t::get_cor() {
    return _cor;
}
