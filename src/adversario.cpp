#include "../include/adversario.hpp"
#include <iostream>

Adversario_t::Adversario_t(Tabuleiro_t *tabuleiro, Engine *engine) {
    _tabuleiro = tabuleiro;
    _engine = engine;
}

void Adversario_t::jogar() {
    Peca_t pecaMover;
    std::vector<Posicao_t> pecasCapturar;
    _engine->get_maior(*_tabuleiro, Cores::PRETO, pecaMover, pecasCapturar);
    if(pecasCapturar.size() != 0) {
        for(Posicao_t posicao : pecasCapturar) {
            int linha = posicao.linha - pecaMover.get_posicao().linha;
            int coluna = posicao.coluna - pecaMover.get_posicao().coluna;
            Movimento_t movimento = {linha, coluna};
            _tabuleiro->captura_peca(pecaMover, movimento);
            pecaMover.andar({pecaMover.get_posicao().linha+(2*movimento.linha),
                             pecaMover.get_posicao().coluna+(2*movimento.coluna)});
        }
    }
    else {
        for(unsigned long int i=0; i<_tabuleiro->get_tabuleiro().size();i++){
            if(_tabuleiro->get_tabuleiro()[i].get_cor() == Cores::PRETO){
                Peca_t peca = _tabuleiro->get_tabuleiro()[i];
                Posicao_t novaPosDir{(peca.get_posicao().linha)+1, (peca.get_posicao().coluna)+1};
                Posicao_t novaPosEsq{(peca.get_posicao().linha)+1, (peca.get_posicao().coluna)-1};
                if(!_tabuleiro->verificar_posicao(novaPosDir)&&
                   !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosDir)) {
                    _tabuleiro->get_ptr_tabuleiro()->at(i).andar(novaPosDir);
                    return;
                }
                else if(!_tabuleiro->verificar_posicao(novaPosEsq)&&
                !_tabuleiro->verificar_pos_saiu_tabuleiro(novaPosEsq)){
                    _tabuleiro->get_ptr_tabuleiro()->at(i).andar(novaPosEsq);
                    return;
                }
            }
        }
    }
}