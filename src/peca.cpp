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

void Peca_t::set_quantidadeJogadas(int quantidade) {
    _quantidadeJogadas = quantidade;
}

int Peca_t::get_quantidadeJogadas() {
    return _quantidadeJogadas;
}

std::vector<Peca_t> Peca_t::get_pecasRemover() {
    return _pecasRemover;
}

void Peca_t::set_pecasRemover(std::vector<Peca_t> pecasRemover) {
    _pecasRemover.clear();
    for (Peca_t peca : pecasRemover) { //implementado dessa forma por causa de possíveis problemas de escopo, testar
        _pecasRemover.push_back(peca); 
    }
}
