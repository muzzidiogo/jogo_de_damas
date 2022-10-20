#include "../include/peca.hpp"

Peca_t::Peca_t(bool dama, int cor, Posicao_t posicao){
    _dama = dama;
    _cor = cor;
    _posicao = posicao;
}

void Peca_t::Capturar_Peca(Posicao_t posicao, Peca_t pecaCapturada) {

}

Posicao_t Peca_t::get_posicao() {
    return _posicao;
}

int Peca_t::get_cor() {
    return _cor;
}
