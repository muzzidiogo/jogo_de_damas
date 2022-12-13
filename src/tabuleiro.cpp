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

void Tabuleiro_t::remover_peca(Posicao_t posicao) { //fonte de bug???
    for(auto it = _tabuleiro.begin(); it != _tabuleiro.end(); it++) {
        if((it->get_posicao().coluna == posicao.coluna) &&
           (it->get_posicao().linha == posicao.linha))
        {
            _tabuleiro.erase(it);
        }
    }
}

bool Tabuleiro_t::verificar_posicao(Posicao_t posicao){
    for(Peca_t peca : _tabuleiro) {
        if((peca.get_posicao().coluna == posicao.coluna) && 
           (peca.get_posicao().linha == posicao.linha)) 
        {
            return true;
        }
    }
    return false;
}

bool Tabuleiro_t::atualizar_tabuleiro(Posicao_t novaPosicao, Peca_t peca){
    if(procura_peca(novaPosicao, peca.get_cor())){
        captura_peca(peca, novaPosicao, novaPosicao.linha, novaPosicao.coluna);
    }
    peca.andar(novaPosicao);
    return true;
}

std::vector<Peca_t> Tabuleiro_t::get_tabuleiro(){
    return _tabuleiro;
}

bool Tabuleiro_t::procura_peca(Posicao_t posicao, char cor) {
    for (Peca_t peca : _tabuleiro) {
        if (peca.get_posicao().linha == posicao.linha && 
           peca.get_posicao().coluna == posicao.coluna && 
           peca.get_cor() == cor) {
            return true;    
        } 
    }
    return false;
}

void Tabuleiro_t::copia_tabuleiro(Tabuleiro_t tabuleiroAntigo) {
    _tabuleiro.clear();

    for (Peca_t peca : tabuleiroAntigo.get_tabuleiro()) {
        _tabuleiro.push_back(peca);
    }
}

void Tabuleiro_t::captura_peca(Peca_t pecaJogada, Posicao_t posicaoRemover, int linhasMover, int colunasMover) {
    unsigned int linha = pecaJogada.get_posicao().linha;
    unsigned int coluna = pecaJogada.get_posicao().coluna;
    
    Peca_t *pecaAndar;
    for (Peca_t peca : _tabuleiro) {
        if (peca.get_posicao().linha == pecaJogada.get_posicao().linha &&
            peca.get_posicao().coluna == pecaJogada.get_posicao().coluna) pecaAndar = &peca;
    }
    pecaAndar->andar({linha + linhasMover, coluna + colunasMover});
    this->remover_peca(posicaoRemover);
}
