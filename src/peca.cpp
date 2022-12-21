#include "../include/peca.hpp"

Peca_t::Peca_t() {
}

Peca_t::Peca_t(int cor, Posicao_t posicao)
:_cor(cor), _posicao(posicao){}

void Peca_t::andar(Posicao_t novaPosicao){
    _posicao.coluna = novaPosicao.coluna;
    _posicao.linha = novaPosicao.linha;
}

Posicao_t Peca_t::get_posicao() {
    return _posicao;
}

int Peca_t::get_cor() {
    return _cor;
}

bool Peca_t::operator ==(Peca_t peca) const {
    if((_posicao.coluna == peca.get_posicao().coluna) &&
       (_posicao.linha == peca.get_posicao().linha) &&
       (_cor == peca.get_cor())){
        return true;
    }
    return false;
}

bool Peca_t::operator !=(Peca_t peca) const {
    if((_posicao.coluna != peca.get_posicao().coluna) ||
       (_posicao.linha != peca.get_posicao().linha) ||
       (_cor != peca.get_cor())){
        return true;
    }
    return false;
}