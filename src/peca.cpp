#include "../include/peca.hpp"

Peca_t::Peca_t(bool dama, int cor, Posicao_t posicao){
    _dama = dama;
    _cor = cor;
    _posicao = posicao;
}

void Peca_t::Andar(Posicao_t novaPosicao){
    _posicao = novaPosicao;
}

Posicao_t Peca_t::get_posicao() {
    return _posicao;
}

int Peca_t::get_cor() {
    return _cor;
}
void Peca_t::set_quantidadeJogadas(int quantidade) {
    quantidadeJogadas = quantidade;
}

int Peca_t::get_quantidadeJogadas() {
    return quantidadeJogadas;
}
